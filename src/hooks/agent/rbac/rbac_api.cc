// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac_api.h>
#include <exceptions/exceptions.h>

// C++11 has no directory walking tool.
#include <dirent.h>

#include <iostream>
#include <cerrno>

using namespace isc;
using namespace isc::data;
using namespace isc::rbac;
using namespace std;

namespace isc {
namespace rbac {

ApiTable apiTable;

ApiPtr
Api::getApiByName(const string& name) {
    auto const& it = apiTable.find(name);
    if (it == apiTable.cend()) {
        return (ApiPtr());
    }
    return (*it);
}

void
Api::fillApiTable(const string& dirname) {
    DIR* dir;
    try {
        dir = opendir(dirname.c_str());
        if (!dir) {
            isc_throw(BadValue, "can't open directory '" << dirname
                      << "': " << string(strerror(errno)));
        }
        for (;;) {
            struct dirent *ent = readdir(dir);
            if (!ent) {
                // done or in error but do not care...
                break;
            }
            string filename(ent->d_name);
            size_t len = filename.size();
            if (len < 6) {
                // too short: skip it.
                continue;
            }
            if ((filename[0] < 'a') ||
                (filename[0] > 'z') ||
                (filename[len - 1] != 'n') ||
                (filename[len - 2] != 'o') ||
                (filename[len - 3] != 's') ||
                (filename[len - 4] != 'j') ||
                (filename[len - 5] != '.')) {
                // not [a-z]*.json: skip it.
                continue;
            }
            ConstElementPtr json = Element::fromJSONFile(filename, true);
            Api::parse(json, true);
        }
        static_cast<void>(closedir(dir));
    } catch (const std::exception& ex) {
        static_cast<void>(closedir(dir));
        isc_throw(BadValue, "fill API table from '" << dirname
                  << "' failed with " << ex.what());
    }
}

void
Api::parse(ConstElementPtr cfg, bool others) {
    if (!cfg) {
        isc_throw(BadValue, "parse null command config");
    }
    if (cfg->getType() != Element::map) {
        isc_throw(BadValue, "command config is not a map");
    }
    string name;
    string access;
    string hook;
    for (auto const& entry : cfg->mapValue()) {
        if (entry.first == "name") {
            if (entry.second->getType() != Element::string) {
                isc_throw(BadValue, "command name is not a string");
            }
            name = entry.second->stringValue();
            if (name.empty()) {
                isc_throw(BadValue, "command name is empty");
            }
        } else if (entry.first == "access") {
            if (entry.second->getType() != Element::string) {
                isc_throw(BadValue, "command access is not a string");
            }
            access = entry.second->stringValue();
            if (access.empty()) {
                isc_throw(BadValue, "command access is empty");
            }
            if (others && (access != "read") && (access != "write")) {
                isc_throw(BadValue, "command access '" << access
                          << "' is not 'read' or 'write'");
            }
        } else if (entry.first == "hook") {
            if (entry.second->getType() != Element::string) {
                isc_throw(BadValue, "command hook is not a string");
            }
            hook = entry.second->stringValue();
        } else if (!others) {
            isc_throw(BadValue, "command spurious keyword '"
                      << entry.first << "'");
        }
    }
    if (name.empty()) {
        isc_throw(BadValue, "'name' is required in command config");
    }
    if (access.empty()) {
        isc_throw(BadValue, "'access' is required in command config");
    }
    if (Api::getApiByName(name)) {
        isc_throw(BadValue, "command '" << name << "' is already defined");
    }
    static_cast<void>(apiTable.insert(ApiPtr(new Api(name, access, hook))));
}

} // end of namespace rbac
} // end of namespace isc
