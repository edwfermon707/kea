// Copyright (C) 2018-2019,2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <yang/testutils/translator_test.h>

#include <boost/lexical_cast.hpp>

#include <sstream>
#include <variant>

using namespace std;
using namespace isc::data;
using namespace sysrepo;
namespace isc {
namespace yang {
namespace test {

YangRepr::YangReprItem
YangRepr::YangReprItem::get(const string& xpath, Session session) {
    string val_xpath = xpath;
    string value;
    bool settable = true;
    try {
        std::optional<libyang::DataNode> data_node(session.getData(xpath.c_str()));
        if (!data_node) {
            isc_throw(BadValue, "YangReprItem failed at '" << xpath << "'");
        }
        val_xpath = string(data_node->path());
        libyang::NodeType const node_type(data_node->schema().nodeType());
        if (node_type == libyang::NodeType::Container) {
            settable = true;
        } else if (node_type == libyang::NodeType::Leaf) {
            libyang::DataNodeTerm leaf(data_node->asTerm());
            value = leaf.valueStr();
        }
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error in YangReprItem: " << ex.what());
    }
    return (YangReprItem(val_xpath, value, settable));
}

YangRepr::Tree
YangRepr::get(Session session) const {
    Tree result;
    try {
        TranslatorBasic tb(session, model_);
        string const xpath0("/" + model_ + ":*//.");
        tb.forAll(xpath0, [&](libyang::DataNode const& node) {
            string const& xpath(node.path());
            std::cout << "foo " << xpath << std::endl;
            result.emplace(xpath, YangReprItem::get(xpath, session));
        });
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error in YangRepr::getTree: " << ex.what());
    }
    return (result);
}

bool
YangRepr::verify(const Tree& expected, Session session,
                 ostream& errs) const {
    bool result(true);
    const Tree& received = get(session);
    for (auto const& kv : received) {
        string const& xpath(kv.first);
        YangReprItem const& received_node(kv.second);

        auto iterator(expected.find(xpath));
        if (iterator == expected.end()) {
            errs << "received " << received_node << ", but was not expected"
                 << endl;
            result = false;
            continue;
        }

        YangReprItem const expected_node(iterator->second);
        if (expected_node != received_node) {
            errs << "expected " << expected_node << ", but received "
                 << received_node << endl;
            result = false;
        }
    }

    for (auto const& kv : expected) {
        string const& xpath(kv.first);
        YangReprItem const& expected_node(kv.second);

        auto iterator(received.find(xpath));
        if (iterator == received.end()) {
            errs << "expected " << expected_node << ", but was not received"
                 << endl;
            result = false;
        }
    }

    return result;
}

void
YangRepr::set(const Tree& tree, Session session) const {
    for (auto const& kv : tree) {
        YangReprItem const& item(kv.second);
        if (!item.settable_) {
            continue;
        }
        try {
            std::cout << "YangRepr::set: xpath: " << item.xpath_ << ", value: " << item.value_ << std::endl;
            session.setItem(item.xpath_, item.value_);
        } catch (const libyang::ErrorWithCode& ex) {
            isc_throw(SysrepoError,
                      "sysrepo error in YangRepr::set for " << item
                      << ", error: " << ex.what());
        }
    }
    session.applyChanges();
}

ostream& operator<<(ostream& os, const YangRepr::YangReprItem& item) {
    os << item.xpath_ << " = '" << item.value_ << "'";
    return (os);
}

ostream& operator<<(ostream& os, const YangRepr::Tree& tree) {
    for (auto const& kv : tree) {
        YangRepr::YangReprItem const& item(kv.second);
        os << item << endl;
    }
    return (os);
}

}  // namespace test
}  // namespace yang
}  // namespace isc
