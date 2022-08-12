// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

/// @file This file contains tests which verify pre processing.

#include <config.h>
#include <pre_process.h>
#include <pre_process_log.h>
#include <dhcp/option_custom.h>
#include <dhcp/option_string.h>
#include <dhcp/libdhcp++.h>
#include <dhcpsrv/cfgmgr.h>
#include <eval/eval_context.h>
#include <hooks/callout_manager.h>
#include <hooks/hooks.h>

#include <tests/test_pre_process.h>
#include <gtest/gtest.h>
#include <sstream>

using namespace std;
using namespace isc;
using namespace isc::data;
using namespace isc::dhcp;
using namespace isc::eval;
using namespace isc::hooks;
using namespace isc::pre_process;
using namespace isc::pre_process::test;

namespace {

/// @brief Test fixture for testing the Pre Process library.
class PreProcessTest : public BasePreProcessTest { };

// Verify that the configuration must exist.
TEST_F(PreProcessTest, noConfig) {
    ElementPtr options;
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'options' parameter is mandatory", impl_->getErrMsg());
}

// Verify that the configuration must be a list.
TEST_F(PreProcessTest, configNotList) {
    ElementPtr options = Element::createMap();
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'options' parameter must be a list", impl_->getErrMsg());
}

// Verify that the configuration can be the empty list.
TEST_F(PreProcessTest, configEmpty) {
    ElementPtr options = Element::createList();
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    EXPECT_TRUE(impl_->getOptionConfigMap().empty());
}

// Verify that an option configuration must exist.
TEST_F(PreProcessTest, noOptionConfig) {
    ElementPtr options = Element::createList();
    ElementPtr option;
    options->add(option);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("null option element", impl_->getErrMsg());
}

// Verify that an option configuration must be a map.
TEST_F(PreProcessTest, optionConfigNotMap) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createList();
    options->add(option);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("option element is not a map", impl_->getErrMsg());
}

// Verify that an unknown option keyword is rejected.
TEST_F(PreProcessTest, optionConfigUnknown) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr unknown = Element::create(string("'ab'"));
    // The right keyword is remove...
    option->set("delete", unknown);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("unknown parameter 'delete'", impl_->getErrMsg());
}

// Verify that an option configuration must have code or name.
TEST_F(PreProcessTest, optionConfigNoCodeName) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    ostringstream errmsg;
    errmsg << "'code' or 'name' must be specified: " << option->str();
    EXPECT_EQ(errmsg.str(), impl_->getErrMsg());
}

// Verify that the v4 option code must be in [1..254].
TEST_F(PreProcessTest, optionConfigBadCode4) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(false);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'code' must be an integer: false", impl_->getErrMsg());

    code = Element::create(-1);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), OutOfRange);
    EXPECT_EQ("invalid 'code' value -1 not in [0..255]", impl_->getErrMsg());

    code = Element::create(DHO_PAD);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("invalid 'code' value 0: reserved for PAD", impl_->getErrMsg());

    code = Element::create(DHO_END);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("invalid 'code' value 255: reserved for END", impl_->getErrMsg());

    code = Element::create(256);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), OutOfRange);
    EXPECT_EQ("invalid 'code' value 256 not in [0..255]", impl_->getErrMsg());

    code = Element::create(1);
    option->set("code", code);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    code = Element::create(254);
    option->set("code", code);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();
}

// Verify that the v6 option code must be in [1..65535].
TEST_F(PreProcessTest, optionConfigBadCode6) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(false);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'code' must be an integer: false", impl_->getErrMsg());

    code = Element::create(-1);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), OutOfRange);
    EXPECT_EQ("invalid 'code' value -1 not in [0..65535]", impl_->getErrMsg());

    code = Element::create(0);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("invalid 'code' value 0: reserved", impl_->getErrMsg());

    code = Element::create(65536);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), OutOfRange);
    EXPECT_EQ("invalid 'code' value 65536 not in [0..65535]", impl_->getErrMsg());

    code = Element::create(1);
    option->set("code", code);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    code = Element::create(65535);
    option->set("code", code);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();
}

// Verify that the space must be a string.
TEST_F(PreProcessTest, optionConfigBadSpace) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(222);
    option->set("code", code);
    ElementPtr space = Element::create(true);
    option->set("space", space);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'space' must be a string: true", impl_->getErrMsg());
}

// Verify that the space must be valid.
TEST_F(PreProcessTest, optionConfigInvalidSpace) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(222);
    option->set("code", code);
    ElementPtr space = Element::create(string("-bad-"));
    option->set("space", space);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'-bad-' is not a valid space name", impl_->getErrMsg());
}

// Verify that the name must be a string.
TEST_F(PreProcessTest, optionConfigBadName) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(true);
    option->set("name", name);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'name' must be a string: true", impl_->getErrMsg());
}

// Verify that the name must not be empty.
TEST_F(PreProcessTest, optionConfigEmptyName) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(string());
    option->set("name", name);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'name' must not be empty", impl_->getErrMsg());
}

// Verify that the name must be a known option.
TEST_F(PreProcessTest, optionConfigUnknownName) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(string("foobar"));
    option->set("name", name);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("no known 'foobar' option in 'dhcp4' space", impl_->getErrMsg());
}

// Verify that the space must be a known space.
TEST_F(PreProcessTest, optionConfigUnknownSpace) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(string("host-name"));
    option->set("name", name);
    ElementPtr space = Element::create(string("foobar"));
    option->set("space", space);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("no known 'host-name' option in 'foobar' space",
              impl_->getErrMsg());
}

// Verify that the definition is not required when csv-format is not specified.
TEST_F(PreProcessTest, optionConfigUnknownCodeNoCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(109);
    option->set("code", code);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(1, map.count(109));
    auto opt_lst = map[109];
    EXPECT_EQ(1, opt_lst.size());
}

// Verify that the definition is not required when csv-format is false.
TEST_F(PreProcessTest, optionConfigUnknownCodeDisableCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(109);
    option->set("code", code);
    // Disable csv-format.
    option->set("csv-format", Element::create(false));
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(1, map.count(109));
    auto opt_lst = map[109];
    EXPECT_EQ(1, opt_lst.size());
}

// Verify that the code must be a known option when csv-format is true.
TEST_F(PreProcessTest, optionConfigUnknownCodeEnableCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(109);
    option->set("code", code);
    // Enable csv-format.
    option->set("csv-format", Element::create(true));
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("no known option with code '109' in 'dhcp4' space", impl_->getErrMsg());
}

// Verify that the name can be a standard option.
TEST_F(PreProcessTest, optionConfigStandardName) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(string("host-name"));
    option->set("name", name);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(1, map.count(DHO_HOST_NAME));
    auto opt_lst = map[DHO_HOST_NAME];
    EXPECT_EQ(1, opt_lst.size());
}

// Verify that the name can be an user defined option.
TEST_F(PreProcessTest, optionConfigDefinedName) {
    OptionDefSpaceContainer defs;
    OptionDefinitionPtr def(new OptionDefinition("my-option", 222,
                                                 DHCP4_OPTION_SPACE, "string"));
    defs.addItem(def);
    EXPECT_NO_THROW(LibDHCP::setRuntimeOptionDefs(defs));

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(string("my-option"));
    option->set("name", name);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(1, map.count(222));
    auto opt_lst = map[222];
    EXPECT_EQ(1, opt_lst.size());
}

// Verify that the name can be an user defined option in a custom space.
TEST_F(PreProcessTest, optionConfigDefinedSpace) {
    OptionDefSpaceContainer defs;
    OptionDefinitionPtr def(new OptionDefinition("my-option", 222,
                                                 "my-space", "string"));
    defs.addItem(def);
    EXPECT_NO_THROW(LibDHCP::setRuntimeOptionDefs(defs));

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr name = Element::create(string("my-option"));
    option->set("name", name);
    ElementPtr space = Element::create(string("my-space"));
    option->set("space", space);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(1, map.count(222));
    auto opt_lst = map[222];
    EXPECT_EQ(1, opt_lst.size());
}

// Last resort is only option 43...

// Verify that the name must match the code.
TEST_F(PreProcessTest, optionConfigCodeNameMismatch) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(DHO_HOST_NAME + 1);
    option->set("code", code);
    ElementPtr name = Element::create(string("host-name"));
    option->set("name", name);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    string expected = "option 'host-name' is defined as code: 12, ";
    expected += "not the specified code: 13";
    EXPECT_EQ(expected, impl_->getErrMsg());
}

// Verify that the csv-format must be a boolean.
TEST_F(PreProcessTest, optionConfigBadCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr csv_format = Element::create(123);
    option->set("csv-format", csv_format);
    ElementPtr code = Element::create(12);
    option->set("code", code);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'csv-format' must be a boolean: 123", impl_->getErrMsg());
}

// Verify that an option can be configured more than once.
TEST_F(PreProcessTest, optionConfigTwice) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr add = Element::create(string("'ab'"));
    option->set("add", add);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);

    // Add it a second time.
    options->add(option);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(1, map.count(DHO_HOST_NAME));
    auto opt_lst = map[DHO_HOST_NAME];
    EXPECT_EQ(2, opt_lst.size());
}

// Verify that the add value must be a string.
TEST_F(PreProcessTest, optionConfigAddNotString) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(true);
    option->set("add", add);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'add' must be a string: true", impl_->getErrMsg());
}

// Verify that the add value must not be empty.
TEST_F(PreProcessTest, optionConfigEmptyAdd) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(string());
    option->set("add", add);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'add' must not be empty", impl_->getErrMsg());
}

// Verify that the add value must parse.
TEST_F(PreProcessTest, optionConfigBadAdd) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(string("ifelse('a','b','c')"));
    option->set("add", add);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    string expected = "can't parse add expression [ifelse('a','b','c')] ";
    expected += "error: <string>:1.11: syntax error, ";
    expected += "unexpected \",\", expecting == or +";
    EXPECT_EQ(expected, impl_->getErrMsg());
}

// Verify that a valid v4 add value is accepted.
TEST_F(PreProcessTest, optionConfigAdd4) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(string("'abc'"));
    option->set("add", add);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    PreProcessImpl::OptionConfigList opt_lst;
    ASSERT_NO_THROW(opt_lst = map.at(DHO_HOST_NAME));
    ASSERT_FALSE(opt_lst.empty());
    EXPECT_EQ(1, opt_lst.size());
    PreProcessImpl::OptionConfigPtr opt_cfg;
    ASSERT_NO_THROW(opt_cfg = opt_lst.front());

    ASSERT_TRUE(opt_cfg);
    EXPECT_EQ(DHO_HOST_NAME, opt_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::ADD, opt_cfg->getAction());
    EXPECT_EQ("'abc'", opt_cfg->getText());

    ExpressionPtr expr = opt_cfg->getExpr();
    ASSERT_TRUE(expr);
    ASSERT_EQ(1, expr->size());
    Pkt4Ptr pkt4(new Pkt4(DHCPDISCOVER, 12345));
    ValueStack values;
    EXPECT_NO_THROW(expr->at(0)->evaluate(*pkt4, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("abc", values.top());
}

// Verify that a valid v6 add value is accepted.
TEST_F(PreProcessTest, optionConfigAdd6) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr add = Element::create(string("'abc'"));
    option->set("add", add);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    PreProcessImpl::OptionConfigList opt_lst;
    ASSERT_NO_THROW(opt_lst = map.at(D6O_BOOTFILE_URL));
    ASSERT_FALSE(opt_lst.empty());
    EXPECT_EQ(1, opt_lst.size());
    PreProcessImpl::OptionConfigPtr opt_cfg;
    ASSERT_NO_THROW(opt_cfg = opt_lst.front());

    ASSERT_TRUE(opt_cfg);
    EXPECT_EQ(D6O_BOOTFILE_URL, opt_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::ADD, opt_cfg->getAction());
    EXPECT_EQ("'abc'", opt_cfg->getText());

    ExpressionPtr expr = opt_cfg->getExpr();
    ASSERT_TRUE(expr);
    ASSERT_EQ(1, expr->size());
    Pkt6Ptr pkt6(new Pkt6(DHCPV6_SOLICIT, 12345));
    ValueStack values;
    EXPECT_NO_THROW(expr->at(0)->evaluate(*pkt6, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("abc", values.top());
}

// Verify that the supersede value must be a string.
TEST_F(PreProcessTest, optionConfigSupersedeNotString) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(123);
    option->set("supersede", supersede);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'supersede' must be a string: 123", impl_->getErrMsg());
}

// Verify that the supersede value must not be empty.
TEST_F(PreProcessTest, optionConfigEmptySupersede) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(string());
    option->set("supersede", supersede);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'supersede' must not be empty", impl_->getErrMsg());
}

// Verify that the supersede value must parse.
TEST_F(PreProcessTest, optionConfigBadSupersede) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("ifelse('a','b','c')"));
    option->set("supersede", supersede);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    string expected = "can't parse supersede expression [ifelse('a','b','c')] ";
    expected += "error: <string>:1.11: syntax error, ";
    expected += "unexpected \",\", expecting == or +";
    EXPECT_EQ(expected, impl_->getErrMsg());
}

// Verify that a valid v4 supersede value is accepted.
TEST_F(PreProcessTest, optionConfigSupersede4) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("'abc'"));
    option->set("supersede", supersede);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    PreProcessImpl::OptionConfigList opt_lst;
    ASSERT_NO_THROW(opt_lst = map.at(DHO_HOST_NAME));
    ASSERT_FALSE(opt_lst.empty());
    EXPECT_EQ(1, opt_lst.size());
    PreProcessImpl::OptionConfigPtr opt_cfg;
    ASSERT_NO_THROW(opt_cfg = opt_lst.front());

    ASSERT_TRUE(opt_cfg);
    EXPECT_EQ(DHO_HOST_NAME, opt_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::SUPERSEDE, opt_cfg->getAction());
    EXPECT_EQ("'abc'", opt_cfg->getText());

    ExpressionPtr expr = opt_cfg->getExpr();
    ASSERT_TRUE(expr);
    ASSERT_EQ(1, expr->size());
    Pkt4Ptr pkt4(new Pkt4(DHCPDISCOVER, 12345));
    ValueStack values;
    EXPECT_NO_THROW(expr->at(0)->evaluate(*pkt4, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("abc", values.top());
}

// Verify that a valid v6 supersede value is accepted.
TEST_F(PreProcessTest, optionConfigSupersede6) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("'abc'"));
    option->set("supersede", supersede);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    PreProcessImpl::OptionConfigList opt_lst;
    ASSERT_NO_THROW(opt_lst = map.at(D6O_BOOTFILE_URL));
    ASSERT_FALSE(opt_lst.empty());
    EXPECT_EQ(1, opt_lst.size());
    PreProcessImpl::OptionConfigPtr opt_cfg;
    ASSERT_NO_THROW(opt_cfg = opt_lst.front());

    ASSERT_TRUE(opt_cfg);
    EXPECT_EQ(D6O_BOOTFILE_URL, opt_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::SUPERSEDE, opt_cfg->getAction());
    EXPECT_EQ("'abc'", opt_cfg->getText());

    ExpressionPtr expr = opt_cfg->getExpr();
    ASSERT_TRUE(expr);
    ASSERT_EQ(1, expr->size());
    Pkt6Ptr pkt6(new Pkt6(DHCPV6_SOLICIT, 12345));
    ValueStack values;
    EXPECT_NO_THROW(expr->at(0)->evaluate(*pkt6, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("abc", values.top());
}

// Verify that the remove value must be a string.
TEST_F(PreProcessTest, optionConfigRemoveNotString) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr remove = Element::createMap();
    option->set("remove", remove);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'remove' must be a string: {  }", impl_->getErrMsg());
}

// Verify that the remove value must not be empty.
TEST_F(PreProcessTest, optionConfigEmptyRemove) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr remove = Element::create(string());
    option->set("remove", remove);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    EXPECT_EQ("'remove' must not be empty", impl_->getErrMsg());
}

// Verify that the remove value must parse.
TEST_F(PreProcessTest, optionConfigBadRemove) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr remove = Element::create(string("'abc'"));
    option->set("remove", remove);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    string expected = "can't parse remove expression ['abc'] error: ";
    expected += "<string>:1.6: syntax error, unexpected end of file, ";
    expected += "expecting == or +";
    EXPECT_EQ(expected, impl_->getErrMsg());
}

// Verify that a valid v4 remove value is accepted.
TEST_F(PreProcessTest, optionConfigRemove4) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr remove = Element::create(string("'abc' == 'abc'"));
    option->set("remove", remove);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    PreProcessImpl::OptionConfigList opt_lst;
    ASSERT_NO_THROW(opt_lst = map.at(DHO_HOST_NAME));
    ASSERT_FALSE(opt_lst.empty());
    EXPECT_EQ(1, opt_lst.size());
    PreProcessImpl::OptionConfigPtr opt_cfg;
    ASSERT_NO_THROW(opt_cfg = opt_lst.front());

    ASSERT_TRUE(opt_cfg);
    EXPECT_EQ(DHO_HOST_NAME, opt_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::REMOVE, opt_cfg->getAction());
    EXPECT_EQ("'abc' == 'abc'", opt_cfg->getText());

    ExpressionPtr expr = opt_cfg->getExpr();
    ASSERT_TRUE(expr);
    ASSERT_EQ(3, expr->size());
    Pkt4Ptr pkt4(new Pkt4(DHCPDISCOVER, 12345));
    ValueStack values;
    EXPECT_NO_THROW(expr->at(0)->evaluate(*pkt4, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("abc", values.top());
    EXPECT_NO_THROW(expr->at(1)->evaluate(*pkt4, values));
    ASSERT_EQ(2, values.size());
    EXPECT_NO_THROW(expr->at(2)->evaluate(*pkt4, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("true", values.top());
}

// Verify that a valid v6 remove value is accepted.
TEST_F(PreProcessTest, optionConfigRemove6) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr remove = Element::create(string("'abc' == 'abc'"));
    option->set("remove", remove);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    PreProcessImpl::OptionConfigList opt_lst;
    ASSERT_NO_THROW(opt_lst = map.at(D6O_BOOTFILE_URL));
    ASSERT_FALSE(opt_lst.empty());
    EXPECT_EQ(1, opt_lst.size());
    PreProcessImpl::OptionConfigPtr opt_cfg;
    ASSERT_NO_THROW(opt_cfg = opt_lst.front());

    ASSERT_TRUE(opt_cfg);
    EXPECT_EQ(D6O_BOOTFILE_URL, opt_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::REMOVE, opt_cfg->getAction());
    EXPECT_EQ("'abc' == 'abc'", opt_cfg->getText());

    ExpressionPtr expr = opt_cfg->getExpr();
    ASSERT_TRUE(expr);
    ASSERT_EQ(3, expr->size());
    Pkt6Ptr pkt6(new Pkt6(DHCPV6_SOLICIT, 12345));
    ValueStack values;
    EXPECT_NO_THROW(expr->at(0)->evaluate(*pkt6, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("abc", values.top());
    EXPECT_NO_THROW(expr->at(1)->evaluate(*pkt6, values));
    ASSERT_EQ(2, values.size());
    EXPECT_NO_THROW(expr->at(2)->evaluate(*pkt6, values));
    ASSERT_EQ(1, values.size());
    EXPECT_EQ("true", values.top());
}

// Verify that multiple actions are not accepted.
TEST_F(PreProcessTest, optionConfigMultipleAction) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);

    // add and supersede.
    ElementPtr add = Element::create(string("'abc'"));
    option->set("add", add);
    ElementPtr supersede = Element::create(string("'abc'"));
    option->set("supersede", supersede);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    ostringstream errmsg;
    errmsg << "multiple actions: " << option->str();
    EXPECT_EQ(errmsg.str(), impl_->getErrMsg());

    // supersede and remove.
    option->remove("add");
    ElementPtr remove = Element::create(string("'abc' == 'abc'"));
    option->set("remove", remove);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    errmsg.str("");
    errmsg << "multiple actions: " << option->str();
    EXPECT_EQ(errmsg.str(), impl_->getErrMsg());

    // add and remove.
    option->remove("supersede");
    option->set("add", add);
    EXPECT_THROW(impl_->testConfigure(options), BadValue);
    errmsg.str("");
    errmsg << "multiple actions: " << option->str();
    EXPECT_EQ(errmsg.str(), impl_->getErrMsg());
}

// Verify that multiple options are accepted.
TEST_F(PreProcessTest, optionConfigList) {
    ElementPtr options = Element::createList();

    ElementPtr option1 = Element::createMap();
    options->add(option1);
    ElementPtr code1 = Element::create(DHO_HOST_NAME);
    option1->set("code", code1);
    ElementPtr add1 = Element::create(string("'abc'"));
    option1->set("add", add1);

    ElementPtr option2 = Element::createMap();
    options->add(option2);
    ElementPtr code2 = Element::create(DHO_ROOT_PATH);
    option2->set("code", code2);
    ElementPtr supersede2 = Element::create(string("'/'"));
    option2->set("supersede", supersede2);

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    auto map = impl_->getOptionConfigMap();
    EXPECT_EQ(2, map.size());

    PreProcessImpl::OptionConfigList opt1_lst;
    ASSERT_NO_THROW(opt1_lst = map.at(DHO_HOST_NAME));
    ASSERT_FALSE(opt1_lst.empty());
    EXPECT_EQ(1, opt1_lst.size());
    PreProcessImpl::OptionConfigPtr opt1_cfg;
    ASSERT_NO_THROW(opt1_cfg = opt1_lst.front());

    ASSERT_TRUE(opt1_cfg);
    EXPECT_EQ(DHO_HOST_NAME, opt1_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::ADD, opt1_cfg->getAction());
    EXPECT_EQ("'abc'", opt1_cfg->getText());

    PreProcessImpl::OptionConfigList opt2_lst;
    ASSERT_NO_THROW(opt2_lst = map.at(DHO_ROOT_PATH));
    ASSERT_FALSE(opt2_lst.empty());
    EXPECT_EQ(1, opt2_lst.size());
    PreProcessImpl::OptionConfigPtr opt2_cfg;
    ASSERT_NO_THROW(opt2_cfg = opt2_lst.front());

    ASSERT_TRUE(opt2_cfg);
    EXPECT_EQ(DHO_ROOT_PATH, opt2_cfg->getCode());
    EXPECT_EQ(PreProcessImpl::SUPERSEDE, opt2_cfg->getAction());
    EXPECT_EQ("'/'", opt2_cfg->getText());
}

// Verify that empty option config list does nothing.
TEST_F(PreProcessTest, processEmpty) {
    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    string txt = query->toText();

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    EXPECT_EQ(txt, query->toText());
}

// Verify that NONE action really does nothing.
TEST_F(PreProcessTest, processNone) {
    CfgMgr::instance().setFamily(AF_INET6);

    OptionDefinitionPtr def = LibDHCP::getOptionDef(DHCP6_OPTION_SPACE, D6O_BOOTFILE_URL);
    PreProcessImpl::OptionConfigPtr
        opt_cfg(new PreProcessImpl::OptionConfig(D6O_BOOTFILE_URL, def));
    EXPECT_EQ(PreProcessImpl::NONE, opt_cfg->getAction());
    auto map = impl_->getMutableOptionConfigMap();
    auto& opt_lst = map[DHO_HOST_NAME];
    opt_lst.push_back(opt_cfg);

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    string txt = query->toText();

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    EXPECT_EQ(txt, query->toText());
}

// Verify that ADD action adds the specified option in csv format.
TEST_F(PreProcessTest, processAddEnableCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(string("'abc'"));
    option->set("add", add);

    option = Element::createMap();
    options->add(option);
    code = Element::create(DHO_DOMAIN_SEARCH);
    option->set("code", code);
    add = Element::create(string("'example.com'"));
    option->set("add", add);
    // fqdn option data is parsed using option definition in csv format.
    option->set("csv-format", Element::create(true));

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));
    EXPECT_FALSE(query->getOption(DHO_DOMAIN_SEARCH));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_HOST_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_HOST_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "abc", 3));

    opt = query->getOption(DHO_DOMAIN_SEARCH);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_DOMAIN_SEARCH, opt->getType());
    const OptionBuffer& buffer_fqdn = opt->getData();
    ASSERT_EQ(13, buffer_fqdn.size());
    EXPECT_EQ(7, buffer_fqdn[0]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[1], "example", 7));
    EXPECT_EQ(3, buffer_fqdn[8]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[9], "com", 3));
    EXPECT_EQ(0, buffer_fqdn[12]);
}

// Verify that ADD action adds the specified option in raw format.
TEST_F(PreProcessTest, processAddDisableCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(string("'abc'"));
    option->set("add", add);

    option = Element::createMap();
    options->add(option);
    code = Element::create(DHO_DOMAIN_SEARCH);
    option->set("code", code);
    add = Element::create(string("0x076578616d706c6503636f6d00"));
    option->set("add", add);
    // fqdn option data is specified in raw format.
    option->set("csv-format", Element::create(false));

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));
    EXPECT_FALSE(query->getOption(DHO_DOMAIN_SEARCH));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_HOST_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_HOST_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "abc", 3));

    opt = query->getOption(DHO_DOMAIN_SEARCH);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_DOMAIN_SEARCH, opt->getType());
    const OptionBuffer& buffer_fqdn = opt->getData();
    ASSERT_EQ(13, buffer_fqdn.size());
    EXPECT_EQ(7, buffer_fqdn[0]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[1], "example", 7));
    EXPECT_EQ(3, buffer_fqdn[8]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[9], "com", 3));
    EXPECT_EQ(0, buffer_fqdn[12]);
}

// Verify that ADD action does not add an already existing option.
TEST_F(PreProcessTest, processAddExisting) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr add = Element::create(string("'abc'"));
    option->set("add", add);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    OptionStringPtr str(new OptionString(Option::V6, D6O_BOOTFILE_URL, "http"));
    query->addOption(str);

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    OptionPtr opt = query->getOption(D6O_BOOTFILE_URL);
    ASSERT_TRUE(opt);
    EXPECT_EQ(D6O_BOOTFILE_URL, opt->getType());
    EXPECT_EQ("http", opt->toString());
}

// Verify that ADD action does not add an empty value.
TEST_F(PreProcessTest, processAddEmpty) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr add = Element::create(string("''"));
    option->set("add", add);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    string txt = query->toText();
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    EXPECT_EQ(txt, query->toText());
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));
}

// Verify that SUPERSEDE action supersedes the specified option in csv format.
TEST_F(PreProcessTest, processSupersedeEnableCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("'abc'"));
    option->set("supersede", supersede);

    option = Element::createMap();
    options->add(option);
    code = Element::create(DHO_DOMAIN_SEARCH);
    option->set("code", code);
    supersede = Element::create(string("'example.com'"));
    option->set("supersede", supersede);
    // fqdn option data is parsed using option definition in csv format.
    option->set("csv-format", Element::create(true));

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));
    EXPECT_FALSE(query->getOption(DHO_DOMAIN_SEARCH));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_HOST_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_HOST_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "abc", 3));

    opt = query->getOption(DHO_DOMAIN_SEARCH);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_DOMAIN_SEARCH, opt->getType());
    const OptionBuffer& buffer_fqdn = opt->getData();
    ASSERT_EQ(13, buffer_fqdn.size());
    EXPECT_EQ(7, buffer_fqdn[0]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[1], "example", 7));
    EXPECT_EQ(3, buffer_fqdn[8]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[9], "com", 3));
    EXPECT_EQ(0, buffer_fqdn[12]);
}

// Verify that SUPERSEDE action supersedes the specified option in raw format.
TEST_F(PreProcessTest, processSupersedeDisableCSVFormat) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("'abc'"));
    option->set("supersede", supersede);

    option = Element::createMap();
    options->add(option);
    code = Element::create(DHO_DOMAIN_SEARCH);
    option->set("code", code);
    supersede = Element::create(string("0x076578616d706c6503636f6d00"));
    option->set("supersede", supersede);
    // fqdn option data is specified in raw format.
    option->set("csv-format", Element::create(false));

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));
    EXPECT_FALSE(query->getOption(DHO_DOMAIN_SEARCH));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_HOST_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_HOST_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "abc", 3));

    opt = query->getOption(DHO_DOMAIN_SEARCH);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_DOMAIN_SEARCH, opt->getType());
    const OptionBuffer& buffer_fqdn = opt->getData();
    ASSERT_EQ(13, buffer_fqdn.size());
    EXPECT_EQ(7, buffer_fqdn[0]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[1], "example", 7));
    EXPECT_EQ(3, buffer_fqdn[8]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[9], "com", 3));
    EXPECT_EQ(0, buffer_fqdn[12]);
}

// Verify that SUPERSEDE action supersedes an already existing option.
TEST_F(PreProcessTest, processSupersedeExisting) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("0xabcdef"));
    option->set("supersede", supersede);

    option = Element::createMap();
    options->add(option);
    code = Element::create(D6O_DOMAIN_SEARCH);
    option->set("code", code);
    supersede = Element::create(string("'example.com'"));
    option->set("supersede", supersede);
    // fqdn option data is parsed using option definition in csv format.
    option->set("csv-format", Element::create(true));

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    OptionStringPtr str(new OptionString(Option::V6, D6O_BOOTFILE_URL, "http"));
    query->addOption(str);
    OptionDefinition def("domain-name", D6O_DOMAIN_SEARCH, DHCP6_OPTION_SPACE,
                         OPT_FQDN_TYPE);
    OptionCustomPtr option_domain_name(new OptionCustom(def, Option::V6));
    option_domain_name->writeFqdn("old.example.com");
    query->addOption(option_domain_name);

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    OptionPtr opt = query->getOption(D6O_BOOTFILE_URL);
    ASSERT_TRUE(opt);
    EXPECT_EQ(D6O_BOOTFILE_URL, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    uint8_t expected[] = { 0xab, 0xcd, 0xef };
    EXPECT_EQ(0, memcmp(&buffer[0], expected, 3));

    opt = query->getOption(D6O_DOMAIN_SEARCH);
    ASSERT_TRUE(opt);
    EXPECT_EQ(D6O_DOMAIN_SEARCH, opt->getType());
    const OptionBuffer& buffer_fqdn = opt->getData();
    ASSERT_EQ(13, buffer_fqdn.size());
    EXPECT_EQ(7, buffer_fqdn[0]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[1], "example", 7));
    EXPECT_EQ(3, buffer_fqdn[8]);
    EXPECT_EQ(0, memcmp(&buffer_fqdn[9], "com", 3));
    EXPECT_EQ(0, buffer_fqdn[12]);
}

// Verify that SUPERSEDE action does not supersede an empty value.
TEST_F(PreProcessTest, processSupersedeEmpty) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr supersede = Element::create(string("''"));
    option->set("supersede", supersede);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    string txt = query->toText();
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    EXPECT_EQ(txt, query->toText());
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));

    // Empty value does not remove existing values.
    OptionStringPtr str(new OptionString(Option::V4, DHO_HOST_NAME, "abc"));
    query->addOption(str);

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_HOST_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_HOST_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "abc", 3));
}

// Verify that SUPERSEDE if exists + ADD adds a not yet existing option.
TEST_F(PreProcessTest, processSupersedeAddNotExisting) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option1 = Element::createMap();
    options->add(option1);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option1->set("code", code);
    string action = "ifelse(option[bootfile-url].exists,'supersede','')";
    ElementPtr supersede = Element::create(action);
    option1->set("supersede", supersede);
    ElementPtr option2 = Element::createMap();
    options->add(option2);
    option2->set("code", code);
    ElementPtr add = Element::create(string("'add'"));
    option2->set("add", add);

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    EXPECT_FALSE(query->getOption(D6O_BOOTFILE_URL));

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    OptionPtr opt = query->getOption(D6O_BOOTFILE_URL);
    ASSERT_TRUE(opt);
    EXPECT_EQ(D6O_BOOTFILE_URL, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(3, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "add", 3));
}

// Verify that SUPERSEDE if exists + ADD supersedes an existing option.
TEST_F(PreProcessTest, processSupersedeAddExisting) {
    ElementPtr options = Element::createList();
    ElementPtr option1 = Element::createMap();
    options->add(option1);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option1->set("code", code);
    string action = "ifelse(option[host-name].exists,'supersede','')";
    ElementPtr supersede = Element::create(action);
    option1->set("supersede", supersede);
    ElementPtr option2 = Element::createMap();
    options->add(option2);
    option2->set("code", code);
    ElementPtr add = Element::create(string("'add'"));
    option2->set("add", add);

    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    OptionStringPtr str(new OptionString(Option::V4, DHO_HOST_NAME, "foobar"));
    query->addOption(str);

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_HOST_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_HOST_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(9, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "supersede", 9));
}

// Verify that REMOVE action removes an already existing option.
TEST_F(PreProcessTest, processRemove) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr remove = Element::create(string("'abc' == 'abc'"));
    option->set("remove", remove);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    OptionStringPtr str(new OptionString(Option::V6, D6O_BOOTFILE_URL, "http"));
    query->addOption(str);

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    EXPECT_FALSE(query->getOption(D6O_BOOTFILE_URL));
}

// Verify that REMOVE action does nothing if the option is not present.
TEST_F(PreProcessTest, processRemoveNoOption) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_HOST_NAME);
    option->set("code", code);
    ElementPtr remove = Element::create(string("'abc' == 'abc'"));
    option->set("remove", remove);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    string txt = query->toText();
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    EXPECT_EQ(txt, query->toText());
    EXPECT_FALSE(query->getOption(DHO_HOST_NAME));
}

// Verify that REMOVE action does nothing when the expression evaluates to false.
TEST_F(PreProcessTest, processRemoveFalse) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_BOOTFILE_URL);
    option->set("code", code);
    ElementPtr remove = Element::create(string("'abc' == 'xyz'"));
    option->set("remove", remove);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    OptionStringPtr str(new OptionString(Option::V6, D6O_BOOTFILE_URL, "http"));
    query->addOption(str);
    string txt = query->toText();

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    EXPECT_EQ(txt, query->toText());
    EXPECT_TRUE(query->getOption(D6O_BOOTFILE_URL));
}

// A more complex check...
TEST_F(PreProcessTest, processFullTest) {
    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(DHO_BOOT_FILE_NAME);
    option->set("code", code);
    string expr = "ifelse(option[host-name].exists,";
    expr += "concat(option[host-name].text,'.boot'),'')";
    ElementPtr add = Element::create(expr);
    option->set("add", add);
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt4Ptr query(new Pkt4(DHCPDISCOVER, 12345));
    OptionStringPtr str(new OptionString(Option::V4, DHO_HOST_NAME, "foo"));
    query->addOption(str);
    EXPECT_FALSE(query->getOption(DHO_BOOT_FILE_NAME));

    EXPECT_NO_THROW(impl_->process<Pkt4Ptr>(Option::V4, query));

    OptionPtr opt = query->getOption(DHO_BOOT_FILE_NAME);
    ASSERT_TRUE(opt);
    EXPECT_EQ(DHO_BOOT_FILE_NAME, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    ASSERT_EQ(8, buffer.size());
    EXPECT_EQ(0, memcmp(&buffer[0], "foo.boot", 8));
}

// Verify that complex strings with escaped characters are properly parsed on add.
TEST_F(PreProcessTest, processFullAddWithComplexString) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_NEW_POSIX_TIMEZONE);
    option->set("code", code);
    string expr = "ifelse(option[39].exists,'EST5EDT4\\,M3.2.0/02:00\\,M11.1.0/02:00','')";
    ElementPtr add = Element::create(expr);
    option->set("add", add);
    // strings with escape characters are parsed in csv format.
    option->set("csv-format", Element::create(true));
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    OptionDefinitionPtr def = isc::dhcp::LibDHCP::getOptionDef(DHCP6_OPTION_SPACE, D6O_CLIENT_FQDN);
    OptionCustomPtr str(new OptionCustom(*def, Option::V6));
    query->addOption(str);
    EXPECT_FALSE(query->getOption(D6O_NEW_POSIX_TIMEZONE));

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    OptionPtr opt = query->getOption(D6O_NEW_POSIX_TIMEZONE);
    ASSERT_TRUE(opt);
    EXPECT_EQ(D6O_NEW_POSIX_TIMEZONE, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    EXPECT_EQ(35, buffer.size());
    std::string data("EST5EDT4,M3.2.0/02:00,M11.1.0/02:00");
    EXPECT_EQ(0, memcmp(&buffer[0], &data[0], buffer.size()));
}

// Verify that complex strings with escaped characters are properly parsed on supersede.
TEST_F(PreProcessTest, processFullSupersedeWithComplexString) {
    CfgMgr::instance().setFamily(AF_INET6);

    ElementPtr options = Element::createList();
    ElementPtr option = Element::createMap();
    options->add(option);
    ElementPtr code = Element::create(D6O_NEW_POSIX_TIMEZONE);
    option->set("code", code);
    string expr = "ifelse(option[39].exists,'EST5EDT4\\,M3.2.0/02:00\\,M11.1.0/02:00','')";
    ElementPtr supersede = Element::create(expr);
    option->set("supersede", supersede);
    // strings with escape characters are parsed in csv format.
    option->set("csv-format", Element::create(true));
    EXPECT_NO_THROW(impl_->testConfigure(options));
    EXPECT_TRUE(impl_->getErrMsg().empty()) << impl_->getErrMsg();

    Pkt6Ptr query(new Pkt6(DHCPV6_SOLICIT, 12345));
    OptionDefinitionPtr def = isc::dhcp::LibDHCP::getOptionDef(DHCP6_OPTION_SPACE, D6O_CLIENT_FQDN);
    OptionCustomPtr str(new OptionCustom(*def, Option::V6));
    query->addOption(str);
    EXPECT_FALSE(query->getOption(D6O_NEW_POSIX_TIMEZONE));

    EXPECT_NO_THROW(impl_->process<Pkt6Ptr>(Option::V6, query));

    OptionPtr opt = query->getOption(D6O_NEW_POSIX_TIMEZONE);
    ASSERT_TRUE(opt);
    EXPECT_EQ(D6O_NEW_POSIX_TIMEZONE, opt->getType());
    const OptionBuffer& buffer = opt->getData();
    EXPECT_EQ(35, buffer.size());
    std::string data("EST5EDT4,M3.2.0/02:00,M11.1.0/02:00");
    EXPECT_EQ(0, memcmp(&buffer[0], &data[0], buffer.size()));
}

} // end of anonymous namespace
