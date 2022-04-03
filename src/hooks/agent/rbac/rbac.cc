// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_log.h>

using namespace isc;
using namespace isc::http;
using namespace isc::log;
using namespace isc::rbac;
using namespace std;

namespace isc {
namespace rbac {

RolePtr roleAssign;

RoleConfigTable roleConfigTable;

RoleConfigPtr defaultRoleConfig;

RoleConfigPtr unknownRoleConfig;

RoleConfigPtr
RoleConfig::getConfig(const string& role) {
    if (role.empty()) {
        return (defaultRoleConfig);
    }
    auto it = roleConfigTable.find(role);
    if (it == roleConfigTable.end()) {
        return (unknownRoleConfig);
    }
    return (it->second);
}

HttpResponseJsonPtr
RoleConfig::createReject(const HttpRequestPtr& request,
                         const HttpStatusCode& status_code) {
    if (!request) {
        // Should not happen!
        isc_throw(Unexpected, "null request");
    }
    // From CtrlAgentResponseCreator::createStockHttpResponseInternal.
    HttpVersion http_version(request->context()->http_version_major_,
                             request->context()->http_version_minor_);
    if ((http_version < HttpVersion(1, 0)) ||
        (HttpVersion(1, 1) < http_version)) {
        http_version.major_ = 1;
        http_version.minor_ = 0;
    }
    HttpResponseJsonPtr response(new HttpResponseJson(http_version,
                                                      status_code));
    response->finalize();
    return (response);
}

} // end of namespace rbac
} // end of namespace isc
