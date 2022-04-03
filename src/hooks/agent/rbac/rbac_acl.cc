// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_log.h>
#include <exceptions/exceptions.h>

using namespace isc;
using namespace isc::data;
using namespace isc::log;
using namespace isc::rbac;
using namespace std;

namespace isc {
namespace rbac {

AclTable aclTable;

void
Acl::initTable() {
    aclTable.clear();
    aclTable["ALL"] = AclPtr(new AllAcl);
    aclTable["NONE"] = AclPtr(new NoneAcl);
    aclTable["READ"] = AclPtr(new AccessAcl("read"));
    aclTable["WRITE"] = AclPtr(new AccessAcl("write"));
}

AclPtr
Acl::parse(ConstElementPtr cfg) {
    if (!cfg) {
        isc_throw(BadValue, "parse null access control list config");
    }
    if (cfg->getType() == Element::string) {
        const string& name = cfg->stringValue();
        auto it = aclTable.find(name);
        if (it == aclTable.end()) {
            isc_throw(BadValue, "unknown access control list name '"
                      << name << "'");
        }
        return (it->second);
    }
    if (cfg->getType() != Element::map) {
      isc_throw(BadValue, "access control list config is not a map");
    }
    AclPtr acl;
    for (auto entry : cfg->mapValue()) {
        if (entry.first == "comment") {
            continue;
        }
        if (acl) {
            isc_throw(BadValue, "spurious '" << entry.first << "' entry in "
                      << cfg->str());
        }
        if (entry.first == "not") {
            acl.reset(new NotAcl(parse(entry.second)));
        } else if (entry.first == "and") {
            acl.reset(new AndAcl(parseList(entry.second)));
        } else if (entry.first == "or") {
            acl.reset(new OrAcl(parseList(entry.second)));
        } else if (entry.first == "commands") {
            if (entry.second->getType() != Element::list) {
                isc_throw(BadValue, "commands access control list is not "
                          << "a list");
            }
            std::set<std::string> names;
            for (auto const& elem : entry.second->listValue()) {
                if (elem->getType() != Element::string) {
                    isc_throw(BadValue, "commands access control list item is "
                              << "not a string");
                }
                const string& name = elem->stringValue();
                if (!Api::getApiByName(name)) {
                    isc_throw(BadValue, "unknown command '" << name << "'");
                }
                static_cast<void>(names.insert(name));
            }
            acl.reset(new NamesAcl(names));
        } else if (entry.first == "access") {
            if (entry.second->getType() != Element::string) {
                isc_throw(BadValue, "access access control list is not a "
                          << "string");
            }
            acl.reset(new AccessAcl(entry.second->stringValue()));
        } else if (entry.first == "hook") {
            if (entry.second->getType() != Element::string) {
                isc_throw(BadValue, "hook access control list is not a "
                          << "string");
            }
            acl.reset(new HookAcl(entry.second->stringValue()));
        } else {
            isc_throw(BadValue, "unknown access control keyword '"
                      << entry.first << "'");
        }
    }
    if (!acl) {
        isc_throw(BadValue, "bad access control config " << cfg->str());
    }
    return (acl);
}

AclList
Acl::parseList(ConstElementPtr cfg) {
    if (!cfg) {
        isc_throw(BadValue, "parse null list of access control list configs");
    }
    if (cfg->getType() != Element::list) {
        isc_throw(BadValue, "list of access control lists is not a list");
    }
    AclList acls;
    for (auto const& elem : cfg->listValue()) {
        acls.push_back(Acl::parse(elem));
    }
    return (acls);
}

} // end of namespace rbac
} // end of namespace isc
