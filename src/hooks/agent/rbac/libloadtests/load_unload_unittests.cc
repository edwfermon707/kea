// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @file This file contains tests which exercise the load and unload
/// functions in the role based access control hook library. In order
/// to test the load function, one must be able to pass it hook
/// library parameters. The the only way to populate these parameters
/// is by actually loading the library via HooksManager::loadLibraries().

#include <config.h>

#include <hooks/hooks_manager.h>
#include <process/daemon.h>

#include <gtest/gtest.h>
#include <errno.h>

using namespace std;
using namespace isc;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::process;

namespace {

/// @brief Test fixture for testing loading and unloading the RBAC library
class LibLoadTest : public ::testing::Test {
public:
    /// @brief Constructor
    LibLoadTest() {
        reset();
    }

    /// @brief Destructor
    /// Removes files that may be left over from previous tests
    virtual ~LibLoadTest() {
        reset();
    }

    /// @brief Removes files that may be left over from previous tests
    virtual void reset() {
        HooksManager::unloadLibraries();
    }

    /// @brief Adds library/parameters to list of libraries to be loaded.
    void addLib(const std::string& lib, ConstElementPtr params) {
        libraries_.push_back(make_pair(lib, params));
    }

    /// @brief Load all specified libraries.
    ///
    /// The libraries are stored in libraries_.
    bool loadLibs() {
        return (HooksManager::loadLibraries(libraries_));
    }

    /// @brief Unloads all libraries.
    void unloadLibs() {
        EXPECT_NO_THROW(HooksManager::unloadLibraries());
    }

    /// @brief Return basic, valid RBAC configuration in JSON format.
    ElementPtr createValidJsonConfiguration() const {
        ElementPtr cfg = Element::createMap();
        cfg->set("assign-role-method",
                 Element::create(string("remote-address")));
        cfg->set("api-files", Element::create(string(API_DIR)));
        return (cfg);
    }

    /// @brief Libraries.
    HookLibsCollection libraries_;
};

// Simple test that checks the library can be loaded in a control agent.
TEST_F(LibLoadTest, validLoad) {
    // Set proc name.
    Daemon::setProcName("kea-ctrl-agent");

    // Add library with valid configuration.
    addLib(RBAC_LIB_SO, createValidJsonConfiguration());

    // Library should load without issue.
    EXPECT_TRUE(loadLibs());
}

// Simple test that checks the library can be loaded and unloaded several times
// in a control agent.
TEST_F(LibLoadTest, validLoads) {
    // Set proc name.
    Daemon::setProcName("kea-ctrl-agent");

    // Add library with valid configuration.
    addLib(RBAC_LIB_SO, createValidJsonConfiguration());

    EXPECT_TRUE(loadLibs());
    unloadLibs();

    EXPECT_TRUE(loadLibs());
    unloadLibs();

    loadLibs();
    unloadLibs();
}

// Verifies that an unknown parameter in an otherwise valid configuration
// is detected.
TEST_F(LibLoadTest, unknownParameterLoad) {
    // Set proc name.
    Daemon::setProcName("kea-ctrl-agent");

    /// Add unknown element "foo" to valid config.
    ElementPtr cfg = createValidJsonConfiguration();
    cfg->set("foo", Element::create("bar"));

    // Add library with invalid configuration.
    addLib(RBAC_LIB_SO, cfg);

    // The load should fail.
    EXPECT_FALSE(loadLibs());
}

// Verifies that a bad type parameter in an otherwise valid configuration
// is detected.
TEST_F(LibLoadTest, badTypeParameterLoad) {
    // Set proc name.
    Daemon::setProcName("kea-ctrl-agent");

    /// Add unknown element "foo" to valid config.
    ElementPtr cfg = createValidJsonConfiguration();
    cfg->set("require-tls", Element::create("bar"));

    // Add library with invalid configuration.
    addLib(RBAC_LIB_SO, cfg);

    // The load should fail.
    EXPECT_FALSE(loadLibs());
}

// Verifies that a bad parameter in an otherwise valid configuration
// is detected.
TEST_F(LibLoadTest, badParameterLoad) {
    // Set proc name.
    Daemon::setProcName("kea-ctrl-agent");

    /// Add unknown element "foo" to valid config.
    ElementPtr cfg = createValidJsonConfiguration();
    cfg->set("preference", Element::create("foo"));

    // Add library with invalid configuration.
    addLib(RBAC_LIB_SO, cfg);

    // The load should fail.
    EXPECT_FALSE(loadLibs());
}

// Verifies that the library can not be loaded in a DHCPv4 server.
TEST_F(LibLoadTest, badDhcpv4) {
    // Set proc name.
    Daemon::setProcName("kea-dhcp4");

    // Add library with valid configuration.
    addLib(RBAC_LIB_SO, createValidJsonConfiguration());

    // The load should fail.
    EXPECT_FALSE(loadLibs());
}

// Verifies that the library can not be loaded in a DHCPv6 server.
TEST_F(LibLoadTest, badDhcpv6) {
    // Set proc name.
    Daemon::setProcName("kea-dhcp6");

    // Add library with valid configuration.
    addLib(RBAC_LIB_SO, createValidJsonConfiguration());

    // The load should fail.
    EXPECT_FALSE(loadLibs());
}

} // end of anonymous namespace
