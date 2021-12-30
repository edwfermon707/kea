// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// $Id: COPYRIGHT,v 1.1.1.1 2013/08/15 18:46:09 labovit Exp $
//
// Copyright (c) 1999-2013
//
// The Regents of the University of Michigan ("The Regents") and Merit
// Network, Inc.
//
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef PATRICIA_TREE_H
#define PATRICIA_TREE_H

#include <exceptions/exceptions.h>
#include <boost/shared_ptr.hpp>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

namespace isc {
namespace util {

/// @file Patricia tree implementation based on ISC AFTR C code.

/// @brief The Patricia tree node.
///
/// @tparam ContentType Type of the content e.g. a subnet list.
template <typename ContentType>
struct Node {
    /// @brief Pointer to the @ref Node object.
    typedef boost::shared_ptr<Node> NodePtr;

    /// @brief Pointer to parent node.
    NodePtr parent_;

    /// @brief Pointer to left node.
    NodePtr left_;

    /// @brief Pointer to right node.
    NodePtr right_;

    /// @brief Content.
    std::list<ContentType> contents_;

    /// @brief Internal node branch bit.
    uint8_t bit_;

    /// @brief Prefix address (either empty or size addr_size).
    std::vector<uint8_t> addr_;

    /// @brief Prefix length.
    uint8_t len_;
};

/// Patricia (Practical Algorithm to Retrieve Information Coded
/// in Alphanumeric) is a standard radix tree.
///
/// @tparam ContentType Type of the content e.g. a subnet list.
template <typename Node>
class PatriciaTree {
public:

    /// @brief Pointer to the @ref Node object.
    typedef typename Node::NodePtr NodePtr;

    /// @brief Constructor.
    ///
    /// @param addr_size Size of addresses in octets i.e. 4 or 16.
    /// @throw OutOfRange on addr_size greater than 32.
    PatriciaTree(uint8_t addr_size)
        : addr_size_(addr_size), max_bit_count_(addr_size * 8),
          nodes_(0), root_() {
#ifdef ENABLE_DEBUG
        if ((addr_size != 4) && (addr_size != 16)) {
            std::cerr << "only address sizes 4 and 16 make sense" << std::endl;
        }
#endif
        if (addr_size >= 32) {
            isc_throw(OutOfRange, "too large address size");
        }
    }

    /// @brief Destructor.
    virtual ~PatriciaTree() {
        clear();
    }

    /// @brief Get the address size.
    ///
    /// @return The address size.
    uint8_t getAddrSize() const {
        return (addr_size_);
    }

    /// @brief Get the active node number.
    ///
    /// @return The number of active nodes.
    int getNodeCount() const {
        return (nodes_);
    }

    /// @brief Compare two addresses with a mask length.
    ///
    /// @param addr1 First addr to compare.
    /// @param addr2 Second addr to compare.
    /// @param len Mask length.
    /// @return When equal up to the length true else false.
    inline bool compare(const std::vector<uint8_t>& addr1,
                       const std::vector<uint8_t>& addr2,
                       uint8_t len) const {
        if (len > max_bit_count_) {
#ifdef ENABLE_DEBUG
            std::cerr << "compare overflow" << std::endl;
#endif
            len = max_bit_count_;
        }
        uint8_t n = len / 8;
        if (memcmp(&addr1[0], &addr2[0], n) == 0) {
            uint8_t r = len % 8;
            uint8_t m = (0xff << (8 - r));
            if ((r == 0) || ((addr1[n] & m) == (addr2[n] & m))) {
                return (true);
            }
        }
        return (false);
    }

    /// @brief Clear the tree.
    void clear() {
        if (root_) {
            std::stack<NodePtr> stack;
            NodePtr node = root_;
            while (node) {
                NodePtr left = node->left_;
                NodePtr right = node->right_;
                node->addr_.clear();
                node->contents_.clear();
                node->parent_.reset();
                node->left_.reset();
                node->right_.reset();
                node.reset();
                --nodes_;
                if (left) {
                    if (right) {
                        stack.push(right);
                    }
                    node = left;
                } else if (right) {
                    node = right;
                } else if (!stack.empty()) {
                    node = stack.top();
                    stack.pop();
                } else {
                    break;
                }
            }
            root_.reset();
        }
#ifdef ENABLE_DEBUG
        if (nodes_ != 0) {
            std::cerr << "~PatriciaTree leaks " << nodes_ << std::endl;
        }
#endif
    }

    /// @brief Walk the tree.
    ///
    /// @param fun A function to apply to each node.
    /// @param all_nodes when false skip nodes with a prefix.
    /// @throw BadValue if fun is empty.
    void walk(std::function<void(const NodePtr&)> fun,
              bool all_nodes = false) {
        if (!fun) {
            isc_throw(BadValue, "empty function (walk)");
        }
        std::stack<NodePtr> stack;
        NodePtr node = root_;
        while (node) {
            if (all_nodes || !node->addr_.empty()) {
                fun(node);
            }
            if (node->left_) {
                if (node->right_) {
                    stack.push(node->right_);
                }
                node = node->left_;
            } else if (node->right_) {
                node = node->right_;
            } else if (!stack.empty()) {
                node = stack.top();
                stack.pop();
            } else {
                node.reset();
            }
        }
    }

    /// @brief Walk a subtree in order.
    ///
    /// When the given top node is null walk the whole tree.

    /// @param node The node at the top of the subtree.
    /// @param fun A function to apply to each node.
    /// @param all_nodes when false skip nodes with a prefix.
    /// @return The number of visited node.
    /// @throw BadValue if fun is empty.
    size_t walkInOrder(const NodePtr& node,
                       std::function<void(const NodePtr&)> fun,
                       bool all_nodes = false) {
        if (!node) {
            return (walkInOrder(root_, fun, all_nodes));
        }
        if (!fun) {
            isc_throw(BadValue, "empty function (walkInOrder)");
        }

        size_t cnt = 0;
        if (node->left_) {
            cnt += walkInOrder(node->left_, fun, all_nodes);
        }
        if (all_nodes || !node->addr_.empty()) {
            fun(node);
            ++cnt;
        }
        if (node->right_) {
            cnt += walkInOrder(node->right_, fun, all_nodes);
        }
        return (cnt);
    }

    /// @brief Search the node for an exact prefix.
    ///
    /// @param addr The address part of the prefix.
    /// @param len The length of the prefix.
    /// @return The node for the exact prefix or null if not found.
    /// @throw BadValue if the address size is not correct.
    /// @throw OutOfRange when the length is greater than max_bit_count_.
    NodePtr findExact(const std::vector<uint8_t>& addr, uint8_t len) const {
        if (addr.size() != addr_size_) {
            isc_throw(BadValue, "bad address size (findExact)");
        }
        if (len > max_bit_count_) {
            isc_throw(OutOfRange, "wrong prefix length (findExact)");
        }
        if (!root_) {
            return (NodePtr());
        }
        NodePtr node = root_;
        while (node->bit_ < len) {
            if ((addr[node->bit_ >> 3] & (0x80 >> (node->bit_ & 7)))) {
                // take right.
                node = node->right_;
            } else {
                // take left.
                node = node->left_;
            }
            if (!node) {
                return (NodePtr());
            }
        }
        // stop.
        if ((node->bit_ > len) || node->addr_.empty()) {
            return (NodePtr());
        }
#ifdef ENABLE_DEBUG
        if ((node->bit_ != len) || (node->bit_ != node->len_)) {
            std::cerr << "findExact failure" << std::endl;
        }
#endif
        if (compare(node->addr_, addr, len)) {
            // found.
            return (node);
        }
        return (NodePtr());
    }

    /// @brief Find the best node for the prefix.
    ///
    /// @param addr The address part of the prefix.
    /// @param len The length of the prefix.
    /// @return The node for the prefix or null if not found.
    /// @throw BadValue if the address size is not correct.
    /// @throw OutOfRange when the length is greater than max_bit_count_.
    NodePtr find(const std::vector<uint8_t>& addr, uint8_t len) const {
        if (addr.size() != addr_size_) {
            isc_throw(BadValue, "bad address size (find)");
        }
        if (len > max_bit_count_) {
            isc_throw(OutOfRange, "wrong prefix length (find)");
        }
        if (!root_) {
            return (NodePtr());
        }
        NodePtr node = root_;
        std::stack<NodePtr> stack;
        while (node->bit_ < len) {
            if (!node->addr_.empty()) {
                // push.
                stack.push(node);
            }
            if ((addr[node->bit_ >> 3] & (0x80 >> (node->bit_ & 7)))) {
                // take right.
                node = node->right_;
            } else {
                // take left.
                node = node->left_;
            }
            if (!node) {
                break;
            }
        }

        // Found an exact match.
        if (node && !node->addr_.empty()) {
            stack.push(node);
        }

        // stop.
        if (stack.empty()) {
            return (NodePtr());
        }
        while (!stack.empty()) {
            // pop.
            node = stack.top();
            stack.pop();
            if (compare(node->addr_, addr, node->len_) &&
                (node->len_ <= len)) {
                // found.
                return (node);
            }
        }
        return (NodePtr());
    }

    /// @brief Apply a function on all matching prefixes.
    ///
    /// @param addr The address.
    /// @param fun A function to apply to each matching node with a prefix.
    /// @throw BadValue if fun is empty or if the address size is not correct.
    void path(const std::vector<uint8_t>& addr,
              std::function<void(const NodePtr&)> fun) const {
        if (!root_) {
            return;
        }
        if (!fun) {
            isc_throw(BadValue, "empty function (path)");
        }
        if (addr.size() != addr_size_) {
            isc_throw(BadValue, "bad address size (path)");
        }
        NodePtr node = root_;
        while (node->bit_ < max_bit_count_) {
            if (!node->addr_.empty() &&
                compare(node->addr_, addr, node->len_)) {
                // found.
                fun(node);
            }
            if ((addr[node->bit_ >> 3] & (0x80 >> (node->bit_ & 7)))) {
                // take right.
                node = node->right_;
            } else {
                // take left.
                node = node->left_;
            }
            if (!node) {
                break;
            }
        }
        // stop.
        if (node && !node->addr_.empty() &&
            compare(node->addr_, addr, node->len_) &&
            (node->len_ <= max_bit_count_)) {
            // found best.
            fun(node);
        }
    }

    /// @brief Insert the node for the prefix.
    ///
    /// @param addr The address part of the prefix.
    /// @param len The length of the prefix.
    /// @return The inserted node for the prefix.
    /// @throw BadValue if the address size is not correct.
    /// @throw OutOfRange when the length is greater than max_bit_count_.
    NodePtr insert(const std::vector<uint8_t>& addr, uint8_t len) {
        if (addr.size() != addr_size_) {
            isc_throw(BadValue, "bad address size (find)");
        }
        if (len > max_bit_count_) {
            isc_throw(OutOfRange, "wrong prefix length (insert)");
        }
        if (!root_) {
            NodePtr node(new Node());
            node->bit_ = len;
            node->addr_ = addr;
            node->len_ = len;
            root_ = node;
            // new node #0 (head).
            ++nodes_;
            return (node);
        }

        NodePtr node = root_;
        while ((node->bit_ < len) || node->addr_.empty()) {
            if ((node->bit_ < max_bit_count_) &&
                (addr[node->bit_ >> 3] & (0x80 >> (node->bit_ & 7)))) {
                if (!node->right_) {
                    break;
                }
                // take rigth.
                node = node->right_;
            } else {
                if (!node->left_) {
                    break;
                }
                // take left.
                node = node->left_;
            }

#ifdef ENABLE_DEBUG
            if (!node) {
                std::cerr << "insert failure 1" << std::endl;
            }
#endif
        }

        // stop.
#ifdef ENABLE_DEBUG
        if (node->addr_.empty()) {
            std::cerr << "insert failure 2" << std::endl;
        }
#endif

        // find the first bit different.
        uint8_t check = (node->bit_ < len ? node->bit_ : len);
        uint8_t differ = 0;
        for (uint8_t i = 0; i * 8 < check; ++i) {
            uint8_t r = (addr[i] ^ node->addr_[i]);
            if (r == 0) {
                differ = (i + 1) * 8;
                continue;
            }
            // I know the better way, but for now.
            uint8_t j = 0;
            for (; j < 8; ++j) {
                if (r & (0x80 >> j)) {
                    break;
                }
            }
            // must be found.
#ifdef ENABLE_DEBUG
            if (j >= 8) {
                std::cerr << "insert failure 3" << std::endl;
            }
#endif
            differ = i * 8 + j;
            break;
        }
        // got differ bit.
        if (differ > check) {
            differ = check;
        }

        NodePtr parent = node->parent_;
        while (parent && (parent->bit_ >= differ)) {
            node = parent;
            parent = node->parent_;
            // up to node bit.
        }

        if ((differ == len) && (node->bit_ == len)) {
            if (!node->addr_.empty()) {
                // found.
                return (node);
            }
            node->addr_ = addr;
            node->len_ = len;
#ifdef ENABLE_DEBUG
            if (!node->contents_.empty()) {
                std::cerr << "insert failure 4" << std::endl;
            }
#endif
            // new node #1 (glue mod).
            return (node);
        }

        NodePtr new_node(new Node());
        new_node->bit_ = len;
        new_node->addr_ = addr;
        new_node->len_ = len;
        ++nodes_;

        if (node->bit_ == differ) {
            new_node->parent_ = node;
            if ((node->bit_ < max_bit_count_) &&
                (addr[node->bit_ >> 3] & (0x80 >> (node->bit_ & 7)))) {
#ifdef ENABLE_DEBUG
                if (node->right_) {
                    std::cerr << "insert failure 5" << std::endl;
                }
#endif
                node->right_ = new_node;
            } else {
#ifdef ENABLE_DEBUG
                if (node->left_) {
                    std::cerr << "insert failure 6" << std::endl;
                }
#endif
                node->left_ = new_node;
            }
            // new node #2 (child).
            return (new_node);
        }

        if (len == differ) {
            if ((node->bit_ < max_bit_count_) &&
                (addr[node->bit_ >> 3] & (0x80 >> (node->bit_ & 7)))) {
                new_node->right_ = node;
            } else {
                new_node->left_ = node;
            }
            new_node->parent_ = node->parent_;
            if (!node->parent_) {
#ifdef ENABLE_DEBUG
                if (root_ != node) {
                    std::cerr << "insert failure 7" << std::endl;
                }
#endif
                root_ = new_node;
            } else if (node->parent_->right_ == node) {
                node->parent_->right_ = new_node;
            } else {
                node->parent_->left_ = new_node;
            }
            // new node #3 (parent).
            node->parent_ = new_node;
        } else {
            NodePtr glue(new Node());
            glue->bit_ = differ;
            glue->parent_ = node->parent_;
            ++nodes_;
            if ((differ < max_bit_count_) &&
                (addr[differ >> 3] & (0x80 >> (differ & 7)))) {
                glue->right_ = new_node;
                glue->left_ = node;
            } else {
                glue->right_ = node;
                glue->left_ = new_node;
            }
            new_node->parent_ = glue;

            if (!node->parent_) {
#ifdef ENABLE_DEBUG
                if (root_ != node) {
                    std::cerr << "insert failure 8" << std::endl;
                }
#endif
                root_ = glue;
            } else if (node->parent_->right_ == node) {
                node->parent_->right_ = glue;
            } else {
                node->parent_->left_ = glue;
            }
            node->parent_ = glue;
        }
        // new node #4 (glue and node).
        return (new_node);
    }

    /// @brief Remove a node.
    ///
    /// @param node The node to remove.
    /// @throw BadValue if the node is null.
    void remove(NodePtr& node) {
        if (!node) {
            isc_throw(BadValue, "null node (remove)");
        }

        // remove #0 (right and left).
        if (node->right_ && node->left_) {

            // this might be a glue node.
            if (!node->addr_.empty()) {
                node->addr_.clear();
            }
            node->contents_.clear();
            return;
        }

        NodePtr parent;
        NodePtr child;
        // remove #1 (!right and !left).
        if (!node->right_ && !node->left_) {
            parent = node->parent_;
            node->addr_.clear();
            node->contents_.clear();
            node->parent_.reset();
            --nodes_;

            if (!parent) {
#ifdef ENABLE_DEBUG
                if (root_ != node) {
                    std::cerr << "remove failure 1" << std::endl;
                }
#endif
                root_.reset();
                return;
            }

            if (parent->right_ == node) {
                parent->right_.reset();
                child = parent->left_;
            } else {
#ifdef ENABLE_DEBUG
                if (parent->left_ != node) {
                    std::cerr << "remove failure 2" << std::endl;
                }
#endif
                parent->left_.reset();
                child = parent->right_;
            }

            if (!parent->addr_.empty()) {
                return;
            }

            // we need to remove parent too.
            if (!parent->parent_) {
#ifdef ENABLE_DEBUG
                if (root_ != parent) {
                    std::cerr << "remove failure 3" << std::endl;
                }
#endif
                root_ = child;
            } else if (parent->parent_->right_ == parent) {
                parent->parent_->right_ = child;
            } else {
#ifdef ENABLE_DEBUG
                if (parent->parent_->left_ != parent) {
                    std::cerr << "remove failure 4" << std::endl;
                }
#endif
                parent->parent_->left_ = child;
            }
            child->parent_ = parent->parent_;
#ifdef ENABLE_DEBUG
            if (!parent->contents_.empty()) {
                std::cerr << "remove failure 5" << std::endl;
            }
#endif
            parent->contents_.clear();
            parent->parent_.reset();
            parent->left_.reset();
            parent->right_.reset();
            parent.reset();
            --nodes_;
            return;
        }

        // remove #2 (either right or left).
        if (node->right_) {
            child = node->right_;
        } else {
#ifdef ENABLE_DEBUG
            if (!node->left_) {
                std::cerr << "remove failure 5" << std::endl;
            }
#endif
            child = node->left_;
        }
        parent = node->parent_;
        child->parent_ = parent;

        node->addr_.clear();
        node->contents_.clear();
        node->parent_.reset();
        node->left_.reset();
        node->right_.reset();
        --nodes_;

        if (!parent) {
#ifdef ENABLE_DEBUG
            if (root_ != node) {
                std::cerr << "remove failure 6" << std::endl;
            }
#endif
            root_ = child;
            return;
        }

        if (parent->right_ == node) {
            parent->right_ = child;
        } else {
#ifdef ENABLE_DEBUG
            if (parent->left_ != node) {
                std::cerr << "remove failure 7" << std::endl;
            }
#endif
            parent->left_ = child;
        }
    }

protected:
    /// @brief Address size.
    const uint8_t addr_size_;

    /// @brief Max bit count.
    const uint8_t max_bit_count_;

    /// @brief Instance counter.
    int nodes_;

    /// @brief Root node.
    NodePtr root_;
};

} // end of namespace isc::util
} // end of namespace isc

#endif // PATRICIA_TREE_H
