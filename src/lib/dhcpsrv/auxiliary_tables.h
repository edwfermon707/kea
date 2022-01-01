// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef AUXILIARY_TABLES_H
#define AUXILIARY_TABLES_H

#include <functional>
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>

namespace isc {
namespace dhcp {

/// @brief Auxiliary table template.
///
/// @tparam NetworkPtrType A shared point to a subtype of Network
/// in all use cases.

template <typename NetworkPtrType>
class AuxiliaryTable {
public:
    /// @brief Type of the remove method.
    typedef std::function<void(const NetworkPtrType&)> RemoveType;

    /// @brief Type of the add method.
    typedef std::function<void(const NetworkPtrType&)> AddType;

    /// @brief Type of the update method.
    typedef std::function<void(const NetworkPtrType&, const NetworkPtrType&)>
        UpdateType;

    /// @brief Constructor.
    ///
    /// @brief name The name.
    /// @brief remove The remove method.
    /// @brief add The add method.
    /// @brief update The update method, if 0 remove + add.
    AuxiliaryTable(const std::string& name,
                   RemoveType& remove, AddType& add,
                   UpdateType& update = null_update) :
        name_(name), remove_(remove), add_(add), update_(update) {
    }

    /// @brief Destructor.
    virtual ~AuxiliaryTable() {
    }

    /// @brief The name.
    const std::string& name_;

    /// @brief The remove method.
    RemoveType remove_;

    /// @brief The add method.
    AddType add_;

    /// @brief The update method (by default remove + add).
    UpdateType update_;

    /// @brief The null update method.
    static UpdateType null_update;
};

template <typename NetworkPtrType>
typename AuxiliaryTable<NetworkPtrType>::UpdateType
    AuxiliaryTable<NetworkPtrType>::null_update =
    AuxiliaryTable<NetworkPtrType>::UpdateType();

/// @brief Type of shared pointers to an auxiliary table.
template <typename NetworkPtrType>
using AuxiliaryTablePtr = boost::shared_ptr<AuxiliaryTable<NetworkPtrType> >;

/// @brief Auxiliary tables template.
///
/// @tparam NetworkPtrType A shared point to a subtype of Network
/// in all use cases.

template <typename NetworkPtrType>
class AuxiliaryTables {
public:
    /// @brief Register a new table.
    ///
    /// @param table A new table.
    void addTable(AuxiliaryTablePtr<NetworkPtrType> table) {
        tables_.push_back(table);
    }

    /// @brief Unregister a table.
    ///
    /// @param table The table to remove.
    void delTable(AuxiliaryTablePtr<NetworkPtrType> table) {
        for (auto it = tables_.begin(); it != tables_.end(); ++it) {
            if ((*it)->name_ == table->name) {
                tables_.erase(it);
                return;
            }
        }
    }

    /// @brief Clear tables.
    void clear() {
        tables_.clear();
    }

    /// @brief Remove a network.
    ///
    /// @param net The network to remove.
    void remove(const NetworkPtrType& net) {
        for (auto table : tables_) {
            table->remove_(net);
        }
    }

    /// @brief Add a network.
    ///
    /// @param net A network to add.
    void add(const NetworkPtrType& net) {
        for (auto table : tables_) {
            table->add_(net);
        }
    }

    /// @brief Update a network.
    ///
    /// @param from The previous network.
    /// @param to The new network.
    void update(const NetworkPtrType& from, const NetworkPtrType& to) {
        for (auto table : tables_) {
            if (table->update_) {
                table->update_(from, to);
            } else {
                table->remove_(from);
                table->add_(to);
            }
        }
    }

protected:
    /// @brief The list of tables.
    std::list<AuxiliaryTablePtr<NetworkPtrType> > tables_;
};

} // namespace isc::dhcp
} // namespace isc

#endif // AUXILIARY_TABLES_H
