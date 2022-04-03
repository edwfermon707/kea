// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_log.h>
#include <rbac_response_filter.h>
#include <cc/command_interpreter.h>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::log;
using namespace isc::rbac;
using namespace std;

namespace isc {
namespace rbac {

void
ListCommandsResponseFilter::filter(const string& role, ConstElementPtr body) {
    if (!body || (body->getType() != Element::map)) {
        return;
    }
    ConstElementPtr command = body->get(CONTROL_COMMAND);
    if (!command || (command->getType() != Element::string)) {
        return;
    }
    if (command->stringValue() != "list-commands") {
        // Add a log here.
        return;
    }
    isc_throw(NotImplemented, "ListCommandsResponseFilter::filter("
              << body->str() << ")");
}

void
ConfigResponseFilter::filter(const string&, ConstElementPtr body) {
    if (!body || (body->getType() != Element::map)) {
        return;
    }
    ConstElementPtr command = body->get(CONTROL_COMMAND);
    if (!command || (command->getType() != Element::string)) {
        return;
    }
    if (command->stringValue() != "config-get") {
        // Add a log here.
        return;
    }
    isc_throw(NotImplemented, "ConfigResponseFilter::filter("
              << body->str() << ")");
}

} // end of namespace rbac
} // end of namespace isc
