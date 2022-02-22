// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>
#include <database/database_connection.h>
#include <database/db_exceptions.h>
#include <database/server.h>
#include <database/testutils/schema.h>
#include <dhcp/libdhcp++.h>
#include <dhcp/option6_addrlst.h>
#include <dhcp/option_int.h>
#include <dhcp/option_space.h>
#include <dhcp/option_string.h>
#include <dhcpsrv/cfgmgr.h>
#include <dhcpsrv/client_class_def.h>
#include <dhcpsrv/config_backend_dhcp6_mgr.h>
#include <dhcpsrv/pool.h>
#include <dhcpsrv/subnet.h>
#include <dhcpsrv/testutils/generic_cb_dhcp6_unittest.h>
#include <dhcpsrv/testutils/test_utils.h>
#include <testutils/gtest_utils.h>

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>

using namespace isc;
using namespace isc::util;
using namespace isc::asiolink;
using namespace isc::db;
using namespace isc::db::test;
using namespace isc::data;
using namespace isc::dhcp;
using namespace isc::dhcp::test;
using namespace isc::process;
using namespace isc::test;
namespace ph = std::placeholders;

void
GenericConfigBackendDHCPv6Test::SetUp() {
    // Ensure we have the proper schema with no transient data.
    createSchema();

#if 0
    try {
        // Create a connection parameter map and use it to start the backend.
        DatabaseConnection::ParameterMap params =
            DatabaseConnection::parse(validConnectionString());
        cbptr_ = backendFactory(params);
    } catch (...) {
        std::cerr << "*** ERROR: unable to open database. The test\n"
                     "*** environment is broken and must be fixed before\n"
                     "*** the tests will run correctly.\n"
                     "*** The reason for the problem is described in the\n"
                     "*** accompanying exception output.\n";
        throw;
    }
#else
    DatabaseConnection::ParameterMap params =
            DatabaseConnection::parse(validConnectionString());
    ASSERT_NO_THROW_LOG(cbptr_ = backendFactory(params));
#endif

    // Create test data.
    initTestServers();
    initTestOptions();
    initTestSubnets();
    initTestSharedNetworks();
    initTestOptionDefs();
    initTestClientClasses();
    initTimestamps();
}

void
GenericConfigBackendDHCPv6Test::TearDown() {
    cbptr_.reset();
    // If data wipe enabled, delete transient data otherwise destroy the schema.
    destroySchema();
}

void
GenericConfigBackendDHCPv6Test::initTestServers() {
}

void
GenericConfigBackendDHCPv6Test::initTestSubnets() {
}

void
GenericConfigBackendDHCPv6Test::initTestSharedNetworks() {
}

void
GenericConfigBackendDHCPv6Test::initTestOptionDefs() {
}

void
GenericConfigBackendDHCPv6Test::initTestOptions() {
}

void
GenericConfigBackendDHCPv6Test::initTestClientClasses() {
}

void
GenericConfigBackendDHCPv6Test::initTimestamps() {
}

std::string
GenericConfigBackendDHCPv6Test::logExistingAuditEntries(const std::string& server_tag) {
    std::ostringstream s;

    auto& mod_time_idx = audit_entries_[server_tag].get<AuditEntryModificationTimeIdTag>();

    for (auto audit_entry_it = mod_time_idx.begin();
         audit_entry_it != mod_time_idx.end();
         ++audit_entry_it) {
        auto audit_entry = *audit_entry_it;
        s << audit_entry->getObjectType() << ", "
          << audit_entry->getObjectId() << ", "
          << static_cast<int>(audit_entry->getModificationType()) << ", "
          << audit_entry->getModificationTime() << ", "
          << audit_entry->getRevisionId() << ", "
          << audit_entry->getLogMessage()
          << std::endl;
    }

    return (s.str());
}

void
GenericConfigBackendDHCPv6Test::getTypeTest(const std::string& expected_type) {
    DatabaseConnection::ParameterMap params;
    params["name"] = "keatest";
    params["password"] = "keatest";
    params["user"] = "keatest";
    ASSERT_NO_THROW_LOG(cbptr_ = backendFactory(params));
    ASSERT_NE(cbptr_->getParameters(), DatabaseConnection::ParameterMap());
    EXPECT_EQ(expected_type, cbptr_->getType());
}

void
GenericConfigBackendDHCPv6Test::getHostTest() {
    DatabaseConnection::ParameterMap params;
    params["name"] = "keatest";
    params["password"] = "keatest";
    params["user"] = "keatest";
    ASSERT_NO_THROW_LOG(cbptr_ = backendFactory(params));
    ASSERT_NE(cbptr_->getParameters(), DatabaseConnection::ParameterMap());
    EXPECT_EQ("localhost", cbptr_->getHost());
}

void
GenericConfigBackendDHCPv6Test::getPortTest() {
    DatabaseConnection::ParameterMap params;
    params["name"] = "keatest";
    params["password"] = "keatest";
    params["user"] = "keatest";
    ASSERT_NO_THROW_LOG(cbptr_ = backendFactory(params));
    ASSERT_NE(cbptr_->getParameters(), DatabaseConnection::ParameterMap());
    EXPECT_EQ(0, cbptr_->getPort());
}

void
GenericConfigBackendDHCPv6Test::testNewAuditEntry(const std::string& exp_object_type,
                                                  const AuditEntry::ModificationType&
                                                        exp_modification_type,
                                                  const std::string& exp_log_message,
                                                  const ServerSelector& server_selector,
                                                  const size_t new_entries_num,
                                                  const size_t max_tested_entries) {

    // Get the server tag for which the entries are fetched.
    std::string tag;
    if (server_selector.getType() == ServerSelector::Type::ALL) {
        // Server tag is 'all'.
        tag = "all";
    } else {
        auto tags = server_selector.getTags();
        // This test is not meant to handle multiple server tags all at once.
        if (tags.size() > 1) {
            ADD_FAILURE() << "Test error: do not use multiple server tags";
        } else if (tags.size() == 1) {
            // Get the server tag for which we run the current test.
            tag = tags.begin()->get();
        }
    }

    auto audit_entries_size_save = audit_entries_[tag].size();

    // Audit entries for different server tags are stored in separate
    // containers.
    ASSERT_NO_THROW_LOG(audit_entries_[tag]
                        = cbptr_->getRecentAuditEntries(server_selector,
                                                        timestamps_["two days ago"], 0));
    ASSERT_EQ(audit_entries_size_save + new_entries_num, audit_entries_[tag].size())
              << logExistingAuditEntries(tag);

    auto& mod_time_idx = audit_entries_[tag].get<AuditEntryModificationTimeIdTag>();

    // Iterate over specified number of entries starting from the most recent
    // one and check they have correct values.
    for (auto audit_entry_it = mod_time_idx.rbegin();
         ((std::distance(mod_time_idx.rbegin(), audit_entry_it) < new_entries_num) &&
         (std::distance(mod_time_idx.rbegin(), audit_entry_it) < max_tested_entries));
         ++audit_entry_it) {
        auto audit_entry = *audit_entry_it;
        EXPECT_EQ(exp_object_type, audit_entry->getObjectType())
                  << logExistingAuditEntries(tag);
        EXPECT_EQ(exp_modification_type, audit_entry->getModificationType())
                  << logExistingAuditEntries(tag);
        EXPECT_EQ(exp_log_message, audit_entry->getLogMessage())
                  << logExistingAuditEntries(tag);
    }
}
