// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @file This file contains common part of pre processing tests.

#ifndef TEST_PRE_PROCESS_H
#define TEST_PRE_PROCESS_H

#include <pre_process.h>
#include <dhcp/libdhcp++.h>
#include <dhcpsrv/cfgmgr.h>
#include <gtest/gtest.h>

namespace isc {
namespace pre_process {
namespace test {

/// @brief Test class derived from PreProcessImpl
class TestPreProcessImpl : public PreProcessImpl {
public:
    /// Export getMutableOptionConfigMap.
    using PreProcessImpl::getMutableOptionConfigMap;

    /// Export getMutableSubOptionConfigMap.
    using PreProcessImpl::getMutableSubOptionConfigMap;

    /// @Brief Configure clone which records the error.
    ///
    /// @param options The element with option config list.
    void testConfigure(isc::data::ConstElementPtr options) {
        err_msg_.clear();
        try {
            configure(options);
        } catch (const std::exception& ex) {
            err_msg_ = std::string(ex.what());
            throw;
        }
    }

    /// @brief Get the last error message.
    ///
    /// @return The last error message.
    const std::string& getErrMsg() const {
        return (err_msg_);
    }

private:
    /// @brief Last error message.
    std::string err_msg_;
};

/// @brief The type of shared pointers to TestPreProcessImpl
typedef boost::shared_ptr<TestPreProcessImpl> TestPreProcessImplPtr;

/// @brief Base test fixture for testing the Pre Process library.
class BasePreProcessTest : public ::testing::Test {
public:
    /// @brief Constructor.
    BasePreProcessTest() {
        impl_.reset(new TestPreProcessImpl());
        isc::dhcp::CfgMgr::instance().setFamily(AF_INET);
    }

    /// @brief Destructor.
    virtual ~BasePreProcessTest() {
        LibDHCP::clearRuntimeOptionDefs();
        isc::dhcp::CfgMgr::instance().setFamily(AF_INET);
        impl_.reset();
    }

    /// @brief Pre Process implementation.
    TestPreProcessImplPtr impl_;
};

} // end of namespace test
} // end of namespace pre_process
} // end of namespace isc

#endif // TEST_PRE_PROCESS_H
