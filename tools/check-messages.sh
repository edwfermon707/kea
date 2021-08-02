#!/bin/sh

# Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

# Usage:
#
# ./tools/check-messages.sh [-a|--amend] [-d|--debug] [-h|--help]
#
# Run from anywhere to check the following in the repository this belongs to:
# * that there are no two messages with the same name
# * that there are no unused messages (run with -a to get rid of them)
# * that messages are only logged once (outside of an exhonerated list
# meant to only warn about new occurences of this type; the list was snapshotted
# in august 2021 and contains all multiple occurences prior to this date)

# shellcheck disable=SC3043
# SC3043: In POSIX sh, 'local' is undefined.

# shellcheck disable=SC2013
# SC2013: To read lines rather than words, pipe/redirect to a 'while read' loop.

# shellcheck disable=SC2044
# SC2044: For loops over find output are fragile. Use find -exec or a while read loop.

# Exit with error if commands exit with non-zero and if undefined variables are
# used.
set -eu

# Print usage.
print_usage() {
  printf \
'Usage: %s {{options}}
Options:
  [-d|--debug]                 enable debug mode, showing every executed command
  [-h|--help]                  print usage (this text)
  [-a|--amend]                 remove unused messages from message files and
                               add missing mentions of debug log levels in
                               message files
' \
    "$(basename "${0}")"
}

# Define some ANSI color codes.
if test -t 1; then
  red='\033[91m'
  reset='\033[0m'
else
  red=
  reset=
fi

# Parse parameters.
while test ${#} -gt 0; do
  case "${1}" in
    # [-d|--debug]                 enable debug mode, showing every executed command
    '-d'|'--debug') set -vx ;;

    # [-h|--help]                  print usage (this text)
    '-h'|'--help') print_usage; exit 0 ;;

    # [-a|--amend]                 remove unused messages from message files and
    #                              add missing mentions of debug log levels in
    #                              message files
    '-a'|'--amend') amend=true ;;

    # Unrecognized argument
    *)
    printf "${red}ERROR: Unrecognized argument '%s'${reset}\\n" "${1}" 1>&2; print_usage; exit 1 ;;
  esac; shift
done

# Default parameters
test -z "${amend+x}" && amend=false

# Change directory to root path.
root_path=$(cd "$(dirname "${0}")/.." && pwd)
cd "${root_path}"

# Check if given commands are available and if not, then warn the user that they
# need to be installed for the script to work and then exit with error code.
mandatory_commands() {
  while test ${#} -gt 0; do
    if ! command -v "${1}" > /dev/null 2>&1; then
      printf "${red}%s${reset} is mandatory.\\n" "${1}" >&2
      exit 3
    fi
    shift
  done
}

# Remove a given message from a given message file. Matches only the first
# occurrence.
remove_message() {
  local message="${1}"; shift
  local file="${1}"; shift

  start_pattern="^% ${message}"
  end_pattern='^%'

  # Remove with sed.
  sed "/${start_pattern}/,/${end_pattern}/{/${end_pattern}/!{/${end_pattern}/!d}}" "${file}" | grep -Ev "${start_pattern}" > "${file}.bak"
  mv "${file}.bak" "${file}"
}

is_message_exhonerated_from_being_logged_multiple_times() {
  grep "${*}" > /dev/null <<HERE_DOCUMENT
    ALLOC_ENGINE_V4_ALLOC_FAIL
    ALLOC_ENGINE_V4_ALLOC_FAIL_CLASSES
    ALLOC_ENGINE_V4_ALLOC_FAIL_NO_POOLS
    ALLOC_ENGINE_V4_ALLOC_FAIL_SHARED_NETWORK
    ALLOC_ENGINE_V4_ALLOC_FAIL_SUBNET
    ALLOC_ENGINE_V4_RECLAIMED_LEASES_DELETE
    ALLOC_ENGINE_V4_RECLAIMED_LEASES_DELETE_COMPLETE
    ALLOC_ENGINE_V4_RECLAIMED_LEASES_DELETE_FAILED
    ALLOC_ENGINE_V4_REQUEST_OUT_OF_POOL
    ALLOC_ENGINE_V6_ALLOC_FAIL
    ALLOC_ENGINE_V6_ALLOC_FAIL_NO_POOLS
    ALLOC_ENGINE_V6_ALLOC_FAIL_SHARED_NETWORK
    ALLOC_ENGINE_V6_ALLOC_FAIL_SUBNET
    ALLOC_ENGINE_V6_ALLOC_HR_LEASE_EXISTS
    ALLOC_ENGINE_V6_EXTEND_LEASE
    ALLOC_ENGINE_V6_EXTEND_LEASE_DATA
    ALLOC_ENGINE_V6_HR_ADDR_GRANTED
    ALLOC_ENGINE_V6_HR_PREFIX_GRANTED
    ALLOC_ENGINE_V6_RECLAIMED_LEASES_DELETE
    ALLOC_ENGINE_V6_RECLAIMED_LEASES_DELETE_COMPLETE
    ALLOC_ENGINE_V6_RECLAIMED_LEASES_DELETE_FAILED
    ASIODNS_OPEN_SOCKET
    ASIODNS_READ_DATA
    ASIODNS_SEND_DATA
    ASIODNS_UNKNOWN_ORIGIN
    BOOTP_PACKET_PACK
    BOOTP_PACKET_PACK_FAIL
    COMMAND_RECEIVED
    COMMAND_SOCKET_READ
    COMMAND_SOCKET_READ_FAIL
    COMMAND_SOCKET_WRITE
    COMMAND_SOCKET_WRITE_FAIL
    DATABASE_TO_JSON_ERROR
    DHCP4_CLASS_ASSIGNED
    DHCP4_CLIENT_HOSTNAME_DATA
    DHCP4_CONFIG_RECEIVED
    DHCP4_CONFIG_UNSUPPORTED_OBJECT
    DHCP4_DB_RECONNECT_NO_DB_CTL
    DHCP4_DECLINE_LEASE
    DHCP4_DECLINE_LEASE_MISMATCH
    DHCP4_DECLINE_LEASE_NOT_FOUND
    DHCP4_DHCP4O6_BAD_PACKET
    DHCP4_DHCP4O6_PACKET_SEND
    DHCP4_DHCP4O6_PACKET_SEND_FAIL
    DHCP4_DYNAMIC_RECONFIGURATION
    DHCP4_DYNAMIC_RECONFIGURATION_FAIL
    DHCP4_HOOK_BUFFER_SEND_SKIP
    DHCP4_HOOK_SUBNET4_SELECT_DROP
    DHCP4_HOOK_SUBNET4_SELECT_SKIP
    DHCP4_PACKET_DROP_0009
    DHCP4_PACKET_DROP_0011
    DHCP4_PACKET_DROP_0012
    DHCP4_PACKET_PACK
    DHCP4_PACKET_PACK_FAIL
    DHCP4_PACKET_PROCESS_EXCEPTION
    DHCP4_PACKET_PROCESS_STD_EXCEPTION
    DHCP4_PACKET_QUEUE_FULL
    DHCP4_PACKET_SEND
    DHCP4_PACKET_SEND_FAIL
    DHCP4_PARSER_COMMIT_FAIL
    DHCP4_RELEASE
    DHCP4_RELEASE_EXCEPTION
    DHCP4_RELEASE_FAIL
    DHCP4_RELEASE_FAIL_NO_LEASE
    DHCP4_RELEASE_FAIL_WRONG_CLIENT
    DHCP4_SHUTDOWN
    DHCP4_SHUTDOWN_REQUEST
    DHCP4_SUBNET_DATA
    DHCP4_SUBNET_SELECTED
    DHCP4_SUBNET_SELECTION_FAILED
    DHCP6_CLASS_ASSIGNED
    DHCP6_CONFIG_RECEIVED
    DHCP6_CONFIG_UNSUPPORTED_OBJECT
    DHCP6_DB_RECONNECT_NO_DB_CTL
    DHCP6_DECLINE_FAIL
    DHCP6_DECLINE_FAIL_DUID_MISMATCH
    DHCP6_DECLINE_FAIL_IAID_MISMATCH
    DHCP6_DECLINE_FAIL_LEASE_WITHOUT_DUID
    DHCP6_DECLINE_FAIL_NO_LEASE
    DHCP6_DYNAMIC_RECONFIGURATION
    DHCP6_DYNAMIC_RECONFIGURATION_FAIL
    DHCP6_HOOK_BUFFER_SEND_SKIP
    DHCP6_LEASE_ADVERT
    DHCP6_LEASE_ADVERT_FAIL
    DHCP6_LEASE_ALLOC
    DHCP6_LEASE_ALLOC_FAIL
    DHCP6_LEASE_REUSE
    DHCP6_PACKET_DROP_DROP_CLASS
    DHCP6_PACKET_DROP_DROP_CLASS2
    DHCP6_PACKET_DROP_DUPLICATE
    DHCP6_PACKET_PROCESS_EXCEPTION
    DHCP6_PACKET_PROCESS_STD_EXCEPTION
    DHCP6_PACKET_QUEUE_FULL
    DHCP6_PACKET_SEND
    DHCP6_PACKET_SEND_FAIL
    DHCP6_PARSER_COMMIT_FAIL
    DHCP6_PD_LEASE_ADVERT
    DHCP6_PD_LEASE_ADVERT_FAIL
    DHCP6_PD_LEASE_ALLOC
    DHCP6_PD_LEASE_ALLOC_FAIL
    DHCP6_PD_LEASE_REUSE
    DHCP6_RELEASE_NA
    DHCP6_RELEASE_NA_FAIL
    DHCP6_RELEASE_NA_FAIL_WRONG_DUID
    DHCP6_RELEASE_NA_FAIL_WRONG_IAID
    DHCP6_RELEASE_PD
    DHCP6_RELEASE_PD_FAIL
    DHCP6_RELEASE_PD_FAIL_WRONG_DUID
    DHCP6_RELEASE_PD_FAIL_WRONG_IAID
    DHCP6_RESPONSE_DATA
    DHCP6_SHUTDOWN
    DHCP6_SHUTDOWN_REQUEST
    DHCPSRV_CFGMGR_SUBNET4
    DHCPSRV_CFGMGR_SUBNET4_ADDR
    DHCPSRV_CFGMGR_SUBNET4_IFACE
    DHCPSRV_CFGMGR_SUBNET6
    DHCPSRV_CFGMGR_SUBNET6_IFACE
    DHCPSRV_CFGMGR_SUBNET6_IFACE_ID
    DHCPSRV_CFGMGR_SUBNET6_RELAY
    DHCPSRV_CQL_COMMIT
    DHCPSRV_CQL_DELETE_ADDR
    DHCPSRV_CQL_HOST_DB
    DHCPSRV_CQL_HOST_DB_GET_VERSION
    DHCPSRV_CQL_HOST_GET4
    DHCPSRV_CQL_HOST_GET6
    DHCPSRV_CQL_HOST_GET_ALL
    DHCPSRV_CQL_LEASE_EXCEPTION_THROWN
    DHCPSRV_CQL_ROLLBACK
    DHCPSRV_DEPRECATED
    DHCPSRV_DHCP4O6_RECEIVED_BAD_PACKET
    DHCPSRV_HOOK_LEASE4_SELECT_SKIP
    DHCPSRV_HOOK_LEASE6_SELECT_SKIP
    DHCPSRV_LEASE_SANITY_FAIL
    DHCPSRV_LEASE_SANITY_FAIL_DISCARD
    DHCPSRV_LEASE_SANITY_FIXED
    DHCPSRV_MEMFILE_DELETE_ADDR
    DHCPSRV_MEMFILE_GET6
    DHCPSRV_MEMFILE_GET6_DUID
    DHCPSRV_MEMFILE_LEASE_LOAD
    DHCPSRV_MEMFILE_LEASE_LOAD_ROW_ERROR
    DHCPSRV_MEMFILE_LFC_START
    DHCPSRV_MEMFILE_LFC_UNREGISTER_TIMER_FAILED
    DHCPSRV_MEMFILE_WIPE_LEASES4
    DHCPSRV_MEMFILE_WIPE_LEASES4_FINISHED
    DHCPSRV_MEMFILE_WIPE_LEASES6
    DHCPSRV_MEMFILE_WIPE_LEASES6_FINISHED
    DHCPSRV_MYSQL_DELETE_ADDR
    DHCPSRV_MYSQL_HOST_DB
    DHCPSRV_MYSQL_HOST_DB_GET_VERSION
    DHCPSRV_MYSQL_HOST_DB_READONLY
    DHCPSRV_MYSQL_HOST_DB_RECONNECT_ATTEMPT_FAILED
    DHCPSRV_MYSQL_HOST_DB_RECONNECT_ATTEMPT_SCHEDULE
    DHCPSRV_MYSQL_HOST_DB_RECONNECT_FAILED
    DHCPSRV_PGSQL_DELETE_ADDR
    DHCPSRV_PGSQL_HOST_DB
    DHCPSRV_PGSQL_HOST_DB_GET_VERSION
    DHCPSRV_PGSQL_HOST_DB_READONLY
    DHCPSRV_PGSQL_HOST_DB_RECONNECT_ATTEMPT_FAILED
    DHCPSRV_PGSQL_HOST_DB_RECONNECT_ATTEMPT_SCHEDULE
    DHCPSRV_PGSQL_HOST_DB_RECONNECT_FAILED
    DHCPSRV_QUEUE_NCR
    DHCPSRV_QUEUE_NCR_FAILED
    DHCPSRV_QUEUE_NCR_SKIP
    DHCPSRV_UNKNOWN_DB
    DHCP_DDNS_ADD_FAILED
    DHCP_DDNS_ADD_SUCCEEDED
    DHCP_DDNS_CONFIGURE
    DHCP_DDNS_CONFIGURED_CALLOUT_DROP
    DHCP_DDNS_FORWARD_ADD_BAD_DNSCLIENT_STATUS
    DHCP_DDNS_FORWARD_ADD_BUILD_FAILURE
    DHCP_DDNS_FORWARD_ADD_IO_ERROR
    DHCP_DDNS_FORWARD_ADD_REJECTED
    DHCP_DDNS_FORWARD_ADD_RESP_CORRUPT
    DHCP_DDNS_FORWARD_REMOVE_RRS_BAD_DNSCLIENT_STATUS
    DHCP_DDNS_FORWARD_REMOVE_RRS_BUILD_FAILURE
    DHCP_DDNS_FORWARD_REMOVE_RRS_IO_ERROR
    DHCP_DDNS_FORWARD_REMOVE_RRS_REJECTED
    DHCP_DDNS_FORWARD_REMOVE_RRS_RESP_CORRUPT
    DHCP_DDNS_REMOVE_FAILED
    DHCP_DDNS_REMOVE_SUCCEEDED
    DHCP_DDNS_REVERSE_REMOVE_BAD_DNSCLIENT_STATUS
    DHCP_DDNS_REVERSE_REMOVE_BUILD_FAILURE
    DHCP_DDNS_REVERSE_REMOVE_IO_ERROR
    DHCP_DDNS_REVERSE_REMOVE_REJECTED
    DHCP_DDNS_REVERSE_REMOVE_RESP_CORRUPT
    DHCP_DDNS_REVERSE_REPLACE_BAD_DNSCLIENT_STATUS
    DHCP_DDNS_REVERSE_REPLACE_BUILD_FAILURE
    DHCP_DDNS_REVERSE_REPLACE_IO_ERROR
    DHCP_DDNS_REVERSE_REPLACE_REJECTED
    DHCP_DDNS_REVERSE_REPLACE_RESP_CORRUPT
    DHCP_DDNS_UNCAUGHT_NCR_RECV_HANDLER_ERROR
    DHCP_DDNS_UNCAUGHT_NCR_SEND_HANDLER_ERROR
    EVAL_DEBUG_IPADDRESS
    EVAL_DEBUG_IPADDRESSTOTEXT
    EVAL_DEBUG_OPTION
    EVAL_DEBUG_PKT
    EVAL_DEBUG_PKT4
    EVAL_DEBUG_PKT6
    EVAL_DEBUG_RELAY6
    EVAL_DEBUG_RELAY6_RANGE
    EVAL_DEBUG_SUBSTRING
    EVAL_DEBUG_SUBSTRING_EMPTY
    EVAL_DEBUG_SUBSTRING_RANGE
    EVAL_DEBUG_SUB_OPTION
    EVAL_DEBUG_SUB_OPTION_NO_OPTION
    EVAL_DEBUG_VENDOR_CLASS_DATA
    EVAL_DEBUG_VENDOR_CLASS_DATA_NOT_FOUND
    EVAL_DEBUG_VENDOR_CLASS_ENTERPRISE_ID
    EVAL_DEBUG_VENDOR_CLASS_ENTERPRISE_ID_MISMATCH
    EVAL_DEBUG_VENDOR_ENTERPRISE_ID
    EVAL_DEBUG_VENDOR_ENTERPRISE_ID_MISMATCH
    EVAL_RESULT
    FLEX_OPTION_PROCESS_ERROR
    FUZZ_SEND
    FUZZ_SEND_ERROR
    HA_COMMUNICATION_INTERRUPTED
    HA_COMMUNICATION_INTERRUPTED_CLIENT4
    HA_COMMUNICATION_INTERRUPTED_CLIENT4_UNACKED
    HA_COMMUNICATION_INTERRUPTED_CLIENT6
    HA_COMMUNICATION_INTERRUPTED_CLIENT6_UNACKED
    HA_CONFIG_LEASE_SYNCING_DISABLED
    HA_CONFIG_LEASE_SYNCING_DISABLED_REMINDER
    HA_CONFIG_LEASE_UPDATES_DISABLED
    HA_CONFIG_LEASE_UPDATES_DISABLED_REMINDER
    HA_HIGH_CLOCK_SKEW
    HA_HIGH_CLOCK_SKEW_CAUSES_TERMINATION
    HA_MAINTENANCE_STARTED
    HA_MAINTENANCE_STARTED_IN_PARTNER_DOWN
    HA_STATE_TRANSITION
    HA_STATE_TRANSITION_PASSIVE_BACKUP
    HA_TERMINATED
    HA_TERMINATED_RESTART_PARTNER
    HOSTS_CFG_CLOSE_HOST_DATA_SOURCE
    HOSTS_CFG_GET_ALL
    HOSTS_CFG_GET_ALL_ADDRESS4
    HOSTS_CFG_GET_ALL_ADDRESS4_COUNT
    HOSTS_CFG_GET_ALL_ADDRESS4_HOST
    HOSTS_CFG_GET_ALL_ADDRESS6
    HOSTS_CFG_GET_ALL_ADDRESS6_COUNT
    HOSTS_CFG_GET_ALL_ADDRESS6_HOST
    HOSTS_CFG_GET_ALL_COUNT
    HOSTS_CFG_GET_ALL_HOST
    HOSTS_CFG_GET_ALL_HOSTNAME
    HOSTS_CFG_GET_ALL_HOSTNAME_COUNT
    HOSTS_CFG_GET_ALL_HOSTNAME_HOST
    HOSTS_CFG_GET_ALL_HOSTNAME_SUBNET_ID4
    HOSTS_CFG_GET_ALL_HOSTNAME_SUBNET_ID4_COUNT
    HOSTS_CFG_GET_ALL_HOSTNAME_SUBNET_ID4_HOST
    HOSTS_CFG_GET_ALL_HOSTNAME_SUBNET_ID6
    HOSTS_CFG_GET_ALL_HOSTNAME_SUBNET_ID6_COUNT
    HOSTS_CFG_GET_ALL_HOSTNAME_SUBNET_ID6_HOST
    HOSTS_CFG_GET_ALL_IDENTIFIER
    HOSTS_CFG_GET_ALL_IDENTIFIER_COUNT
    HOSTS_CFG_GET_ALL_IDENTIFIER_HOST
    HOSTS_CFG_GET_ALL_SUBNET_ID4
    HOSTS_CFG_GET_ALL_SUBNET_ID4_COUNT
    HOSTS_CFG_GET_ALL_SUBNET_ID4_HOST
    HOSTS_CFG_GET_ALL_SUBNET_ID6
    HOSTS_CFG_GET_ALL_SUBNET_ID6_COUNT
    HOSTS_CFG_GET_ALL_SUBNET_ID6_HOST
    HOSTS_CFG_GET_ALL_SUBNET_ID_ADDRESS4
    HOSTS_CFG_GET_ALL_SUBNET_ID_ADDRESS4_COUNT
    HOSTS_CFG_GET_ALL_SUBNET_ID_ADDRESS4_HOST
    HOSTS_CFG_GET_ALL_SUBNET_ID_ADDRESS6
    HOSTS_CFG_GET_ALL_SUBNET_ID_ADDRESS6_COUNT
    HOSTS_CFG_GET_ALL_SUBNET_ID_ADDRESS6_HOST
    HOSTS_CFG_GET_ONE_PREFIX
    HOSTS_CFG_GET_ONE_PREFIX_HOST
    HOSTS_CFG_GET_ONE_PREFIX_NULL
    HOSTS_CFG_GET_ONE_SUBNET_ID_ADDRESS4
    HOSTS_CFG_GET_ONE_SUBNET_ID_ADDRESS4_HOST
    HOSTS_CFG_GET_ONE_SUBNET_ID_ADDRESS4_NULL
    HOSTS_CFG_GET_ONE_SUBNET_ID_ADDRESS6
    HOSTS_CFG_GET_ONE_SUBNET_ID_ADDRESS6_HOST
    HOSTS_CFG_GET_ONE_SUBNET_ID_ADDRESS6_NULL
    HOSTS_CFG_GET_ONE_SUBNET_ID_IDENTIFIER
    HOSTS_CFG_GET_ONE_SUBNET_ID_IDENTIFIER_HOST
    HOSTS_CFG_GET_ONE_SUBNET_ID_IDENTIFIER_NULL
    HOSTS_MGR_ALTERNATE_GET4_SUBNET_ID_IDENTIFIER
    HOSTS_MGR_ALTERNATE_GET4_SUBNET_ID_IDENTIFIER_HOST
    HOSTS_MGR_ALTERNATE_GET4_SUBNET_ID_IDENTIFIER_NULL
    HOSTS_MGR_ALTERNATE_GET6_SUBNET_ID_IDENTIFIER
    HOSTS_MGR_ALTERNATE_GET6_SUBNET_ID_IDENTIFIER_HOST
    HOSTS_MGR_ALTERNATE_GET6_SUBNET_ID_IDENTIFIER_NULL
    HTTP_BAD_CLIENT_REQUEST_RECEIVED
    HTTP_BAD_CLIENT_REQUEST_RECEIVED_DETAILS
    HTTP_BAD_SERVER_RESPONSE_RECEIVED
    HTTP_BAD_SERVER_RESPONSE_RECEIVED_DETAILS
    HTTP_CLIENT_REQUEST_RECEIVED
    HTTP_CLIENT_REQUEST_RECEIVED_DETAILS
    HTTP_CLIENT_REQUEST_SEND
    HTTP_CLIENT_REQUEST_SEND_DETAILS
    HTTP_CONNECTION_HANDSHAKE_FAILED
    HTTP_CONNECTION_SHUTDOWN
    HTTP_CONNECTION_SHUTDOWN_FAILED
    HTTP_CONNECTION_STOP
    HTTP_CONNECTION_STOP_FAILED
    HTTP_SERVER_RESPONSE_RECEIVED
    HTTP_SERVER_RESPONSE_RECEIVED_DETAILS
    HTTP_SERVER_RESPONSE_SEND
    HTTP_SERVER_RESPONSE_SEND_DETAILS
    LEASE_CMDS_ADD4
    LEASE_CMDS_ADD4_FAILED
    LEASE_CMDS_ADD6
    LEASE_CMDS_ADD6_FAILED
    LEASE_CMDS_RESEND_DDNS4
    LEASE_CMDS_RESEND_DDNS4_FAILED
    LEASE_CMDS_RESEND_DDNS6
    LEASE_CMDS_RESEND_DDNS6_FAILED
    LFC_START
    LOG_BAD_DESTINATION
    LOG_BAD_SEVERITY
    LOG_NO_MESSAGE_TEXT
    LOG_OPEN_OUTPUT_FAIL
    LOG_UNRECOGNIZED_DIRECTIVE
    LOG_WRITE_ERROR
    MYSQL_CB_DELETE_ALL_CLIENT_CLASSES4
    MYSQL_CB_DELETE_ALL_CLIENT_CLASSES4_RESULT
    MYSQL_CB_DELETE_ALL_CLIENT_CLASSES6
    MYSQL_CB_DELETE_ALL_CLIENT_CLASSES6_RESULT
    MYSQL_CB_DELETE_ALL_GLOBAL_PARAMETERS4
    MYSQL_CB_DELETE_ALL_GLOBAL_PARAMETERS4_RESULT
    MYSQL_CB_DELETE_ALL_GLOBAL_PARAMETERS6
    MYSQL_CB_DELETE_ALL_GLOBAL_PARAMETERS6_RESULT
    MYSQL_CB_DELETE_ALL_OPTION_DEFS4
    MYSQL_CB_DELETE_ALL_OPTION_DEFS4_RESULT
    MYSQL_CB_DELETE_ALL_OPTION_DEFS6
    MYSQL_CB_DELETE_ALL_OPTION_DEFS6_RESULT
    MYSQL_CB_DELETE_ALL_SERVERS4
    MYSQL_CB_DELETE_ALL_SERVERS4_RESULT
    MYSQL_CB_DELETE_ALL_SERVERS6
    MYSQL_CB_DELETE_ALL_SERVERS6_RESULT
    MYSQL_CB_DELETE_ALL_SHARED_NETWORKS4
    MYSQL_CB_DELETE_ALL_SHARED_NETWORKS4_RESULT
    MYSQL_CB_DELETE_ALL_SHARED_NETWORKS6
    MYSQL_CB_DELETE_ALL_SHARED_NETWORKS6_RESULT
    MYSQL_CB_DELETE_ALL_SUBNETS4
    MYSQL_CB_DELETE_ALL_SUBNETS4_RESULT
    MYSQL_CB_DELETE_ALL_SUBNETS6
    MYSQL_CB_DELETE_ALL_SUBNETS6_RESULT
    MYSQL_CB_DELETE_BY_POOL_OPTION4
    MYSQL_CB_DELETE_BY_POOL_OPTION4_RESULT
    MYSQL_CB_DELETE_BY_POOL_OPTION6
    MYSQL_CB_DELETE_BY_POOL_OPTION6_RESULT
    MYSQL_CB_DELETE_BY_POOL_PREFIX_OPTION6
    MYSQL_CB_DELETE_BY_POOL_PREFIX_OPTION6_RESULT
    MYSQL_CB_DELETE_BY_PREFIX_SUBNET4
    MYSQL_CB_DELETE_BY_PREFIX_SUBNET4_RESULT
    MYSQL_CB_DELETE_BY_PREFIX_SUBNET6
    MYSQL_CB_DELETE_BY_PREFIX_SUBNET6_RESULT
    MYSQL_CB_DELETE_BY_SUBNET_ID_OPTION4
    MYSQL_CB_DELETE_BY_SUBNET_ID_OPTION4_RESULT
    MYSQL_CB_DELETE_BY_SUBNET_ID_OPTION6
    MYSQL_CB_DELETE_BY_SUBNET_ID_OPTION6_RESULT
    MYSQL_CB_DELETE_BY_SUBNET_ID_SUBNET4
    MYSQL_CB_DELETE_BY_SUBNET_ID_SUBNET4_RESULT
    MYSQL_CB_DELETE_BY_SUBNET_ID_SUBNET6
    MYSQL_CB_DELETE_BY_SUBNET_ID_SUBNET6_RESULT
    MYSQL_CB_DELETE_CLIENT_CLASS4
    MYSQL_CB_DELETE_CLIENT_CLASS4_RESULT
    MYSQL_CB_DELETE_CLIENT_CLASS6
    MYSQL_CB_DELETE_CLIENT_CLASS6_RESULT
    MYSQL_CB_DELETE_GLOBAL_PARAMETER4
    MYSQL_CB_DELETE_GLOBAL_PARAMETER4_RESULT
    MYSQL_CB_DELETE_GLOBAL_PARAMETER6
    MYSQL_CB_DELETE_GLOBAL_PARAMETER6_RESULT
    MYSQL_CB_DELETE_OPTION4
    MYSQL_CB_DELETE_OPTION4_RESULT
    MYSQL_CB_DELETE_OPTION6
    MYSQL_CB_DELETE_OPTION6_RESULT
    MYSQL_CB_DELETE_OPTION_DEF4
    MYSQL_CB_DELETE_OPTION_DEF4_RESULT
    MYSQL_CB_DELETE_OPTION_DEF6
    MYSQL_CB_DELETE_OPTION_DEF6_RESULT
    MYSQL_CB_DELETE_SERVER4
    MYSQL_CB_DELETE_SERVER4_RESULT
    MYSQL_CB_DELETE_SERVER6
    MYSQL_CB_DELETE_SERVER6_RESULT
    MYSQL_CB_DELETE_SHARED_NETWORK4
    MYSQL_CB_DELETE_SHARED_NETWORK4_RESULT
    MYSQL_CB_DELETE_SHARED_NETWORK6
    MYSQL_CB_DELETE_SHARED_NETWORK6_RESULT
    MYSQL_CB_DELETE_SHARED_NETWORK_OPTION4
    MYSQL_CB_DELETE_SHARED_NETWORK_OPTION4_RESULT
    MYSQL_CB_DELETE_SHARED_NETWORK_OPTION6
    MYSQL_CB_DELETE_SHARED_NETWORK_OPTION6_RESULT
    MYSQL_CB_DELETE_SHARED_NETWORK_SUBNETS4
    MYSQL_CB_DELETE_SHARED_NETWORK_SUBNETS4_RESULT
    MYSQL_CB_DELETE_SHARED_NETWORK_SUBNETS6
    MYSQL_CB_DELETE_SHARED_NETWORK_SUBNETS6_RESULT
    MYSQL_CB_GET_ALL_CLIENT_CLASSES4
    MYSQL_CB_GET_ALL_CLIENT_CLASSES4_RESULT
    MYSQL_CB_GET_ALL_CLIENT_CLASSES6
    MYSQL_CB_GET_ALL_CLIENT_CLASSES6_RESULT
    MYSQL_CB_GET_ALL_GLOBAL_PARAMETERS4
    MYSQL_CB_GET_ALL_GLOBAL_PARAMETERS4_RESULT
    MYSQL_CB_GET_ALL_GLOBAL_PARAMETERS6
    MYSQL_CB_GET_ALL_GLOBAL_PARAMETERS6_RESULT
    MYSQL_CB_GET_ALL_OPTIONS4
    MYSQL_CB_GET_ALL_OPTIONS4_RESULT
    MYSQL_CB_GET_ALL_OPTIONS6
    MYSQL_CB_GET_ALL_OPTIONS6_RESULT
    MYSQL_CB_GET_ALL_OPTION_DEFS4
    MYSQL_CB_GET_ALL_OPTION_DEFS4_RESULT
    MYSQL_CB_GET_ALL_OPTION_DEFS6
    MYSQL_CB_GET_ALL_OPTION_DEFS6_RESULT
    MYSQL_CB_GET_ALL_SERVERS4
    MYSQL_CB_GET_ALL_SERVERS4_RESULT
    MYSQL_CB_GET_ALL_SERVERS6
    MYSQL_CB_GET_ALL_SERVERS6_RESULT
    MYSQL_CB_GET_ALL_SHARED_NETWORKS4
    MYSQL_CB_GET_ALL_SHARED_NETWORKS4_RESULT
    MYSQL_CB_GET_ALL_SHARED_NETWORKS6
    MYSQL_CB_GET_ALL_SHARED_NETWORKS6_RESULT
    MYSQL_CB_GET_ALL_SUBNETS4
    MYSQL_CB_GET_ALL_SUBNETS4_RESULT
    MYSQL_CB_GET_ALL_SUBNETS6
    MYSQL_CB_GET_ALL_SUBNETS6_RESULT
    MYSQL_CB_GET_MODIFIED_CLIENT_CLASSES4
    MYSQL_CB_GET_MODIFIED_CLIENT_CLASSES4_RESULT
    MYSQL_CB_GET_MODIFIED_CLIENT_CLASSES6
    MYSQL_CB_GET_MODIFIED_CLIENT_CLASSES6_RESULT
    MYSQL_CB_GET_MODIFIED_GLOBAL_PARAMETERS4
    MYSQL_CB_GET_MODIFIED_GLOBAL_PARAMETERS4_RESULT
    MYSQL_CB_GET_MODIFIED_GLOBAL_PARAMETERS6
    MYSQL_CB_GET_MODIFIED_GLOBAL_PARAMETERS6_RESULT
    MYSQL_CB_GET_MODIFIED_OPTIONS4
    MYSQL_CB_GET_MODIFIED_OPTIONS4_RESULT
    MYSQL_CB_GET_MODIFIED_OPTIONS6
    MYSQL_CB_GET_MODIFIED_OPTIONS6_RESULT
    MYSQL_CB_GET_MODIFIED_OPTION_DEFS4
    MYSQL_CB_GET_MODIFIED_OPTION_DEFS4_RESULT
    MYSQL_CB_GET_MODIFIED_OPTION_DEFS6
    MYSQL_CB_GET_MODIFIED_OPTION_DEFS6_RESULT
    MYSQL_CB_GET_MODIFIED_SHARED_NETWORKS4
    MYSQL_CB_GET_MODIFIED_SHARED_NETWORKS4_RESULT
    MYSQL_CB_GET_MODIFIED_SHARED_NETWORKS6
    MYSQL_CB_GET_MODIFIED_SHARED_NETWORKS6_RESULT
    MYSQL_CB_GET_MODIFIED_SUBNETS4
    MYSQL_CB_GET_MODIFIED_SUBNETS4_RESULT
    MYSQL_CB_GET_MODIFIED_SUBNETS6
    MYSQL_CB_GET_MODIFIED_SUBNETS6_RESULT
    MYSQL_CB_GET_RECENT_AUDIT_ENTRIES4
    MYSQL_CB_GET_RECENT_AUDIT_ENTRIES4_RESULT
    MYSQL_CB_GET_RECENT_AUDIT_ENTRIES6
    MYSQL_CB_GET_RECENT_AUDIT_ENTRIES6_RESULT
    MYSQL_CB_GET_SHARED_NETWORK_SUBNETS4
    MYSQL_CB_GET_SHARED_NETWORK_SUBNETS4_RESULT
    MYSQL_CB_GET_SHARED_NETWORK_SUBNETS6
    MYSQL_CB_GET_SHARED_NETWORK_SUBNETS6_RESULT
    NETCONF_CONFIG_CHANGED_DETAIL
    NETCONF_GET_CONFIG
    NETCONF_GET_CONFIG_FAILED
    NETCONF_GET_CONFIG_STARTED
    NETCONF_LOG_CHANGE_FAIL
    NETCONF_SET_CONFIG
    NETCONF_SET_CONFIG_FAILED
    NETCONF_SET_CONFIG_STARTED
    NETCONF_SUBSCRIBE_CONFIG
    NETCONF_SUBSCRIBE_CONFIG_FAILED
    NETCONF_SUBSCRIBE_NOTIFICATIONS
    NETCONF_SUBSCRIBE_NOTIFICATIONS_FAILED
    NETCONF_UPDATE_CONFIG
    NETCONF_UPDATE_CONFIG_COMPLETED
    NETCONF_UPDATE_CONFIG_FAILED
    NETCONF_UPDATE_CONFIG_STARTED
    NETCONF_VALIDATE_CONFIG
    NETCONF_VALIDATE_CONFIG_COMPLETED
    NETCONF_VALIDATE_CONFIG_FAILED
    NETCONF_VALIDATE_CONFIG_REJECTED
    NETCONF_VALIDATE_CONFIG_STARTED
    RUN_SCRIPT_LOAD
    RUN_SCRIPT_LOAD_ERROR
    STAT_CMDS_LEASE4_GET
    STAT_CMDS_LEASE4_GET_FAILED
    STAT_CMDS_LEASE4_GET_INVALID
    STAT_CMDS_LEASE4_GET_NO_SUBNETS
    STAT_CMDS_LEASE6_GET
    STAT_CMDS_LEASE6_GET_FAILED
    STAT_CMDS_LEASE6_GET_INVALID
    STAT_CMDS_LEASE6_GET_NO_SUBNETS

    DCTL_CONFIG_FILE_LOAD_FAIL
    DCTL_UNSUPPORTED_SIGNAL
    HOST_CACHE_GET_ONE_SUBNET_ID_IDENTIFIER
    HOST_CACHE_GET_ONE_SUBNET_ID_IDENTIFIER_HOST
    HOST_CMDS_RESERV_ADD
    LEGAL_LOG_LOAD_ERROR
    RADIUS_ACCESS_BUILD_FAILED
    RADIUS_ACCESS_CACHE_GET
    RADIUS_ACCESS_CACHE_INSERT
    RADIUS_ACCESS_ERROR
    RADIUS_ACCESS_GET_IDENTIFIER
    RADIUS_ACCESS_GET_IDENTIFIER_FAILED
    RADIUS_ACCESS_NO_HOST_CACHE
    RADIUS_ACCESS_SUBNET_RESELECT
    RADIUS_AUTHENTICATION
    RADIUS_AUTHENTICATION_ACCEPTED
    RADIUS_AUTHENTICATION_FAILED
    RADIUS_AUTHENTICATION_REJECTED
    RADIUS_HOOK_FAILED
    RADIUS_SESSION_HISTORY_APPEND_FAILED
HERE_DOCUMENT
}

mandatory_commands cut find grep sed sort

mistake=false

# For all the message files:
for message_file in $(find . -type f -name '*.mes' | sort -uV); do
  printf 'Checking %s...\n' "$(basename "${message_file}")"

  # For all the messages in a message file:
  for message in $(grep -E '^%' "${message_file}" | cut -d ' ' -f 2); do

    # Get all occurences.
    occurences="$(grep -EIR "\b${message}\b" "${root_path}"/* | grep -Fv '.git')"

    # Check for duplicate message names.
    occurences_in_message_files="$(printf '%s\n' "${occurences}" | grep "% ${message}\b" | grep -E 'messages\.mes:' || true)"
    occurence_count="$(printf '%s\n' "${occurences_in_message_files}" | wc -l)"
    if test -z "${occurence_count}"; then
      printf 'ERROR: could not find number of occurences for message %s. Fix this in the script.\n' "${message}"
      exit 2
    fi
    if test "${occurence_count}" -ne 1; then
      printf "${red}%% expected %s to be found in one message file, but it is found in %s.${reset}\\n" "${message}" "${occurence_count}"
      mistake=true
    fi

    # Get occurences that appear in code.
    occurences_in_sources="$(printf '%s\n' "${occurences}" | grep -E '\.cc:|\.h:' | grep -Ev 'messages\.cc:|messages\.h|test' || true)"
    occurence_count="$(printf '%s\n' "${occurences_in_sources}" | wc -l)"
    if test -z "${occurence_count}"; then
      printf 'ERROR: could not find number of occurences for message %s. Fix this in the script.\n' "${message}"
      exit 2
    fi

    # If not found in any source file, print it for the developer to take action.
    if test "${occurence_count}" -eq 0; then
      printf "${red}%% %s is not used.${reset}\\n" "${message}"
      mistake=true

      # If the caller decided to amend the message files, then remove the unused
      # message.
      if "${amend}"; then
        remove_message "${message}" "${message_file}"
      fi

    # If found multiple times and it is due to a recent change, print it for the developer to take
    # action.
    elif test "${occurence_count}" -gt 1; then
      if ! is_message_exhonerated_from_being_logged_multiple_times "${message}"; then
        printf "${red}%% %s is used %s times${reset}:\n%s\n\n" "${message}" "${occurence_count}" "${occurences_in_sources}"
        mistake=true
      fi
    fi

    # For this iterated message, iterate further through all the occurences in
    # sources mainly find the log level used so that you can check further if it
    # is mentioned in its .mes file.
    for i in $(printf '%s\n' "${occurences_in_sources}" | cut -d ':' -f 1); do

      # Get the log level used in sources and make sure a single log level is
      # used everywhere.
      loglevel="$(tr -s '\n' ' ' < "${i}" | grep -Po "LOG_DEBUG[^;]*?\b${message}\b" | cut -d ',' -f 2 | sed 's/.*:://g' | sed 's/^ *//g;s/ *$//g' | sort -uV || true)"
      if test -z "${loglevel}"; then
        # A log level could not be found. This most probably means that this
        # message is not logged as a debug message, but as an info, warning, or
        # error message. In that case a log level is not required. So skip this occurrence.
        continue
      fi
      lines="$(printf '%s\n' "${loglevel}" | wc -l)"
      if test "${lines}" != 1; then
        printf "${red}%% message %s logged under %s different debug levels: \n%s${reset}\n\n" "${message}" "${lines}" "${loglevel}" >&2
        mistake=true
        continue
      fi

      # Resolve log level variable names into numerals. This may require
      # multiple recursions e.g. DBG_DHCP6_BASIC -> DBGLVL_TRACE_BASIC -> 40.
      # If 16 recursions are reached, stop and return an error so that either
      # this script or complex C++ definitions of these log levels (like this
      # previous one: const int DBG_ALL = DBGLVL_TRACE_DETAIL + 20) may be
      # fixed.
      recursions=16
      while test "$(printf '%s\n' "${loglevel}" | grep -Ec '^[0-9]+$')" != 1; do
        loglevel_define_file="$(grep -EIR "\b${loglevel}\b =" "${root_path}"/* | grep -Fv '.git' | cut -d ':' -f 1)"
        lines="$(printf '%s\n' "${loglevel_define_file}" | wc -l)"
        if test "${lines}" != 1; then
          printf "${red}%% found %s files instead of 1 when searching for the numeral version of debug log level %s which message %s is logged under${reset}\n\n" "${lines}" "${loglevel}" "${message}" >&2
          mistake=true
          continue
        fi
        loglevel="$(tr -s '\n' ' ' < "${loglevel_define_file}" | grep -Po "\b${loglevel}\b =[^;]+?;" | cut -d '=' -f 2 | cut -d ';' -f 1 | sed 's/.*:://g' | sed 's/^ *//g;s/ *$//g')"
        recursions=$((recursions - 1))
        if test "${recursions}" = 0; then
          printf "${red}%% could not find log level of message %s after 16 recursions. Breaking endless loop...${reset}\n\n" "${message}" >&2
          mistake=true
          break
        fi
      done

      # Finally, do the actual check of the line being mentioned in the .mes
      # file.
      message_file=$(printf '%s\n' "${occurences_in_message_files}" | cut -d ':' -f 1 | sort -uV)
      logged_at_message="Logged at debug log level ${loglevel}."
      if test "$(grep -F -A1 "${message}" "${message_file}" | grep -Ec "^${logged_at_message}$")" = 0; then
        printf "${red}%% debug level %s is not mentioned for message %s in %s${reset}\n\n" "${loglevel}" "${message}" "${message_file}"
        mistake=true

        # And if amendment is commanded by the user...
        if "${amend}"; then
          # Delete any different log level, it has changed in the meantime.
          if test "$(grep -F -A1 "${message}" "${message_file}" | grep -Ec '^Logged at debug log level ')" -gt 0; then
            line_number="$(grep -En "\b${message}\b" "${message_file}" | cut -d ':' -f 1)"
            line_number="$(( line_number + 1 ))"
            sed "${line_number}d" "${message_file}" > "${message_file}.tmp"
          fi
          # And add the right one.
          sed "/^% ${message}/a Logged at debug log level ${loglevel}." "${message_file}" > "${message_file}.tmp"
          mv "${message_file}.tmp" "${message_file}"
        fi
      fi
    done
  done
done

# exit 1 if any unused message was found so that CI properly fails.
if "${mistake}"; then
  exit 1
fi
