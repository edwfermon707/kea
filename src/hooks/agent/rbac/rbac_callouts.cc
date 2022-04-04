// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_log.h>
#include <cc/command_interpreter.h>
#include <exceptions/exceptions.h>
#include <hooks/hooks.h>
#include <http/post_request_json.h>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::http;
using namespace isc::log;
using namespace isc::rbac;
using namespace std;

// Functions accessed by the hooks framework use C linkage to avoid the name
// mangling that accompanies use of the C++ compiler as well as to avoid
// issues related to namespaces.
extern "C" {

/// @brief This function is called when the library is loaded.
///
/// @param handle library handle.
/// @return 0 when initialization is successful, 1 otherwise.
int
load(LibraryHandle& handle) {
    /// @todo: parse config.
    return (0);
}

/// @brief This function is called when the library is unloaded.
///
/// @return always 0.
int
unload() {
    roleAssign.reset();
    roleConfigTable.clear();
    defaultRoleConfig.reset();
    unknownRoleConfig.reset();
    aclTable.clear();
    apiTable.clear();
    apiAccesses.clear();
    apiHooks.clear();
    responseFilterTable.clear();
    return (0);
}

/// @brief This callout is called at the "auth" hook.
///
/// @param handle CalloutHandle.
/// @return 0 upon success, non-zero otherwise.
int
auth(CalloutHandle& handle) {
    if (!roleAssign) {
        // The RBAC is disabled.
        return (0);
    }

    // Get the parameters.
    HttpRequestPtr request;
    HttpResponseJsonPtr response;
    handle.getArgument("request", request);
    handle.getArgument("response", response);

    if (response) {
        /// Response already set likely to an error.
        return (0);
    }

    auto status_code = HttpStatusCode::UNAUTHORIZED;
    bool updated = false;
    try {
        // Most errors will be caught later.
        if (!request) {
            // No request.
            return (0);
        }
        PostHttpRequestJsonPtr request_json =
            boost::dynamic_pointer_cast<PostHttpRequestJson>(request);
        if (!request_json) {
            // Not a JSON POST request.
            return (0);
        }
        ConstElementPtr body = request_json->getBodyAsJson();
        if (!body) {
            // No JSON body.
            return (0);
        }
        if (body->getType() != Element::map) {
            // Body is not a map.
            return (0);
        }
        ConstElementPtr elem = body->get(CONTROL_COMMAND);
        if (!elem) {
            // No command.
            return (0);
        }
        if (elem->getType() != Element::string) {
            // Command is not a string.
            return (0);
        }
        const string& command = elem->stringValue();

        // Assign role.
        const string& role = roleAssign->assign(request);
        RoleConfigPtr role_config = RoleConfig::getConfig(role);

        // filter command.
        if (role_config && !role_config->match(command)) {
            response = RoleConfig::createReject(request, status_code);
            updated = true;
        }
    } catch (const std::exception& ex) {
        status_code = HttpStatusCode::INTERNAL_SERVER_ERROR;
        response = RoleConfig::createReject(request, status_code);
        updated = true;
    }

    // Set parameters.
    if (updated) {
        handle.setArgument("response", response);
    }

    return (0);
}

/// @brief This callout is called at the "response" hook.
///
/// @param handle CalloutHandle.
/// @return 0 upon success, non-zero otherwise.
int
response(CalloutHandle& handle) {
    if (!roleAssign) {
        // The RBAC is disabled.
        return (0);
    }

    // Get the parameters.
    HttpRequestPtr request;
    HttpResponseJsonPtr response;
    handle.getArgument("request", request);
    handle.getArgument("response", response);

    if (!request || !response) {
        // Give up!
        return (0);
    }

    // Decode response.
    ConstElementPtr body = response->getBodyAsJson();
    if (!body) {
        // No body to act on.
        return (0);
    }
    if (body->getType() != Element::list) {
        // Should be an error response, anyway nothing to filter.
        return (0);
    }
    if (body->size() < 1) {
        // Empty body.
        return (0);
    }

    // Assign role.
    const string& role = roleAssign->assign(request);
    RoleConfigPtr role_config = RoleConfig::getConfig(role);
    if (!role_config) {
        return (0);
    }

    // Apply filters on each list item.
    response->setBodyAsJson(body);

    // Set parameters.
    handle.setArgument("response", response);
    return (0);
}

}
