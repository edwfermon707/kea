// Copyright (C) 2018-2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <yang/translator.h>
#include <util/encode/base64.h>

#include <sysrepo-cpp/utils/exception.hpp>

#include <cstring>

using namespace std;
using namespace isc::data;
using namespace isc::util::encode;
using namespace libyang;
using namespace sysrepo;

namespace {

string encode64(const string& input) {
    vector<uint8_t> binary;
    binary.resize(input.size());
    memmove(&binary[0], input.c_str(), binary.size());
    return (encodeBase64(binary));
}

string decode64(const string& input) {
    vector<uint8_t> binary;
    decodeBase64(input, binary);
    string result;
    result.resize(binary.size());
    memmove(&result[0], &binary[0], result.size());
    return (result);
}

} // end of anonymous namespace

namespace isc {
namespace yang {

TranslatorBasic::TranslatorBasic(Session session, const string& model)
    : session_(session), model_(model) {
}

TranslatorBasic::~TranslatorBasic() {
}

void
TranslatorBasic::checkAndGetLeaf(ElementPtr& storage,
                                 DataNode const& data_node,
                                 string const& name) {
    ConstElementPtr x = getItem(data_node, name);
    if (x) {
        storage->set(name, x);
    }
}

void TranslatorBasic::checkAndSetLeaf(ConstElementPtr const& from,
                                      string const& xpath,
                                      string const& name,
                                      LeafBaseType const type) {
    ConstElementPtr const& x(from->get(name));
    if (x) {
        setItem(xpath + "/" + name, x, type);
    }
}

void
TranslatorBasic::delItem(const std::string& xpath) {
    /// @todo: Remove this if convenient. It is not strictly required and only done to detect
    /// missing schema nodes and throw an exception to keep old behavior.
    try {
        Context const& context(session_.getContext());
        context.findPath(xpath);
    } catch (libyang::Error const& ex) {
        isc_throw(SysrepoError, "sysrepo error getting item at '" << xpath
                  << "': " << ex.what());
    }

    try {
        if (session_.getData(xpath)) {
            session_.deleteItem(xpath);
        }
    } catch (sysrepo::Error const& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error deleting item at '"
                  << xpath << "': " << ex.what());
    }
    session_.applyChanges();
}

DataNode
TranslatorBasic::findXPath(string const& xpath) {
    optional<DataNode> const& data_node(getNode(xpath));
    if (!data_node) {
        isc_throw(SysrepoError, "no data");
    }
    Set<DataNode> at_path(data_node->findXPath(xpath));
    if (at_path.empty()) {
        isc_throw(SysrepoError, "no data");
    }
    return at_path.front();
}

ElementPtr
TranslatorBasic::getItem(DataNode const& data_node, string const& xpath) const {
    try {
        Set<DataNode> const& nodes(data_node.findXPath(xpath));
        if (nodes.empty()) {
            return ElementPtr();
        }
        DataNode const& front(nodes.front());
        NodeType const node_type(front.schema().nodeType());

        // Leaf-list
        if (node_type == NodeType::Leaflist) {
            ElementPtr result(Element::createList());
            for (DataNode const& i : nodes) {
                result->add(value(i));
            }
            return result;
        } else if (node_type == NodeType::Container) {
            /// @todo:
            /// isc_throw(SysrepoError, "getting containers not supported, xpath is '" << xpath << "'");
            return ElementPtr();
        } else if (node_type == NodeType::List) {
            /// @todo:
            /// isc_throw(SysrepoError, "getting lists not supported, xpath is '" << xpath << "'");
            return ElementPtr();
        }

        // Leaf
        return value(front);
    } catch (sysrepo::Error const& ex) {
        isc_throw(SysrepoError, "sysrepo error getting item at '" << xpath
                  << "': " << ex.what());
    }
}

ElementPtr
TranslatorBasic::getItem(string const& xpath) const {
    optional<DataNode> const& data_node(getNode(xpath));
    if (!data_node) {
        /// @todo:
        /// isc_throw(SysrepoError, "no data ");
        return ElementPtr();
    }
    return getItem(*data_node, xpath);
}

optional<DataNode>
TranslatorBasic::getNode(string const& xpath) const {
    /// @todo: Remove this if convenient. It is not strictly required and only done to detect
    /// missing schema nodes and throw an exception to keep old behavior.
    try {
        Context const& context(session_.getContext());
        context.findPath(xpath);
    } catch (libyang::Error const& ex) {
        isc_throw(SysrepoError, "sysrepo error getting item at '" << xpath
                  << "': " << ex.what());
    }

    optional<DataNode> data_node;
    try {
        data_node = session_.getData(xpath);
    } catch (sysrepo::Error const& ex) {
        isc_throw(SysrepoError, "sysrepo error getting item at '" << xpath
                  << "': " << ex.what());
    }

    return data_node;
}

ElementPtr
TranslatorBasic::leaf(optional<DataNode> const& data_node) {
    DataNodeTerm const& leaf(data_node->asTerm());
    Value const& value(leaf.value());
    if (holds_alternative<string>(value) ||
        holds_alternative<Enum>(value)) {
        // Should be a string. Call create(). Should be slightly faster
        // than wrapping value in double quotes and calling fromJSON().
        return Element::create(string(leaf.valueStr()));
    } else {
        // This can be various types so defer to fromJSON().
        return Element::fromJSON(string(leaf.valueStr()));
    }
}

void
TranslatorBasic::set(string const& xpath, ElementPtr const& element) {
    Context const& context(session_.getContext());
    SchemaNode const& schema(context.findPath(xpath));
    NodeType const node_type(schema.nodeType());

    if (node_type == NodeType::Container) {
        for (auto kv : element->mapValue()) {
            stringstream child_xpath;
            child_xpath << xpath << "/" << kv.first;
            set(child_xpath.str(), copy(kv.second, 0));
        }
    } else if (node_type == NodeType::List) {
        List const& list(schema.asList());
        std::vector<Leaf> const& list_keys(list.keys());
        for (ElementPtr i : element->listValue()) {
            stringstream child_xpath;
            child_xpath << xpath;
            for (Leaf const& l : list_keys) {
                string const leaf_name(l.name());
                ElementPtr child_element(i->getNonConst(leaf_name));
                if (!child_element) {
                    isc_throw(SysrepoError, "element at xpath " << xpath << " is missing key '"
                                                                << leaf_name << "': " << i->str());
                }
                if (child_element->getType() == Element::string) {
                    child_xpath << "[" << leaf_name << "="
                                << "'" << child_element->stringValue() << "']";
                } else {
                    child_xpath << "[" << leaf_name << "="
                                << "'" << child_element->str() << "']";
                }
            }
            for (auto kv : i->mapValue()) {
                bool found(false);
                for (Leaf const& l : list_keys) {
                    string const leaf_name(l.name());
                    if (kv.first == leaf_name) {
                        found = true;
                    }
                }
                if (found) {
                    continue;
                }

                stringstream map_xpath;
                map_xpath << child_xpath.str() << "/" << kv.first;
                map_xpath << child_xpath.str() << "/" << kv.first;
                set(map_xpath.str(), copy(kv.second, 0));
            }
        }
    } else if (node_type == NodeType::Leaf) {
        setItem(xpath, element);
    } else if (node_type == NodeType::Leaflist) {
        for (ElementPtr i : element->listValue()) {
            stringstream child_xpath;
            child_xpath << xpath << "[.='" << i->str() << "']";
            setItem(xpath, i);
        }
    } else if (node_type == NodeType::Unknown) {
        isc_throw(SysrepoError, "Unhandled node type: Unknown");
    } else if (node_type == NodeType::Choice) {
        isc_throw(SysrepoError, "Unhandled node type: Choice");
    } else if (node_type == NodeType::AnyXML) {
        isc_throw(SysrepoError, "Unhandled node type: AnyXML");
    } else if (node_type == NodeType::AnyData) {
        isc_throw(SysrepoError, "Unhandled node type: AnyData");
    } else if (node_type == NodeType::Case) {
        isc_throw(SysrepoError, "Unhandled node type: Case");
    } else if (node_type == NodeType::RPC) {
        isc_throw(SysrepoError, "Unhandled node type: RPC");
    } else if (node_type == NodeType::Action) {
        isc_throw(SysrepoError, "Unhandled node type: Action");
    } else if (node_type == NodeType::Notification) {
        isc_throw(SysrepoError, "Unhandled node type: Notification");
    } else if (node_type == NodeType::Uses) {
        isc_throw(SysrepoError, "Unhandled node type: Uses");
    } else if (node_type == NodeType::Input) {
        isc_throw(SysrepoError, "Unhandled node type: Input");
    } else if (node_type == NodeType::Output) {
        isc_throw(SysrepoError, "Unhandled node type: Output");
    } else if (node_type == NodeType::Grouping) {
        isc_throw(SysrepoError, "Unhandled node type: Grouping");
    } else if (node_type == NodeType::Augment) {
        isc_throw(SysrepoError, "Unhandled node type: Augment");
    } else {
        isc_throw(SysrepoError, "Unhandled node type: " << node_type);
    }
}

void
TranslatorBasic::setItem(const string& xpath, ConstElementPtr elem) {
    try {
        Context const& context(session_.getContext());
        SchemaNode const& schema(context.findPath(xpath));
        NodeType const node_type(schema.nodeType());
        LeafBaseType base_type;
        if (node_type == NodeType::Leaf) {
            base_type = schema.asLeaf().valueType().base();
        } else if (node_type == NodeType::Leaflist) {
            base_type = schema.asLeafList().valueType().base();
        } else {
            isc_throw(SysrepoError, "TranslatorBasic::setItem(): unsupported node type: " << node_type);
        }
        string value;
        if (base_type == LeafBaseType::Enum ||
            base_type == LeafBaseType::String ||
            base_type == LeafBaseType::Union) {
            // Enums are strings in ElementPtr, but are accepted
            // without the double quotes in sysrepo.
            if (elem->getType() == Element::map) {
                // Except for some nodes which are maps e.g. user-context.
                value = elem->str();
            } else {
                value = elem->stringValue();
            }
        } else {
            // The rest of YANG values can be expressed using the
            // general string representation of ElementPtr.
            value = elem->str();
        }

        session_.setItem(xpath, value);
        session_.applyChanges();
    } catch (sysrepo::Error const& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error setting item '" << elem->str()
                  << "' at '" << xpath << "': " << ex.what());
    }
}

void
TranslatorBasic::setItem(const string& xpath, ConstElementPtr elem,
                         LeafBaseType type) {
    optional<string> const s_val(value(elem, type));
    try {
        session_.setItem(xpath, s_val);
    } catch (sysrepo::Error const& ex) {
        isc_throw(SysrepoError, "sysrepo error setting item '" << (elem ? elem->str() : "nullopt")
                                << "' at '" << xpath << "': " << ex.what());
    }
    session_.applyChanges();
}

ElementPtr
TranslatorBasic::translate(optional<DataNode> const& data_node) {
    if (!data_node) {
        return ElementPtr();
    }

    NodeType const node_type(data_node->schema().nodeType());
    ElementPtr result;
    if (node_type == NodeType::Container) {
        for (DataNode const& child : data_node->immediateChildren()) {
            // Recurse.
            ElementPtr const& element(translate(child));

            // If we have a non-null element, set it in a map.
            if (element) {
                // Create a map now and not earlier to make sure that we don't
                // end up with an empty map in case there are no elements.
                if (!result) {
                    result = Element::createMap();
                }

                SchemaNode const& child_schema(child.schema());
                string const key(child_schema.name());
                if (child.schema().nodeType() == NodeType::Leaflist) {
                    ElementPtr l(result->getNonConst(key));
                    if (!l) {
                        l = Element::createList();
                    }
                    l->add(element);
                    result->set(key, l);
                } else {
                    result->set(key, element);
                }
            }
        }
    } else if (node_type == NodeType::List) {
        SchemaNode const& schema(data_node->schema());
        List const& list(schema.asList());
        std::vector<Leaf> const& list_keys(list.keys());

        // Children of the list type are always maps. It would have been a
        // leaf list if they weren't. We rely on the guarantee that
        // insertion order is kept. If we have elements, it is sufficient to
        // check if the latest element contains the keys to see if {child}
        // belongs to it or to a new element.
        ElementPtr underlying_map;
        if (result && !result->empty()) {
            underlying_map = result->getNonConst(result->size() - 1);
            for (Leaf l : list_keys) {
                string const leaf_name(l.name());
                optional<DataNode> key_child(data_node->findPath(leaf_name));

                if (!key_child) {
                    isc_throw(SysrepoError, "sysrepo data node does not contain key form schema");
                }

                if (!underlying_map->get(leaf_name) ||
                    underlying_map->get(leaf_name)->str() != key_child->asTerm().valueStr()) {
                    // At least a key doesn't exist or match so break.
                    // A new map should be created outside the loop.
                    break;
                }
            }
        }

        for (DataNode child : data_node->immediateChildren()) {
            // Recurse.
            ElementPtr element(translate(child));

            // If we have a non-null element, set it in a list.
            if (element) {
                if (!underlying_map) {
                    underlying_map = Element::createMap();

                    // Set all the siblings that are keys. This is done only once.
                    // The second time, the map should be matched in the loop above.
                    // This step is needed especially for lists with multiple keys.
                    // If there were a single key, it's probable that it is {child}.
                    for (Leaf l : list_keys) {
                        string const leaf_name(l.name());
                        optional<DataNode> key_child(data_node->findPath(leaf_name));

                        if (!key_child) {
                            isc_throw(SysrepoError, "sysrepo data node does not contain key form schema");
                        }

                        underlying_map->set(leaf_name, leaf(key_child));
                    }
                    if (!result) {
                        // Create a list now and not earlier to make sure that we don't
                        // end up with an empty list in case there are no elements.
                        result = Element::createList();
                        result->add(underlying_map);
                    }
                }

                SchemaNode const& child_schema(child.schema());
                string const key(child_schema.name());
                underlying_map->set(key, element);
            }
        }
    } else if (node_type == NodeType::Leaf) {
        result = leaf(data_node);
    } else if (node_type == NodeType::Leaflist) {
        result = leaf(data_node);
    } else if (node_type == NodeType::Unknown) {
        isc_throw(SysrepoError, "Unhandled node type: Unknown");
    } else if (node_type == NodeType::Choice) {
        isc_throw(SysrepoError, "Unhandled node type: Choice");
    } else if (node_type == NodeType::AnyXML) {
        isc_throw(SysrepoError, "Unhandled node type: AnyXML");
    } else if (node_type == NodeType::AnyData) {
        isc_throw(SysrepoError, "Unhandled node type: AnyData");
    } else if (node_type == NodeType::Case) {
        isc_throw(SysrepoError, "Unhandled node type: Case");
    } else if (node_type == NodeType::RPC) {
        isc_throw(SysrepoError, "Unhandled node type: RPC");
    } else if (node_type == NodeType::Action) {
        isc_throw(SysrepoError, "Unhandled node type: Action");
    } else if (node_type == NodeType::Notification) {
        isc_throw(SysrepoError, "Unhandled node type: Notification");
    } else if (node_type == NodeType::Uses) {
        isc_throw(SysrepoError, "Unhandled node type: Uses");
    } else if (node_type == NodeType::Input) {
        isc_throw(SysrepoError, "Unhandled node type: Input");
    } else if (node_type == NodeType::Output) {
        isc_throw(SysrepoError, "Unhandled node type: Output");
    } else if (node_type == NodeType::Grouping) {
        isc_throw(SysrepoError, "Unhandled node type: Grouping");
    } else if (node_type == NodeType::Augment) {
        isc_throw(SysrepoError, "Unhandled node type: Augment");
    } else {
        isc_throw(SysrepoError, "Unhandled node type: " << node_type);
    }
    return result;
}

ElementPtr
TranslatorBasic::value(optional<DataNode> data_node) {
    NodeType const node_type(data_node->schema().nodeType());
    if (node_type == NodeType::Leaf || node_type == NodeType::Leaflist) {
        DataNodeTerm const& leaf(data_node->asTerm());
        Value const& v(leaf.value());
        if (holds_alternative<string>(v) ||
            holds_alternative<Enum>(v) ||
            holds_alternative<IdentityRef>(v)) {
            // Should be a string. Call create(). Should be slightly faster
            // than wrapping value in double quotes and calling fromJSON().
            return Element::create(string(leaf.valueStr()));
        } else if (holds_alternative<Binary>(v)) {
            return Element::create(decode64(string(leaf.valueStr())));
        } else {
            // This can be various types so defer to fromJSON().
            return Element::fromJSON(string(leaf.valueStr()));
        }
    }
    return ElementPtr();
}

optional<string>
TranslatorBasic::value(ConstElementPtr const& element,
                       LeafBaseType const type) {
    if (!element) {
        // A null ElementPtr is how we signal that this item requires no value.
        // Useful when setting YANG lists which is the only way to set their
        // keys in sysrepo since setting the key itself results in an error.
        return std::nullopt;
    } else if (element->getType() == Element::map) {
        /// @todo: implement
        isc_throw(NotImplemented, "TranslatorBasic::value(): map element");
    } else if (element->getType() == Element::list) {
        /// @todo: implement
        isc_throw(NotImplemented, "TranslatorBasic::value(): list element");
    }
    if (type == LeafBaseType::Enum ||
        type == LeafBaseType::String ||
        type == LeafBaseType::Union ||
        type == LeafBaseType::IdentityRef) {
        // These types are usually strings in ElementPtr, but are accepted
        // without the double quotes in sysrepo, so get the stringValue().
        if (element->getType() == Element::string) {
            return element->stringValue();
        } else {
            // Except for some nodes which are maps e.g. user-context. And also Unions and
            // IdentityRefs can very well have underlying types that are different than strings.
            // Use the generic str() for those.
            return element->str();
        }
    } else if (type == LeafBaseType::Binary) {
        return encode64(element->stringValue());
    } else {
        // The rest of YANG values can be expressed using the
        // general string representation of ElementPtr.
        return element->str();
    }
}

}  // namespace yang
}  // namespace isc
