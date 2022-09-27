// Copyright (C) 2018-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef ISC_YANG_CONFIGS_H
#define ISC_YANG_CONFIGS_H

#include <yang/yang_models.h>
#include <yang/testutils/translator_test.h>

namespace isc {
namespace yang {
namespace test {

/// @brief The test module from sysrepo tests.
const std::string testModel = "keatest-module";
const YRTree testTree = YangRepr::buildTreeFromVector({
    { "/keatest-module:container", "", false },
    { "/keatest-module:main", "", false },
    { "/keatest-module:main/string", "str", true },
    { "/keatest-module:main/boolean", "true", true },
    { "/keatest-module:main/ui8", "8", true },
    { "/keatest-module:main/ui16", "16", true },
    { "/keatest-module:main/ui32", "32", true },
    { "/keatest-module:main/i8", "8", true },
    { "/keatest-module:main/i16", "16", true },
    { "/keatest-module:main/i32", "32", true },
    { "/keatest-module:main/id_ref", "keatest-module:id_1", true },
    { "/keatest-module:main/enum", "maybe", true },
    { "/keatest-module:main/raw", "Zm9vYmFy", true },
    { "/keatest-module:kernel-modules", "", false }
});

/// @brief A subnet with two pools with ietf-dhcpv6-server model.
const std::string subnetTwoPoolsModelIetf6 = IETF_DHCPV6_SERVER;
const YRTree subnetTwoPoolsTreeIetf6 = YangRepr::buildTreeFromVector({
    { "/ietf-dhcpv6-server:server", "", false },
    { "/ietf-dhcpv6-server:server/server-config", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-range-id",
      "111", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-prefix",
      "2001:db8::/48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/pool-id", "0", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/pool-prefix",
      "2001:db8::1:0/112", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/start-address",
      "2001:db8::1:0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/end-address",
      "2001:db8::1:ffff", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/max-address-count",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/pool-id", "1", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/pool-prefix",
      "2001:db8::2:0/112", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/start-address",
      "2001:db8::2:0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/end-address",
      "2001:db8::2:ffff", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/max-address-count",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid/type-code",
      "65535", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/host-reservations",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/lease-storage",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/vendor-info",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/option-sets",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/relay-opaque-paras",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/rsoo-enabled-options",
      "", false },
});

/// @brief A subnet with timers with ietf-dhcpv6-server model.
const std::string subnetTimersModel = IETF_DHCPV6_SERVER;
const YRTree subnetTimersIetf6 = YangRepr::buildTreeFromVector({
    { "/ietf-dhcpv6-server:server", "", false },
    { "/ietf-dhcpv6-server:server/server-config", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-range-id",
      "111", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-prefix",
      "2001:db8::/48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/pool-id", "0", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/pool-prefix",
      "2001:db8::1:0/112", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/start-address",
      "2001:db8::1:0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/end-address",
      "2001:db8::1:ffff", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/renew-time", "1000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/rebind-time", "2000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='0']/max-address-count",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/pool-id", "1", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/pool-prefix",
      "2001:db8::2:0/112", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/start-address",
      "2001:db8::2:0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/end-address",
      "2001:db8::2:ffff", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/renew-time", "1000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/rebind-time", "2000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools/"
      "address-pool[pool-id='1']/max-address-count",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid/type-code",
      "65535", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/host-reservations",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/lease-storage",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/vendor-info",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/option-sets",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/relay-opaque-paras",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/rsoo-enabled-options",
      "", false },
});

/// @brief A subnet with two pools with ietf-dhcpv6-server model
/// which validates.
const std::string validModelIetf6 = IETF_DHCPV6_SERVER;
const YRTree validTreeIetf6 = YangRepr::buildTreeFromVector({
    { "/ietf-dhcpv6-server:server", "", false },
    { "/ietf-dhcpv6-server:server/server-config", "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/vendor-info",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes"
      "/vendor-info/ent-num", "2495", true },
    { "/ietf-dhcpv6-server:server/server-config/option-sets",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/option-sets"
      "/option-set[option-set-id='0']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/option-sets"
      "/option-set[option-set-id='0']/option-set-id",
      "0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-range-id",
      "111", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-description",
      "Subnet#111", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/network-prefix",
      "2001:db8::/48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/pool-id", "0", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/prefix",
      "2001:db8:1::/48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/prefix-length", "48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/valid-lifetime", "4000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/preferred-lifetime",
      "3000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/renew-time", "1000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/rebind-time", "2000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/rapid-commit", "false", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/option-set-id", "0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='0']/max-pd-space-utilization",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/pool-id", "1", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/prefix",
      "2001:db8:2::/48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/prefix-length", "48", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/valid-lifetime", "4000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/preferred-lifetime",
      "3000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/renew-time", "1000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/rebind-time", "2000", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/rapid-commit", "false", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/option-set-id", "0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools/"
      "pd-pool[pool-id='1']/max-pd-space-utilization",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid/type-code",
      "65535", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/address-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/pd-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='111']/host-reservations",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/lease-storage",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/vendor-info",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/option-sets",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/relay-opaque-paras",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/rsoo-enabled-options",
      "", false },
});

/// @brief A subnet with a pool and option data lists with
/// kea-dhcp4-server:config model.
const std::string subnetOptionsModelKeaDhcp4 = KEA_DHCP4_SERVER;
const YRTree subnetOptionsTreeKeaDhcp4 = YangRepr::buildTreeFromVector({
    { "/kea-dhcp4-server:config", "", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']", "",
      false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/id",
      "111", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "option-data[code='100'][space='dns']", "", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "option-data[code='100'][space='dns']/code",
      "100", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "option-data[code='100'][space='dns']/space",
      "dns", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "option-data[code='100'][space='dns']/data",
      "12121212", true },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "option-data[code='100'][space='dns']/csv-format",
      "false", true },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "option-data[code='100'][space='dns']/always-send",
      "false", true },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "pools[prefix='\"10.0.1.0/24\"']",
      "", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/"
      "pools[prefix='\"10.0.1.0/24\"']/prefix",
      "10.0.1.0/24", true },
    { "/kea-dhcp4-server:config/subnet4[id='111']/subnet",
      "10.0.0.0/8", true },
    { "/kea-dhcp4-server:config/expired-leases-processing",
      "", false },
    { "/kea-dhcp4-server:config/dhcp-ddns",
      "", false },
    { "/kea-dhcp4-server:config/config-control",
      "", false },
    { "/kea-dhcp4-server:config/sanity-checks",
      "", false },
    { "/kea-dhcp4-server:config/interfaces-config",
      "", false },
    { "/kea-dhcp4-server:config/subnet4[id='111']/relay",
      "", false },
    { "/kea-dhcp4-server:config/compatibility",
      "", false },
    { "/kea-dhcp4-server:config/multi-threading",
      "", false },
});

/// @brief A subnet with a pool and option data lists with
/// kea-dhcp6-server:config model.
const std::string subnetOptionsModelKeaDhcp6 = KEA_DHCP6_SERVER;
const YRTree subnetOptionsTreeKeaDhcp6 = YangRepr::buildTreeFromVector({
    { "/kea-dhcp6-server:config", "", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']", "", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/id",
      "111", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']",
      "", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "start-address", "2001:db8::1:0", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "end-address", "2001:db8::1:ffff", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "prefix", "2001:db8::1:0/112", true },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "option-data[code='100'][space='dns']",
      "", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "option-data[code='100'][space='dns']/code",
      "100", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "option-data[code='100'][space='dns']/space",
      "dns", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "option-data[code='100'][space='dns']/data",
      "12121212", true },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "option-data[code='100'][space='dns']/csv-format",
      "false", true },
    { "/kea-dhcp6-server:config/subnet6[id='111']/"
      "pools[prefix='\"2001:db8::1:0/112\"']/"
      "option-data[code='100'][space='dns']/always-send",
      "false", true },
    { "/kea-dhcp6-server:config/subnet6[id='111']/subnet",
      "2001:db8::/48", true },
    { "/kea-dhcp6-server:config/expired-leases-processing",
      "", false },
    { "/kea-dhcp6-server:config/dhcp-ddns",
      "", false },
    { "/kea-dhcp6-server:config/config-control",
      "", false },
    { "/kea-dhcp6-server:config/sanity-checks",
      "", false },
    { "/kea-dhcp6-server:config/interfaces-config",
      "", false },
    { "/kea-dhcp6-server:config/subnet6[id='111']/relay",
      "", false },
    { "/kea-dhcp6-server:config/compatibility",
      "", false },
    { "/kea-dhcp6-server:config/multi-threading",
      "", false },
});

/// @brief Example from the design document.
const std::string designExampleModel = IETF_DHCPV6_SERVER;
const YRTree designExampleTree = YangRepr::buildTreeFromVector({
    { "/ietf-dhcpv6-server:server", "", false },
    { "/ietf-dhcpv6-server:server/server-config", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']", "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/network-range-id",
      "1", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/network-description",
      "example", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/pd-pools",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/pd-pools/pd-pool[pool-id='0']",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/pd-pools/pd-pool[pool-id='0']"
      "/pool-id",
      "0", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/pd-pools/pd-pool[pool-id='0']"
      "/prefix",
      "2001:db8:20:b00::/57", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/pd-pools/pd-pool[pool-id='0']"
      "/prefix-length",
      "57", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/pd-pools/"
      "pd-pool[pool-id='0']/max-pd-space-utilization",
      "disabled", true },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/network-prefix",
      "2001:db8:20:b00::/56", true },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid/type-code",
      "65535", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/host-reservations",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/duid",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/lease-storage",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/serv-attributes/vendor-info",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/option-sets",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/relay-opaque-paras",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/rsoo-enabled-options",
      "", false },
    { "/ietf-dhcpv6-server:server/server-config/network-ranges/"
      "network-range[network-range-id='1']/address-pools",
      "", false },
});

const YRTree emptyTreeKeaDhcp4 = YangRepr::buildTreeFromVector({
});

const YRTree emptyTreeKeaDhcp6 = YangRepr::buildTreeFromVector({
});

/// @brief Set of example configurations.
const std::vector<std::pair<std::string, YRTree> > TEST_CONFIGS =
{
    { testModel,                   testTree },
    { subnetTwoPoolsModelIetf6,    subnetTwoPoolsTreeIetf6 },
    { subnetTimersModel,           subnetTimersIetf6 },
    { validModelIetf6,             validTreeIetf6 },
    { subnetOptionsModelKeaDhcp4,  subnetOptionsTreeKeaDhcp4 },
    { subnetOptionsModelKeaDhcp6,  subnetOptionsTreeKeaDhcp6 },
    { designExampleModel,          designExampleTree }
};

}  // namespace test
}  // namespace yang
}  // namespace isc

#endif // ISC_YANG_CONFIGS_H
