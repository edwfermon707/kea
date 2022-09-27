// Copyright (C) 2018-2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <yang/translator_database.h>
#include <yang/adaptor.h>
#include <yang/yang_models.h>

#include <sstream>

using namespace std;
using namespace isc::data;
using namespace sysrepo;

namespace isc {
namespace yang {

TranslatorDatabase::TranslatorDatabase(Session session, const string& model)
    : TranslatorBasic(session, model) {
}

TranslatorDatabase::~TranslatorDatabase() {
}

ElementPtr
TranslatorDatabase::getDatabase(const string& xpath) {
    try {
        if ((model_ == KEA_DHCP4_SERVER) ||
            (model_ == KEA_DHCP6_SERVER)) {
            return (getDatabaseKea(xpath));
        }
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error getting database access at '" << xpath
                  << "': " << ex.what());
    }
    isc_throw(NotImplemented,
              "getDatabase not implemented for the model: " << model_);
}

ElementPtr
TranslatorDatabase::getDatabaseKea(const string& xpath) {
    ConstElementPtr type = getItem(xpath + "/database-type");
    if (!type) {
        return (ElementPtr());
    }
    ElementPtr result = Element::createMap();
    result->set("type", type);
    checkAndGetLeaf(result, xpath, "user");
    checkAndGetLeaf(result, xpath, "password");
    checkAndGetLeaf(result, xpath, "host");
    checkAndGetLeaf(result, xpath, "name");
    checkAndGetLeaf(result, xpath, "persist");
    checkAndGetLeaf(result, xpath, "port");
    checkAndGetLeaf(result, xpath, "lfc-interval");
    checkAndGetLeaf(result, xpath, "readonly");
    checkAndGetLeaf(result, xpath, "trust-anchor");
    checkAndGetLeaf(result, xpath, "cert-file");
    checkAndGetLeaf(result, xpath, "key-file");
    checkAndGetLeaf(result, xpath, "cipher-list");
    checkAndGetLeaf(result, xpath, "connect-timeout");
    checkAndGetLeaf(result, xpath, "max-reconnect-tries");
    checkAndGetLeaf(result, xpath, "reconnect-wait-time");
    checkAndGetLeaf(result, xpath, "max-row-errors");
    checkAndGetLeaf(result, xpath, "on-fail");
    ConstElementPtr context = getItem(xpath + "/user-context");
    if (context) {
        result->set("user-context", Element::fromJSON(context->stringValue()));
    }
    return (result);
}

void
TranslatorDatabase::setDatabase(const string& xpath,
                                ConstElementPtr elem,
                                bool skip) {
    try {
        if ((model_ == KEA_DHCP4_SERVER) ||
            (model_ == KEA_DHCP6_SERVER)) {
            setDatabaseKea(xpath, elem, skip);
        } else {
            isc_throw(NotImplemented,
                      "setDatabase not implemented for the model: " << model_);
        }
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error setting database access '" << elem->str()
                  << "' at '" << xpath << "': " << ex.what());
    }
}

void
TranslatorDatabase::setDatabaseKea(const string& xpath,
                                   ConstElementPtr elem,
                                   bool skip) {
    if (!elem) {
        delItem(xpath);
        return;
    }
    if (!skip) {
        ConstElementPtr type = elem->get("type");
        if (!type) {
            isc_throw(BadValue, "setDatabase requires database type: "
                      << elem->str());
        }
        setItem(xpath + "/database-type", type);
    }
    checkAndSetLeaf(elem, xpath, "user");
    checkAndSetLeaf(elem, xpath, "password");
    checkAndSetLeaf(elem, xpath, "host");
    checkAndSetLeaf(elem, xpath, "name");
    checkAndSetLeaf(elem, xpath, "persist");
    checkAndSetLeaf(elem, xpath, "port");
    checkAndSetLeaf(elem, xpath, "lfc-interval");
    checkAndSetLeaf(elem, xpath, "readonly");
    checkAndSetLeaf(elem, xpath, "trust-anchor");
    checkAndSetLeaf(elem, xpath, "cert-file");
    checkAndSetLeaf(elem, xpath, "key-file");
    checkAndSetLeaf(elem, xpath, "cipher-list");
    checkAndSetLeaf(elem, xpath, "connect-timeout");
    checkAndSetLeaf(elem, xpath, "max-reconnect-tries");
    checkAndSetLeaf(elem, xpath, "reconnect-wait-time");
    checkAndSetLeaf(elem, xpath, "max-row-errors");
    checkAndSetLeaf(elem, xpath, "on-fail");
    ConstElementPtr context = Adaptor::getContext(elem);
    if (context) {
        setItem(xpath + "/user-context", Element::create(context->str()));
    }
}

TranslatorDatabases::TranslatorDatabases(Session session,
                                         const string& model)
    : TranslatorBasic(session, model),
      TranslatorDatabase(session, model) {
}

TranslatorDatabases::~TranslatorDatabases() {
}

ConstElementPtr
TranslatorDatabases::getDatabases(const string& xpath) {
    try {
        if ((model_ == KEA_DHCP4_SERVER) ||
            (model_ == KEA_DHCP6_SERVER)) {
            return (getDatabasesKea(xpath));
        }
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error getting database accesses at '" << xpath
                  << "': " << ex.what());
    }
    isc_throw(NotImplemented,
              "getDatabases not implemented for the model: " << model_);
}

ElementPtr
TranslatorDatabases::getDatabasesKea(const string& xpath) {
    return getList<TranslatorDatabase>(xpath, *this,
                                       &TranslatorDatabase::getDatabase);
}

void
TranslatorDatabases::setDatabases(const string& xpath, ConstElementPtr elem) {
    try {
        if ((model_ == KEA_DHCP4_SERVER) ||
            (model_ == KEA_DHCP6_SERVER)) {
            setDatabasesKea(xpath, elem);
        } else {
            isc_throw(NotImplemented,
                      "setDatabases not implemented for the model: "
                      << model_);
        }
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error setting database accesses '" << elem->str()
                  << "' at '" << xpath << "': " << ex.what());
    }
}

void
TranslatorDatabases::setDatabasesKea(const string& xpath,
                                     ConstElementPtr elem) {
    if (!elem) {
        delItem(xpath);
        return;
    }
    for (size_t i = 0; i < elem->size(); ++i) {
        ConstElementPtr database = elem->get(i);
        if (!database->contains("type")) {
            isc_throw(BadValue, "database without type: " << database->str());
        }
        string type = database->get("type")->stringValue();
        ostringstream key;
        key << xpath << "[database-type='" << type << "']";
        setDatabase(key.str(), database, true);
    }
}

}  // namespace yang
}  // namespace isc
