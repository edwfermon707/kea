// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_config.h>
#include <cc/command_interpreter.h>
#include <hooks/callout_manager.h>
#include <hooks/hooks.h>
#include <http/post_request_json.h>
#include <http/response_json.h>
#include <testutils/gtest_utils.h>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::http;
using namespace isc::rbac;
using namespace std;

/// @brief Declarations of callout points.
extern "C" {
    extern int auth(CalloutHandle& handle);
    extern int response(CalloutHandle& handle);
}

namespace {

/// @brief RBAC configurations.
const char* CONFIGS[] = {
    // configuration 0: remote address, accept only list-commands on 127.0.0.1.
    "{\n"
    "    \"assign-role-method\": \"remote-address\",\n"
    "    \"roles\":\n"
    "    [\n"
    "        {\n"
    "            \"name\": \"127.0.0.1\",\n"
    "            \"accept-commands\":\n"
    "            {\n"
    "                \"commands\":\n"
    "                [\n"
    "                    \"list-commands\"\n"
    "                ]\n"
    "            },\n"
    "            \"other-commands\": false\n"
    "        }\n"
    "    ]\n"
    "}\n"
};

/// @brief Test fixture for check RBAC callouts.
class CalloutTest : public ::testing::Test {
public:

    /// @brief Constructor.
    CalloutTest() : co_manager_(new CalloutManager(1)) {
        roleAssign.reset();
        roleConfigTable.clear();
        defaultRoleConfig.reset();
        unknownRoleConfig.reset();
        aclTable.clear();
        apiTable.clear();
        apiAccesses.clear();
        apiHooks.clear();
        responseFilterTable.clear();
    }

    /// @brief Destructor.
    virtual ~CalloutTest() {
        roleAssign.reset();
        roleConfigTable.clear();
        defaultRoleConfig.reset();
        unknownRoleConfig.reset();
        aclTable.clear();
        apiTable.clear();
        apiAccesses.clear();
        apiHooks.clear();
        responseFilterTable.clear();
    }

    /// @brief Configure.
    ///
    /// @param config The configuration.
    void configure(const string& config) {
        ElementPtr json;
        EXPECT_NO_THROW(json = Element::fromJSON(config));
        ASSERT_TRUE(json);
        json->set("api-files", Element::create(string(API_DIR)));
        EXPECT_NO_THROW(Config::parse(json));
    }

    /// @brief Fetches the callout manager instance.
    boost::shared_ptr<CalloutManager>getCalloutManager() {
        return (co_manager_);
    }

    /// @brief Test auth callout.
    ///
    /// @param request The request.
    /// @param response The response.
    void authCalloutCall(HttpRequestPtr request,
                         HttpResponseJsonPtr& response) {
        // Get callout handle.
        CalloutHandle handle(getCalloutManager());

        handle.setArgument("request", request);
        handle.setArgument("response", response);

        int ret;
        ASSERT_NO_THROW(ret = auth(handle));
        EXPECT_EQ(0, ret);

        handle.getArgument("response", response);
    }

    /// @brief Create HTTP Request.
    ///
    /// @param command The command name.
    /// @param service  The service (can be empty).
    HttpRequestPtr createHttpRequest(const string& command,
                                     const string& service) {
        PostHttpRequestJsonPtr request(new PostHttpRequestJson(
                HttpRequest::Method::HTTP_POST, "/",
                HttpVersion::HTTP_11()));
        const ConstElementPtr& body = createCommand(command, service);
        request->setBodyAsJson(body);
        request->finalize();
        return (request);
    }

    /// @brief Callout manager accessed by this CalloutHandle.
    boost::shared_ptr<CalloutManager> co_manager_;
};

/// @brief This test verifies that accept works as expected.
TEST_F(CalloutTest, accept) {
    configure(CONFIGS[0]);
    HttpRequestPtr request = createHttpRequest("list-commands", "dhcp4");
    request->setRemote("127.0.0.1");
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_FALSE(response);
}

/// @brief This test verifies that reject works as expected.
TEST_F(CalloutTest, reject) {
    configure(CONFIGS[0]);
    HttpRequestPtr request = createHttpRequest("status-get", "dhcp6");
    request->setRemote("127.0.0.1");
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_TRUE(response);
}

} // end of anonymous namespace
