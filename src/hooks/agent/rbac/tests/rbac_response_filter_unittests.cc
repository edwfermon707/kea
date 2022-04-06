// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <cc/command_interpreter.h>
#include <testutils/gtest_utils.h>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::rbac;
using namespace std;

namespace {

/// @brief Test fixture for check RBAC response filters.
class ResponseFilterTest : public ::testing::Test {
public:

    /// @brief Constructor.
    ResponseFilterTest() {
        responseFilterTable.clear();
        ResponseFilter::initResponseFilterTable();
    }

    /// @brief Destructor.
    virtual ~ResponseFilterTest() {
        responseFilterTable.clear();
    }
};

/// @brief This test verifies that the table works as expected.
TEST_F(ResponseFilterTest, table) {
    EXPECT_EQ(2, responseFilterTable.size());
}

/// @brief This test verifies that noop response filter works as expected.
TEST_F(ResponseFilterTest, noop) {
    RoleConfigPtr rc(new RoleConfig("my-role", AclPtr(), AclPtr(),
                                    true, true, ResponseFilterList()));
    ASSERT_TRUE(rc);
    ResponseFilterPtr rf(new NoopResponseFilter);
    ASSERT_TRUE(rf);
    EXPECT_EQ("noop", rf->getName());
    EXPECT_FALSE(rf->filter("foo", *rc, ConstElementPtr()));

    // Get the noop response filter from the table.
    rf = responseFilterTable["noop"];
    ASSERT_TRUE(rf);
    EXPECT_EQ("noop", rf->getName());
    EXPECT_FALSE(rf->filter("bar", *rc, ConstElementPtr()));
}

/// @brief This test verifies that list-commands response filter works
/// as expected.
TEST_F(ResponseFilterTest, listCommands) {
    // Response filter
    ResponseFilterPtr rf(new ListCommandsResponseFilter);
    ASSERT_TRUE(rf);
    EXPECT_EQ("list-commands", rf->getName());
    ResponseFilterList rfl;
    rfl.push_back(rf);

    // Get it from the table too.
    ResponseFilterPtr got = responseFilterTable["list-commands"];
    ASSERT_TRUE(got);
    EXPECT_EQ("list-commands", got->getName());

    // Role config.
    set<string> commands = { "foo", "bar", "xyz" };
    AclPtr accept(new CommandsAcl(commands));
    RoleConfigPtr rc(new RoleConfig("my-role", accept, AclPtr(),
                                    false, true, rfl));
    ASSERT_TRUE(rc);

    // Build a list-commands answer.
    ElementPtr answer = Element::createMap();
    ElementPtr result = Element::create(CONTROL_RESULT_SUCCESS);
    answer->set(CONTROL_RESULT, result);
    ElementPtr args = Element::createList();
    answer->set(CONTROL_ARGUMENTS, args);
    args->add(Element::create(string("list-commands")));
    args->add(Element::create(string("foo")));
    args->add(Element::create(string("bar")));
    ConstElementPtr expected = data::copy(answer);
    args->add(Element::create(string("abc")));
    args->add(Element::create(string("def")));
    ConstElementPtr answer1 = data::copy(answer);

    // Tests.
    EXPECT_FALSE(rf->filter("foo", *rc, ConstElementPtr()));
    EXPECT_FALSE(rf->filter("foo", *rc, Element::createList()));
    string arguments = "{ \"foo\": \"bar\" }";
    EXPECT_FALSE(rf->filter("foo", *rc, Element::fromJSON(arguments)));
}

} // end of anonymous namespace
