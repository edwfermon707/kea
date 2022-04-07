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
#include <testutils/log_utils.h>
#include <cstdlib>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::dhcp::test;
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
    "}\n",

    // configuration 1: same with other-commands to true.
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
    "            \"other-commands\": true\n"
    "        }\n"
    "    ]\n"
    "}\n",

    // configuration 2: now with require-tls.
    "{\n"
    "    \"assign-role-method\": \"remote-address\",\n"
    "    \"require-tls\": true,\n"
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
    "}\n",

    // configuration 3: now with the list-commands response filter.
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
    "                    \"list-commands\",\n"
    "                    \"config-get\",\n"
    "                    \"build-report\"\n"
    "                ]\n"
    "            },\n"
    "            \"other-commands\": false,\n"
    "            \"response-filters\":\n"
    "            [\n"
    "                \"list-commands\"\n"
    "            ]\n"
    "        }\n"
    "    ]\n"
    "}\n"

};

/// @brief Test fixture for check RBAC callouts.
class CalloutTest : public LogContentTest {
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
        rbacConfig.init();
    }

    /// @brief Destructor.
    virtual ~CalloutTest() {
        if (roleAssign) {
            roleAssign->setup(false);
        }
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

    /// @brief Test chained callouts.
    ///
    /// @param request The request.
    /// @param http_response The response.
    void calloutCalls(HttpRequestPtr request,
                      HttpResponseJsonPtr http_response) {
        // Get callout handle.
        CalloutHandle handle(getCalloutManager());

        handle.setArgument("request", request);
        HttpResponseJsonPtr auth_response;
        handle.setArgument("response", auth_response);

        int ret;
        ASSERT_NO_THROW(ret = auth(handle));
        EXPECT_EQ(0, ret);

        handle.getArgument("response", auth_response);
        EXPECT_FALSE(auth_response);

        // response requires a post processing response.
        handle.setArgument("response", http_response);

        ASSERT_NO_THROW(ret = response(handle));
        EXPECT_EQ(0, ret);
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

    /// @brief Create HTTP Response.
    ///
    /// @param answer JSON answer.
    HttpResponseJsonPtr createHttpResponse(ConstElementPtr answer) {
        HttpResponseJsonPtr response(new HttpResponseJson(
                HttpVersion::HTTP_11(),
                HttpStatusCode::OK));
        response->setBodyAsJson(answer);
        response->finalize();
        return (response);
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
    string expected = "RBAC_TRACE_AUTH_ACCEPT ";
    expected += "Role configuration '127.0.0.1' for role '127.0.0.1' ";
    expected += "has accepted command 'list-commands'.";
    EXPECT_EQ(1, countFile(expected));
}

/// @brief This test verifies that reject works as expected.
TEST_F(CalloutTest, reject) {
    configure(CONFIGS[0]);
    HttpRequestPtr request = createHttpRequest("status-get", "dhcp6");
    request->setRemote("127.0.0.1");
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_TRUE(response);
    string expected = "RBAC_TRACE_AUTH_REJECT ";
    expected += "Role configuration '127.0.0.1' for role '127.0.0.1' ";
    expected += "has rejected command 'status-get'.";
    EXPECT_EQ(1, countFile(expected));
}

/// @brief This test verifies that other commands works as expected.
TEST_F(CalloutTest, otherCommands) {
    configure(CONFIGS[1]);
    RoleConfigPtr rc = roleConfigTable["127.0.0.1"];
    HttpRequestPtr request = createHttpRequest("status-get", "dhcp4");
    request->setRemote("127.0.0.1");
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_FALSE(response);
    string expected = "RBAC_TRACE_AUTH_ACCEPT ";
    expected += "Role configuration '127.0.0.1' for role '127.0.0.1' ";
    expected += "has accepted command 'status-get'.";
    EXPECT_EQ(1, countFile(expected));
}

/// @brief This test verifies that default role works as expected.
TEST_F(CalloutTest, defaultRole) {
    configure(CONFIGS[0]);
    HttpRequestPtr request = createHttpRequest("list-commands", "dhcp6");
    // no remote.
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_TRUE(response);
    string expected = "RBAC_TRACE_AUTH_REJECT ";
    expected += "Role configuration 'default/reject' for role '' ";
    expected += "has rejected command 'list-commands'.";
    EXPECT_EQ(1, countFile(expected));
}

/// @brief This test verifies that unknown role works as expected.
TEST_F(CalloutTest, unknowntRole) {
    configure(CONFIGS[0]);
    HttpRequestPtr request = createHttpRequest("list-commands", "dhcp4");
    request->setRemote("::1");
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_TRUE(response);
    string expected = "RBAC_TRACE_AUTH_REJECT ";
    expected += "Role configuration 'unknown/reject' for role '::1' ";
    expected += "has rejected command 'list-commands'.";
    EXPECT_EQ(1, countFile(expected));
}

/// @brief This test verifies that require TLS works as expected.
TEST_F(CalloutTest, requireTls) {
    configure(CONFIGS[2]);
    HttpRequestPtr request = createHttpRequest("list-commands", "dhcp6");
    // Require TLS default value is false.
    HttpResponseJsonPtr response;
    authCalloutCall(request, response);
    EXPECT_TRUE(response);
    EXPECT_EQ(1, countFile("RBAC_TRACE_AUTH_NO_TLS_REJECT"));
}

/// @brief This test verifies that list-commands response filter works
/// as expected.
TEST_F(CalloutTest, listCommands) {
    configure(CONFIGS[3]);
    HttpRequestPtr request = createHttpRequest("list-commands", "dhcp4");
    request->setRemote("127.0.0.1");

    ElementPtr answer_list = Element::createList();
    ElementPtr answer = Element::createMap();
    answer_list->add(answer);
    ElementPtr result = Element::create(CONTROL_RESULT_SUCCESS);
    answer->set(CONTROL_RESULT, result);
    ElementPtr args = Element::createList();
    answer->set(CONTROL_ARGUMENTS, args);
    args->add(Element::create(string("list-commands")));
    args->add(Element::create(string("config-get")));
    args->add(Element::create(string("build-report")));
    string expected = answer_list->str();
    args->add(Element::create(string("config-set")));
    args->add(Element::create(string("shutdown")));
    HttpResponseJsonPtr response = createHttpResponse(answer_list);

    calloutCalls(request, response);
    ConstElementPtr body = response->getBodyAsJson();
    ASSERT_TRUE(body);
    EXPECT_EQ(expected, body->str());

    expected = "RBAC_TRACE_RESPONSE_MODIFIED The response has been modified ";
    expected += "by a response filter in response callout.";
    EXPECT_EQ(1, countFile(expected));
}

} // end of anonymous namespace
