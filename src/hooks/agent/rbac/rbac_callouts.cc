// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_config.h>
#include <rbac_log.h>
#include <cc/command_interpreter.h>
#include <exceptions/exceptions.h>
#include <hooks/hooks.h>
#include <http/post_request_json.h>
#include <process/daemon.h>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::http;
using namespace isc::log;
using namespace isc::process;
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
    try {
        // Make the hook library loadable only by the control agent.
        const string& proc_name = Daemon::getProcName();
        if (proc_name != "kea-ctrl-agent") {
            isc_throw(Unexpected, "Bad process name: " << proc_name
                      << ", expected kea-ctrl-agent");
        }

        // Load the configuration.
        ConstElementPtr config = handle.getParameters();
        Config::parse(config);
    } catch (const std::exception& ex) {
        LOG_ERROR(rbac_logger, RBAC_LOAD_FAILED)
            .arg(ex.what());
        return (1);
    }

    LOG_INFO(rbac_logger, RBAC_LOAD_OK);
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

    LOG_INFO(rbac_logger, RBAC_UNLOAD_OK);
    return (0);
}

/// @brief This callout is called at the "auth" hook.
///
/// @param handle CalloutHandle.
/// @return 0 upon success, non-zero otherwise.
int
auth(CalloutHandle& handle) {
    if (!roleAssign) {
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC, RBAC_TRACE_AUTH_DISABLED);
        return (0);
    }

    // Get the parameters.
    HttpRequestPtr request;
    HttpResponseJsonPtr response;
    handle.getArgument("request", request);
    handle.getArgument("response", response);

    if (response) {
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC, RBAC_TRACE_AUTH_RESPONSE)
            .arg(response->toBriefString());
        return (0);
    }

    auto status_code = HttpStatusCode::FORBIDDEN;
    bool updated = false;
    try {
        // Most errors will be caught later.
        if (!request) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_NO_REQUEST);
            return (0);
        }
        // Check TLS.
        if (rbacConfig.getRequireTls() && !Role::requireTls(request)) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_NO_TLS_REJECT);
            status_code = HttpStatusCode::UNAUTHORIZED;
            response = RoleConfig::createReject(request, status_code);
            LOG_INFO(rbac_logger, RBAC_AUTH_RESPONSE)
                .arg(response->toBriefString());
            handle.setArgument("response", response);
            return (0);
        }
        PostHttpRequestJsonPtr request_json =
            boost::dynamic_pointer_cast<PostHttpRequestJson>(request);
        if (!request_json) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_NO_JSON);
            return (0);
        }
        ConstElementPtr body = request_json->getBodyAsJson();
        if (!body) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_EMPTY_BODY);
            return (0);
        }
        if (body->getType() != Element::map) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_BAD_BODY_TYPE);
            return (0);
        }
        ConstElementPtr elem = body->get(CONTROL_COMMAND);
        if (!elem) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_NO_COMMAND);
            return (0);
        }
        if (elem->getType() != Element::string) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                      RBAC_TRACE_AUTH_BAD_COMMAND_TYPE);
            return (0);
        }
        const string& command = elem->stringValue();
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC, RBAC_TRACE_AUTH_COMMAND)
            .arg(command);

        // Assign role.
        const string& role = roleAssign->assign(request);
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC, RBAC_TRACE_AUTH_ROLE)
            .arg(role);
        RoleConfigPtr role_config = RoleConfig::getConfig(role);
        if (!role_config) {
            isc_throw(Unexpected, "can't find a role configuration");
        }

        // filter command.
        if (role_config->match(command)) {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC, RBAC_TRACE_AUTH_ACCEPT)
                .arg(role_config->name_)
                .arg(role)
                .arg(command);
        } else {
            LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC, RBAC_TRACE_AUTH_REJECT)
                .arg(role_config->name_)
                .arg(role)
                .arg(command);
            response = RoleConfig::createReject(request, status_code);
            updated = true;
        }
    } catch (const std::exception& ex) {
        LOG_ERROR(rbac_logger, RBAC_AUTH_ERROR)
            .arg(ex.what());
        status_code = HttpStatusCode::INTERNAL_SERVER_ERROR;
        response = RoleConfig::createReject(request, status_code);
        updated = true;
    }

    // Set parameters.
    if (updated) {
        LOG_INFO(rbac_logger, RBAC_AUTH_RESPONSE)
            .arg(response->toBriefString());
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
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                  RBAC_TRACE_RESPONSE_DISABLED);
        return (0);
    }

    // Get the parameters.
    HttpRequestPtr request;
    HttpResponseJsonPtr response;
    handle.getArgument("request", request);
    handle.getArgument("response", response);

    if (!request || !response) {
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                  RBAC_TRACE_RESPONSE_NO_ARGUMENTS);
        return (0);
    }

    // Decode response.
    ConstElementPtr body = response->getBodyAsJson();
    if (!body) {
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                  RBAC_TRACE_RESPONSE_EMPTY_BODY);
        return (0);
    }
    if (body->getType() != Element::list) {
        // Should be an error response, anyway nothing to filter.
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                  RBAC_TRACE_RESPONSE_BAD_BODY_TYPE);
        return (0);
    }
    if (body->size() < 1) {
        LOG_DEBUG(rbac_logger, DBGLVL_TRACE_BASIC,
                  RBAC_TRACE_RESPONSE_EMPTY_BODY_LIST);
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
