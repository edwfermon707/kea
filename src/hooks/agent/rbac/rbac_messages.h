// File created from ../../../../src/hooks/agent/rbac/rbac_messages.mes

#ifndef RBAC_MESSAGES_H
#define RBAC_MESSAGES_H

#include <log/message_types.h>

extern const isc::log::MessageID RBAC_AUTH_ERROR;
extern const isc::log::MessageID RBAC_AUTH_RESPONSE;
extern const isc::log::MessageID RBAC_CONFIGURED_ACLS;
extern const isc::log::MessageID RBAC_CONFIGURED_COMMANDS;
extern const isc::log::MessageID RBAC_CONFIGURED_ROLES;
extern const isc::log::MessageID RBAC_LOAD_FAILED;
extern const isc::log::MessageID RBAC_LOAD_OK;
extern const isc::log::MessageID RBAC_READ_API_FILES;
extern const isc::log::MessageID RBAC_TRACE_AUTH_ACCEPT;
extern const isc::log::MessageID RBAC_TRACE_AUTH_BAD_BODY_TYPE;
extern const isc::log::MessageID RBAC_TRACE_AUTH_BAD_COMMAND_TYPE;
extern const isc::log::MessageID RBAC_TRACE_AUTH_COMMAND;
extern const isc::log::MessageID RBAC_TRACE_AUTH_DISABLED;
extern const isc::log::MessageID RBAC_TRACE_AUTH_EMPTY_BODY;
extern const isc::log::MessageID RBAC_TRACE_AUTH_NO_COMMAND;
extern const isc::log::MessageID RBAC_TRACE_AUTH_NO_JSON;
extern const isc::log::MessageID RBAC_TRACE_AUTH_NO_REQUEST;
extern const isc::log::MessageID RBAC_TRACE_AUTH_NO_TLS_REJECT;
extern const isc::log::MessageID RBAC_TRACE_AUTH_REJECT;
extern const isc::log::MessageID RBAC_TRACE_AUTH_RESPONSE;
extern const isc::log::MessageID RBAC_TRACE_AUTH_ROLE;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_BAD_BODY_TYPE;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_CONTEXT;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_DISABLED;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_EMPTY_BODY;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_EMPTY_BODY_LIST;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_MODIFIED;
extern const isc::log::MessageID RBAC_TRACE_RESPONSE_NO_ARGUMENTS;
extern const isc::log::MessageID RBAC_UNLOAD_OK;

#endif // RBAC_MESSAGES_H
