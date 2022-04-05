// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef RBAC_RESPONSE_FILTER_H
#define RBAC_RESPONSE_FILTER_H

#include <http/response_json.h>
#include <list>
#include <map>

namespace isc {
namespace rbac {

/// @brief Forward declaration of ResponseFilter.
class ResponseFilter;

/// @brief The type of shared pointers to response filters.
typedef boost::shared_ptr<ResponseFilter> ResponseFilterPtr;

/// @brief The type of list of shared pointers to response filters.
typedef std::list<ResponseFilterPtr> ResponseFilterList;

/// @brief The type of the response filter table.
typedef std::map<std::string, ResponseFilterPtr> ResponseFilterTable;

/// @brief Response filter base class.
class ResponseFilter {
public:

    /// @brief Constructor.
    ///
    /// @param name Name of the response filter class.
    /// @throw Unexpected when name is empty.
    ResponseFilter(const std::string& name) : name_(name) {
        if (name.empty()) {
            isc_throw(Unexpected, "empty response filter name");
        }
    }

    /// @brief Destructor.
    virtual ~ResponseFilter() = default;

    /// @brief Returns the name.
    ///
    /// @return the name.
    std::string getName() const {
        return (name_);
    }

    /// @brief Filter a response.
    ///
    /// @param role The role.
    /// @param body The JSON response body.
    /// @return whether the body was modified.
    virtual bool filter(const std::string& role,
                        data::ConstElementPtr body) = 0;

    /// @brief Initialize the response filter table.
    static void initResponseFilterTable();

    /// @brief Parse a response filter list.
    ///
    /// @param cfg Configuration of response filter list.
    static ResponseFilterList parse(data::ConstElementPtr cfg);

protected:
    /// @brief The class name.
    std::string name_;
};

/// @brief Response filter for list-commands.
///
/// Removes not allowed commands from the response.
class ListCommandsResponseFilter : public ResponseFilter {
public:

    /// @brief Constructor.
    ListCommandsResponseFilter() : ResponseFilter("list-commands") {
    }

    /// @brief Filter a response from list-commands.
    ///
    /// @param role The role.
    /// @param body The JSON response body.
    /// @return whether the body was modified.
    virtual bool filter(const std::string& role,
                        data::ConstElementPtr body) final;
};

/// @brief Response filter for config.
///
/// Removes config-control from a response with a config.
class ConfigResponseFilter : public ResponseFilter {
public:

    /// @brief Constructor.
    ConfigResponseFilter() : ResponseFilter("config") {
    }

    /// @brief Filter a response with a config.
    ///
    /// @param body The JSON response body.
    /// @return whether the body was modified.
    virtual bool filter(const std::string&, data::ConstElementPtr body) final;
};

/// @brief The response filter table.
extern ResponseFilterTable responseFilterTable;

} // end of namespace rbac
} // end of namespace isc
#endif
