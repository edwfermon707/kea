// Copyright (C) 2018-2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <yang/translator_config.h>
#include <yang/adaptor_config.h>
#include <yang/yang_models.h>
#include <sstream>

using namespace std;
using namespace isc::data;
using namespace sysrepo;

namespace isc {
namespace yang {

TranslatorConfig::TranslatorConfig(Session session, const string& model)
    : TranslatorBasic(session, model),
      TranslatorControlSocket(session, model),
      TranslatorDatabase(session, model),
      TranslatorDatabases(session, model),
      TranslatorOptionData(session, model),
      TranslatorOptionDataList(session, model),
      TranslatorOptionDef(session, model),
      TranslatorOptionDefList(session, model),
      TranslatorClass(session, model),
      TranslatorClasses(session, model),
      TranslatorPool(session, model),
      TranslatorPools(session, model),
      TranslatorPdPool(session, model),
      TranslatorPdPools(session, model),
      TranslatorHost(session, model),
      TranslatorHosts(session, model),
      TranslatorSubnet(session, model),
      TranslatorSubnets(session, model),
      TranslatorSharedNetwork(session, model),
      TranslatorSharedNetworks(session, model),
      TranslatorLogger(session, model),
      TranslatorLoggers(session, model) {
}

TranslatorConfig::~TranslatorConfig() {
}

ElementPtr
TranslatorConfig::getConfig() {
    ElementPtr result;
    try {
        result = getItem("/" + model_ + ":*//.");
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError, "sysrepo error getting config: " << ex.what());
    }

    if (model_ == KEA_DHCP4_SERVER ||
        model_ == KEA_DHCP6_SERVER) {
        result->forAll([](Element& e) {
            if (e.getType() == Element::map) {
                ElementPtr user_context(e.getNonConst("user-context"));
                if (user_context) {
                    e.set("user-context", Element::fromJSON(user_context->stringValue()));
                }
            }
        });
    }

    return result;
}

ElementPtr
TranslatorConfig::getConfigIetf6() {
    ElementPtr result = Element::createMap();
    ElementPtr dhcp6 = Element::createMap();
    string xpath = "/" + model_ + ":server/server-config";
    ConstElementPtr ranges =
        getSubnets(xpath + "/network-ranges");
    if (ranges && !ranges->empty()) {
        dhcp6->set("subnet6", ranges);
    }
    // Skip everything else.
    return (result);
}

ElementPtr
TranslatorConfig::getConfigKea4() {
    ElementPtr result = Element::createMap();
    ElementPtr dhcp = getServerKeaDhcp4();
    result->set("Dhcp4", dhcp);
    return (result);
}

ElementPtr
TranslatorConfig::getConfigKea6() {
    ElementPtr result = Element::createMap();
    ElementPtr dhcp = getServerKeaDhcp6();
    result->set("Dhcp6", dhcp);
    return (result);
}

ElementPtr TranslatorConfig::getHook(string const& xpath) {
    ElementPtr const& hook_library(Element::createMap());
    ElementPtr const& name(getItem(xpath + "/library"));
    if (name) {
        hook_library->set("library", name);
        ElementPtr const& parameters(getItem(xpath + "/parameters"));
        if (parameters) {
            hook_library->set("parameters",
                              Element::fromJSON(parameters->stringValue()));
        }
    }
    return hook_library;
}

ElementPtr
TranslatorConfig::getHooksKea(const std::string& xpath) {
    return getList(xpath + "/hooks-libraries", *this, &TranslatorConfig::getHook);
}

isc::data::ElementPtr
TranslatorConfig::getExpiredKea(const std::string& xpath) {
    ElementPtr expired = Element::createMap();

    checkAndGetLeaf(expired, xpath, "reclaim-timer-wait-time");
    checkAndGetLeaf(expired, xpath, "flush-reclaimed-timer-wait-time");
    checkAndGetLeaf(expired, xpath, "hold-reclaimed-time");
    checkAndGetLeaf(expired, xpath, "max-reclaim-leases");
    checkAndGetLeaf(expired, xpath, "max-reclaim-time");
    checkAndGetLeaf(expired, xpath, "unwarned-reclaim-cycles");

    if (!expired->empty()) {
        return (expired);
    }

    return (ElementPtr());
}

isc::data::ElementPtr
TranslatorConfig::getDdnsKea(const std::string& xpath) {
    ElementPtr ddns = Element::createMap();
    checkAndGetLeaf(ddns, xpath, "enable-updates");
    checkAndGetLeaf(ddns, xpath, "qualifying-suffix");
    checkAndGetLeaf(ddns, xpath, "server-ip");
    checkAndGetLeaf(ddns, xpath, "server-port");
    checkAndGetLeaf(ddns, xpath, "sender-ip");
    checkAndGetLeaf(ddns, xpath, "sender-port");
    checkAndGetLeaf(ddns, xpath, "max-queue-size");
    checkAndGetLeaf(ddns, xpath, "ncr-protocol");
    checkAndGetLeaf(ddns, xpath, "ncr-format");
    checkAndGetLeaf(ddns, xpath, "override-no-update");
    checkAndGetLeaf(ddns, xpath, "override-client-update");
    checkAndGetLeaf(ddns, xpath, "replace-client-name");
    checkAndGetLeaf(ddns, xpath, "generated-prefix");
    checkAndGetLeaf(ddns, xpath, "hostname-char-set");
    checkAndGetLeaf(ddns, xpath, "hostname-char-replacement");

    ConstElementPtr context = getItem(xpath + "/user-context");
    if (context) {
        ddns->set("user-context", Element::fromJSON(context->stringValue()));
    }

    if (!ddns->empty()) {
        // If there's something to return, use it.
        return (ddns);
    }

    // If not, return null.
    return (ElementPtr());
}

ElementPtr
TranslatorConfig::getConfigControlKea(const string& xpath) {
    ElementPtr config_ctrl = Element::createMap();
    checkAndGetLeaf(config_ctrl, xpath, "config-fetch-wait-time");
    ConstElementPtr databases = getDatabases(xpath + "/config-database");
    if (databases && !databases->empty()) {
        config_ctrl->set("config-databases", databases);
    }
    if (!config_ctrl->empty()) {
        // If there's something to return, use it.
        return (config_ctrl);
    }

    // If not, return null.
    return (ElementPtr());
}

ElementPtr
TranslatorConfig::getServerKeaDhcpCommon(const string& xpath) {
    ElementPtr result = Element::createMap();

    checkAndGetLeaf(result, xpath, "valid-lifetime");
    checkAndGetLeaf(result, xpath, "min-valid-lifetime");
    checkAndGetLeaf(result, xpath, "max-valid-lifetime");
    checkAndGetLeaf(result, xpath, "renew-timer");
    checkAndGetLeaf(result, xpath, "rebind-timer");
    checkAndGetLeaf(result, xpath, "calculate-tee-times");
    checkAndGetLeaf(result, xpath, "t1-percent");
    checkAndGetLeaf(result, xpath, "t2-percent");
    checkAndGetLeaf(result, xpath, "decline-probation-period");
    checkAndGetLeaf(result, xpath, "hostname-char-set");
    checkAndGetLeaf(result, xpath, "hostname-char-replacement");

    ConstElementPtr networks = getSharedNetworks(xpath);
    if (networks && !networks->empty()) {
        result->set("shared-networks", networks);
    }
    ConstElementPtr classes = getClasses(xpath);
    if (classes && !classes->empty()) {
        result->set("client-classes", classes);
    }
    ConstElementPtr database = getDatabase(xpath + "/lease-database");
    if (database) {
        result->set("lease-database", database);
    }
    ConstElementPtr databases = getDatabases(xpath + "/hosts-database");
    if (databases && !databases->empty()) {
        result->set("hosts-databases", databases);
    }
    ConstElementPtr host_ids =
        getItem(xpath + "/host-reservation-identifiers");
    if (host_ids) {
        result->set("host-reservation-identifiers", host_ids);
    }
    ConstElementPtr defs = getOptionDefList(xpath);
    if (defs && !defs->empty()) {
        result->set("option-def", defs);
    }
    ConstElementPtr options = getOptionDataList(xpath);
    if (options && !options->empty()) {
        result->set("option-data", options);
    }
    ConstElementPtr hooks = getHooksKea(xpath);
    if (hooks && !hooks->empty()) {
        result->set("hooks-libraries", hooks);
    }
    ConstElementPtr expired =
        getExpiredKea(xpath + "/expired-leases-processing");
    if (expired) {
        result->set("expired-leases-processing", expired);
    }
    checkAndGetLeaf(result, xpath, "dhcp4o6-port");
    ConstElementPtr socket = getControlSocket(xpath + "/control-socket");
    if (socket) {
        result->set("control-socket", socket);
    }
    ConstElementPtr ddns = getDdnsKea(xpath + "/dhcp-ddns");
    if (ddns) {
        result->set("dhcp-ddns", ddns);
    }
    ConstElementPtr context = getItem(xpath + "/user-context");
    if (context) {
        result->set("user-context", Element::fromJSON(context->stringValue()));
    }
    ConstElementPtr checks = getItem(xpath + "/sanity-checks/lease-checks");
    if (checks) {
        ElementPtr sanity = Element::createMap();
        sanity->set("lease-checks", checks);
        result->set("sanity-checks", sanity);
    }
    checkAndGetLeaf(result, xpath, "reservation-mode");
    ConstElementPtr hosts = getHosts(xpath);
    if (hosts && !hosts->empty()) {
        result->set("reservations", hosts);
    }
    ConstElementPtr config_ctrl =
        getConfigControlKea(xpath + "/config-control");
    if (config_ctrl) {
        result->set("config-control", config_ctrl);
    }
    checkAndGetLeaf(result, xpath, "server-tag");
    ConstElementPtr queue_ctrl = getItem(xpath + "/dhcp-queue-control");
    if (queue_ctrl) {
        result->set("dhcp-queue-control",
                    Element::fromJSON(queue_ctrl->stringValue()));
    }
    ConstElementPtr loggers = getLoggers(xpath);
    if (loggers && !loggers->empty()) {
        result->set("loggers", loggers);
    }
    checkAndGetLeaf(result, xpath, "cache-max-age");
    checkAndGetLeaf(result, xpath, "cache-threshold");
    ElementPtr compatibility = Element::createMap();
    checkAndGetLeaf(compatibility, xpath + "/compatibility", "lenient-option-parsing");
    if (!compatibility->empty()) {
        result->set("compatibility", compatibility);
    }
    checkAndGetLeaf(result, xpath, "ddns-generated-prefix");
    checkAndGetLeaf(result, xpath, "ddns-override-client-update");
    checkAndGetLeaf(result, xpath, "ddns-override-no-update");
    checkAndGetLeaf(result, xpath, "ddns-qualifying-suffix");
    checkAndGetLeaf(result, xpath, "ddns-replace-client-name");
    checkAndGetLeaf(result, xpath, "ddns-send-updates");
    checkAndGetLeaf(result, xpath, "ddns-update-on-renew");
    checkAndGetLeaf(result, xpath, "ddns-use-conflict-resolution");
    checkAndGetLeaf(result, xpath, "ip-reservations-unique");
    checkAndGetLeaf(result, xpath, "early-global-reservations-lookup");
    checkAndGetLeaf(result, xpath, "reservations-lookup-first");
    ElementPtr multi_threading = Element::createMap();
    string mt_xpath = xpath + "/multi-threading";
    checkAndGetLeaf(multi_threading, mt_xpath, "enable-multi-threading");
    checkAndGetLeaf(multi_threading, mt_xpath, "packet-queue-size");
    checkAndGetLeaf(multi_threading, mt_xpath, "thread-pool-size");
    if (!multi_threading->empty()) {
        result->set("multi-threading", multi_threading);
    }
    checkAndGetLeaf(result, xpath, "parked-packet-limit");
    checkAndGetLeaf(result, xpath, "reservations-global");
    checkAndGetLeaf(result, xpath, "reservations-in-subnet");
    checkAndGetLeaf(result, xpath, "reservations-out-of-pool");
    checkAndGetLeaf(result, xpath, "statistic-default-sample-age");
    checkAndGetLeaf(result, xpath, "statistic-default-sample-count");
    checkAndGetLeaf(result, xpath, "store-extended-info");
    return (result);
}

ElementPtr
TranslatorConfig::getServerKeaDhcp4() {
    string xpath = "/kea-dhcp4-server:config";
    ElementPtr result = getServerKeaDhcpCommon(xpath);
    // Handle subnets.
    ConstElementPtr subnets = getSubnets(xpath);
    if (subnets && !subnets->empty()) {
        result->set("subnet4", subnets);
    }
    // Handle interfaces.
    ElementPtr if_config = Element::createMap();
    ConstElementPtr ifs = getItem(xpath + "/interfaces-config/interfaces");
    if (ifs && !ifs->empty()) {
        if_config->set("interfaces", ifs);
    }
    string if_cfg_xpath = xpath + "/interfaces-config";
    checkAndGetLeaf(if_config, if_cfg_xpath, "dhcp-socket-type");
    checkAndGetLeaf(if_config, if_cfg_xpath, "outbound-interface");
    checkAndGetLeaf(if_config, if_cfg_xpath, "service-sockets-require-all");
    checkAndGetLeaf(if_config, if_cfg_xpath, "service-sockets-max-retries");
    checkAndGetLeaf(if_config, if_cfg_xpath, "service-sockets-retry-wait-time");
    checkAndGetLeaf(if_config, if_cfg_xpath, "re-detect");
    ConstElementPtr context =
        getItem(xpath + "/interfaces-config/user-context");
    if (context) {
        if_config->set("user-context",
                       Element::fromJSON(context->stringValue()));
    }
    if (!if_config->empty()) {
        result->set("interfaces-config", if_config);
    }
    // Handle DHCPv4 specific global parameters.
    checkAndGetLeaf(result, xpath, "echo-client-id");
    checkAndGetLeaf(result, xpath, "match-client-id");
    checkAndGetLeaf(result, xpath, "next-server");
    checkAndGetLeaf(result, xpath, "server-hostname");
    checkAndGetLeaf(result, xpath, "boot-file-name");
    checkAndGetLeaf(result, xpath, "authoritative");
    return (result);
}

ElementPtr
TranslatorConfig::getServerKeaDhcp6() {
    string xpath = "/kea-dhcp6-server:config";
    ElementPtr result = getServerKeaDhcpCommon(xpath);
    // Handle DHCPv6 specific global parameters.
    checkAndGetLeaf(result, xpath, "data-directory");
    checkAndGetLeaf(result, xpath, "preferred-lifetime");
    checkAndGetLeaf(result, xpath, "min-preferred-lifetime");
    checkAndGetLeaf(result, xpath, "max-preferred-lifetime");
    // Handle subnets.
    ConstElementPtr subnets = getSubnets(xpath);
    if (subnets && !subnets->empty()) {
        result->set("subnet6", subnets);
    }
    // Handle interfaces.
    ElementPtr if_config = Element::createMap();
    ConstElementPtr ifs = getItem(xpath + "/interfaces-config/interfaces");
    if (ifs && !ifs->empty()) {
        if_config->set("interfaces", ifs);
    }
    string if_cfg_xpath = xpath + "/interfaces-config";
    checkAndGetLeaf(if_config, if_cfg_xpath, "service-sockets-require-all");
    checkAndGetLeaf(if_config, if_cfg_xpath, "service-sockets-max-retries");
    checkAndGetLeaf(if_config, if_cfg_xpath, "service-sockets-retry-wait-time");
    checkAndGetLeaf(if_config, if_cfg_xpath, "re-detect");
    ConstElementPtr context =
        getItem(xpath + "/interfaces-config/user-context");
    if (context) {
        if_config->set("user-context",
                       Element::fromJSON(context->stringValue()));
    }
    if (!if_config->empty()) {
        result->set("interfaces-config", if_config);
    }
    // Handle DHCPv6 specific global entries.
    ConstElementPtr relay = getItem(xpath + "/relay-supplied-options");
    if (relay) {
        result->set("relay-supplied-options", relay);
    }
    ConstElementPtr macs = getItem(xpath + "/mac-sources");
    if (macs) {
        result->set("mac-sources", macs);
    }
    // Handle server-id.
    // @todo: move to a DUID translator.
    ElementPtr server_id = Element::createMap();
    string srv_id_xpath = xpath + "/server-id";
    checkAndGetLeaf(server_id, srv_id_xpath, "type");
    checkAndGetLeaf(server_id, srv_id_xpath, "identifier");
    checkAndGetLeaf(server_id, srv_id_xpath, "time");
    checkAndGetLeaf(server_id, srv_id_xpath, "htype");
    checkAndGetLeaf(server_id, srv_id_xpath, "enterprise-id");
    checkAndGetLeaf(server_id, srv_id_xpath, "persist");
    context = getItem(xpath + "/server-id/user-context");
    if (context) {
        server_id->set("user-context",
                       Element::fromJSON(context->stringValue()));
    }
    if (!server_id->empty()) {
        result->set("server-id", server_id);
    }
    return (result);
}

void
TranslatorConfig::setConfig(ConstElementPtr elem) {
    if (model_ == KEA_DHCP4_SERVER ||
        model_ == KEA_DHCP6_SERVER) {
        ElementPtr mutable_elem(copy(elem, 0));
        mutable_elem->forAll([](Element& e) {
            if (e.getType() == Element::map) {
                ElementPtr reservations(e.getNonConst("reservations"));
                if (reservations) {
                    for (ElementPtr i : reservations->listValue()) {
                        ElementPtr duid(i->getNonConst("duid"));
                        if (duid) {
                            i->set("identifier-type", Element::create("duid"));
                            i->set("identifier", duid);
                        }
                    }
                }
            }
        });
    }

    try {
        if (model_ == IETF_DHCPV6_SERVER) {
            ElementPtr config(elem->getNonConst("config"));
            if (config) {
                set("/" + model_ + ":config", config);
            }
        } else if (model_ == KEA_DHCP4_SERVER) {
            ElementPtr dhcp4(elem->getNonConst("Dhcp4"));
            if (dhcp4) {
                set("/" + model_ + ":config", dhcp4);
            }
        } else if (model_ == KEA_DHCP6_SERVER) {
            ElementPtr dhcp6(elem->getNonConst("Dhcp6"));
            if (dhcp6) {
                set("/" + model_ + ":config", dhcp6);
            }
        } else {
            isc_throw(NotImplemented,
                      "setConfig not implemented for the model: " << model_);
        }
    } catch (const libyang::ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error setting config '" << elem->str()
                  << "': " << ex.what());
    }
}

void
TranslatorConfig::delConfigIetf6() {
    delItem("/" + model_ + ":server");
}

void
TranslatorConfig::setConfigIetf6(ConstElementPtr elem) {
    string xpath = "/" + model_ + ":server/server-config";
    ConstElementPtr ranges = elem->get("subnet6");
    if (ranges && !ranges->empty()) {
        setSubnets(xpath + "/network-ranges", ranges);
    }
    // Skip everything else.
}

void
TranslatorConfig::delConfigKea() {
    delItem("/" + model_ + ":config");
}

void
TranslatorConfig::setConfigKea4(ConstElementPtr elem) {
    ConstElementPtr dhcp = elem->get("Dhcp4");
    if (dhcp) {
        setServerKeaDhcp4(dhcp);
    }
}

void
TranslatorConfig::setConfigKea6(ConstElementPtr elem) {
    ConstElementPtr dhcp = elem->get("Dhcp6");
    if (dhcp) {
        setServerKeaDhcp6(dhcp);
    }
}

void
TranslatorConfig::setServerKeaDhcpCommon(const string& xpath,
                                         ConstElementPtr elem) {
    checkAndSetLeaf(elem, xpath, "valid-lifetime");
    checkAndSetLeaf(elem, xpath, "min-valid-lifetime");
    checkAndSetLeaf(elem, xpath, "max-valid-lifetime");
    checkAndSetLeaf(elem, xpath, "renew-timer");
    checkAndSetLeaf(elem, xpath, "rebind-timer");
    checkAndSetLeaf(elem, xpath, "calculate-tee-times");
    checkAndSetLeaf(elem, xpath, "t1-percent");
    checkAndSetLeaf(elem, xpath, "t2-percent");
    checkAndSetLeaf(elem, xpath, "decline-probation-period");
    ConstElementPtr networks = elem->get("shared-networks");
    if (networks) {
        setSharedNetworks(xpath, networks);
    }
    ConstElementPtr classes = elem->get("client-classes");
    if (classes && !classes->empty()) {
        setClasses(xpath, classes);
    }
    ConstElementPtr database = elem->get("lease-database");
    if (database) {
        setDatabase(xpath + "/lease-database", database);
    }
    ConstElementPtr databases = elem->get("hosts-databases");
    if (databases && !databases->empty()) {
        setDatabases(xpath + "/hosts-database", databases);
    } else {
        // Reuse of database from lease-database.
        database = elem->get("hosts-database");
        if (database) {
            ElementPtr list = Element::createList();
            list->add(copy(database));
            setDatabases(xpath + "/hosts-database", list);
        }
    }
    ConstElementPtr host_ids = elem->get("host-reservation-identifiers");
    if (host_ids) {
        for (ConstElementPtr id : host_ids->listValue()) {
            setItem(xpath + "/host-reservation-identifiers", id);
        }
    }
    ConstElementPtr defs = elem->get("option-def");
    if (defs && !defs->empty()) {
        setOptionDefList(xpath, defs);
    }
    ConstElementPtr options = elem->get("option-data");
    if (options && !options->empty()) {
        setOptionDataList(xpath, options);
    }
    ConstElementPtr hook_libs = elem->get("hooks-libraries");
    if (hook_libs) {
        for (ConstElementPtr lib : hook_libs->listValue()) {
            ConstElementPtr name = lib->get("library");
            if (!name) {
                continue;
            }
            ostringstream hook_lib;
            hook_lib << xpath << "/hooks-libraries[library='"
                     << name->stringValue() << "']";
            ConstElementPtr params = lib->get("parameters");
            if (params) {
                hook_lib << "/parameters";
                setItem(hook_lib.str(), Element::create(params->str()));
            } else {
                ConstElementPtr list = Element::createList();
                setItem(hook_lib.str(), list);
            }
        }
    }
    ConstElementPtr expired = elem->get("expired-leases-processing");
    if (expired) {
        string expired_xpath = xpath + "/expired-leases-processing";
        checkAndSetLeaf(expired, expired_xpath, "reclaim-timer-wait-time");
        checkAndSetLeaf(expired, expired_xpath, "flush-reclaimed-timer-wait-time");
        checkAndSetLeaf(expired, expired_xpath, "hold-reclaimed-time");
        checkAndSetLeaf(expired, expired_xpath, "max-reclaim-leases");
        checkAndSetLeaf(expired, expired_xpath, "max-reclaim-time");
        checkAndSetLeaf(expired, expired_xpath, "unwarned-reclaim-cycles");
    }
    checkAndSetLeaf(elem, xpath, "dhcp4o6-port");
    ConstElementPtr socket = elem->get("control-socket");
    if (socket) {
        setControlSocket(xpath + "/control-socket", socket);
    }
    checkAndSetLeaf(elem, xpath, "hostname-char-set");
    checkAndSetLeaf(elem, xpath, "hostname-char-replacement");
    ConstElementPtr ddns = elem->get("dhcp-ddns");
    if (ddns) {
        string ddns_xpath = xpath + "/dhcp-ddns";
        checkAndSetLeaf(ddns, ddns_xpath, "enable-updates");
        checkAndSetLeaf(ddns, ddns_xpath, "qualifying-suffix");
        checkAndSetLeaf(ddns, ddns_xpath, "server-ip");
        checkAndSetLeaf(ddns, ddns_xpath, "server-port");
        checkAndSetLeaf(ddns, ddns_xpath, "sender-ip");
        checkAndSetLeaf(ddns, ddns_xpath, "sender-port");
        checkAndSetLeaf(ddns, ddns_xpath, "max-queue-size");
        checkAndSetLeaf(ddns, ddns_xpath, "ncr-protocol");
        checkAndSetLeaf(ddns, ddns_xpath, "ncr-format");
        checkAndSetLeaf(ddns, ddns_xpath, "override-no-update");
        checkAndSetLeaf(ddns, ddns_xpath, "override-client-update");
        checkAndSetLeaf(ddns, ddns_xpath, "replace-client-name");
        checkAndSetLeaf(ddns, ddns_xpath, "generated-prefix");
        checkAndSetLeaf(ddns, ddns_xpath, "hostname-char-set");
        checkAndSetLeaf(ddns, ddns_xpath, "hostname-char-replacement");
        ConstElementPtr context = Adaptor::getContext(ddns);
        if (context) {
            ConstElementPtr repr = Element::create(context->str());
            setItem(xpath + "/dhcp-ddns/user-context", repr);
        }
    }
    ConstElementPtr context = Adaptor::getContext(elem);
    if (context) {
        ConstElementPtr repr = Element::create(context->str());
        setItem(xpath + "/user-context", repr);
    }
    ConstElementPtr sanity = elem->get("sanity-checks");
    if (sanity) {
        checkAndSetLeaf(sanity, xpath + "/sanity-checks", "lease-checks");
    }
    checkAndSetLeaf(elem, xpath, "reservation-mode");
    ConstElementPtr hosts = elem->get("reservations");
    if (hosts && !hosts->empty()) {
        setHosts(xpath, hosts);
    }
    ConstElementPtr config_ctrl = elem->get("config-control");
    if (config_ctrl && !config_ctrl->empty()) {
        checkAndSetLeaf(config_ctrl, xpath + "/config-control", "config-fetch-wait-time");
        databases = config_ctrl->get("config-databases");
        if (databases && !databases->empty()) {
            setDatabases(xpath + "/config-control/config-database", databases);
        }
    }
    checkAndSetLeaf(elem, xpath, "server-tag");
    ConstElementPtr queue_ctrl = elem->get("dhcp-queue-control");
    if (queue_ctrl) {
        ConstElementPtr repr = Element::create(queue_ctrl->str());
        setItem(xpath + "/dhcp-queue-control", repr);
    }
    ConstElementPtr loggers = elem->get("loggers");
    if (loggers) {
        setLoggers(xpath, loggers);
    }
    checkAndSetLeaf(elem, xpath, "cache-max-age");
    checkAndSetLeaf(elem, xpath, "cache-threshold");
    ConstElementPtr compatibility(elem->get("compatibility"));
    if (compatibility) {
        checkAndSetLeaf(compatibility, xpath + "/compatibility", "lenient-option-parsing");
    }
    checkAndSetLeaf(elem, xpath, "ddns-generated-prefix");
    checkAndSetLeaf(elem, xpath, "ddns-override-client-update");
    checkAndSetLeaf(elem, xpath, "ddns-override-no-update");
    checkAndSetLeaf(elem, xpath, "ddns-qualifying-suffix");
    checkAndSetLeaf(elem, xpath, "ddns-replace-client-name");
    checkAndSetLeaf(elem, xpath, "ddns-send-updates");
    checkAndSetLeaf(elem, xpath, "ddns-update-on-renew");
    checkAndSetLeaf(elem, xpath, "ddns-use-conflict-resolution");
    checkAndSetLeaf(elem, xpath, "ip-reservations-unique");
    checkAndSetLeaf(elem, xpath, "early-global-reservations-lookup");
    checkAndSetLeaf(elem, xpath, "reservations-lookup-first");
    ConstElementPtr multi_threading(elem->get("multi-threading"));
    if (multi_threading) {
        string mt_xpath = xpath + "/multi-threading";
        checkAndSetLeaf(multi_threading, mt_xpath, "enable-multi-threading");
        checkAndSetLeaf(multi_threading, mt_xpath, "packet-queue-size");
        checkAndSetLeaf(multi_threading, mt_xpath, "thread-pool-size");
    }
    checkAndSetLeaf(elem, xpath, "parked-packet-limit");
    checkAndSetLeaf(elem, xpath, "reservations-global");
    checkAndSetLeaf(elem, xpath, "reservations-in-subnet");
    checkAndSetLeaf(elem, xpath, "reservations-out-of-pool");
    checkAndSetLeaf(elem, xpath, "statistic-default-sample-age");
    checkAndSetLeaf(elem, xpath, "statistic-default-sample-count");
    checkAndSetLeaf(elem, xpath, "store-extended-info");
}

void
TranslatorConfig::setServerKeaDhcp4(ConstElementPtr elem) {
    string xpath = "/kea-dhcp4-server:config";
    setServerKeaDhcpCommon(xpath, elem);
    ConstElementPtr subnets = elem->get("subnet4");
    if (subnets) {
        setSubnets(xpath, subnets);
    }
    ConstElementPtr if_config = elem->get("interfaces-config");
    if (if_config) {
        ConstElementPtr ifs = if_config->get("interfaces");
        if (ifs && !ifs->empty()) {
            for (ConstElementPtr intf : ifs->listValue()) {
                setItem(xpath + "/interfaces-config/interfaces",
                        intf);
            }
        }
        string if_cfg_xpath = xpath + "/interfaces-config";
        checkAndSetLeaf(if_config, if_cfg_xpath, "dhcp-socket-type");
        checkAndSetLeaf(if_config, if_cfg_xpath, "outbound-interface");
        checkAndSetLeaf(if_config, if_cfg_xpath, "service-sockets-require-all");
        checkAndSetLeaf(if_config, if_cfg_xpath, "service-sockets-max-retries");
        checkAndSetLeaf(if_config, if_cfg_xpath, "service-sockets-retry-wait-time");
        checkAndSetLeaf(if_config, if_cfg_xpath, "re-detect");
        ConstElementPtr context = Adaptor::getContext(if_config);
        if (context) {
            setItem(xpath + "/interfaces-config/user-context",
                    Element::create(context->str()));
        }
    }
    checkAndSetLeaf(elem, xpath, "echo-client-id");
    checkAndSetLeaf(elem, xpath, "match-client-id");
    checkAndSetLeaf(elem, xpath, "next-server");
    checkAndSetLeaf(elem, xpath, "server-hostname");
    checkAndSetLeaf(elem, xpath, "boot-file-name");
    checkAndSetLeaf(elem, xpath, "authoritative");
}

void
TranslatorConfig::setServerKeaDhcp6(ConstElementPtr elem) {
    string xpath = "/kea-dhcp6-server:config";
    setServerKeaDhcpCommon(xpath, elem);
    checkAndSetLeaf(elem, xpath, "data-directory");
    checkAndSetLeaf(elem, xpath, "preferred-lifetime");
    checkAndSetLeaf(elem, xpath, "min-preferred-lifetime");
    checkAndSetLeaf(elem, xpath, "max-preferred-lifetime");
    ConstElementPtr subnets = elem->get("subnet6");
    if (subnets) {
        setSubnets(xpath, subnets);
    }
    ConstElementPtr if_config = elem->get("interfaces-config");
    if (if_config) {
        ConstElementPtr ifs = if_config->get("interfaces");
        if (ifs && !ifs->empty()) {
            for (ConstElementPtr intf : ifs->listValue()) {
                setItem(xpath + "/interfaces-config/interfaces",
                        intf);
            }
        }
        string if_cfg_xpath = xpath + "/interfaces-config";
        checkAndSetLeaf(if_config, if_cfg_xpath, "service-sockets-require-all");
        checkAndSetLeaf(if_config, if_cfg_xpath, "service-sockets-max-retries");
        checkAndSetLeaf(if_config, if_cfg_xpath, "service-sockets-retry-wait-time");
        checkAndSetLeaf(if_config, if_cfg_xpath, "re-detect");
        ConstElementPtr context = Adaptor::getContext(if_config);
        if (context) {
            setItem(xpath + "/interfaces-config/user-context",
                    Element::create(context->str()));
        }
    }
    ConstElementPtr relay = elem->get("relay-supplied-options");
    if (relay) {
        for (ConstElementPtr addr : relay->listValue()) {
            setItem(xpath + "/relay-supplied-options", addr);
        }
    }
    ConstElementPtr macs = elem->get("mac-sources");
    if (macs) {
        for (ConstElementPtr source : macs->listValue()) {
            setItem(xpath + "/mac-sources", source);
        }
    }
    ConstElementPtr server_id = elem->get("server-id");
    if (server_id) {
        string srv_id_xpath = xpath + "/server-id";
        checkAndSetLeaf(server_id, srv_id_xpath, "type");
        checkAndSetLeaf(server_id, srv_id_xpath, "identifier");
        checkAndSetLeaf(server_id, srv_id_xpath, "time");
        checkAndSetLeaf(server_id, srv_id_xpath, "htype");
        checkAndSetLeaf(server_id, srv_id_xpath, "enterprise-id");
        checkAndSetLeaf(server_id, srv_id_xpath, "persist");
        ConstElementPtr context = Adaptor::getContext(server_id);
        if (context) {
            ConstElementPtr repr = Element::create(context->str());
            setItem(xpath + "/server-id/user-context", repr);
        }
    }
}

}  // namespace yang
}  // namespace isc
