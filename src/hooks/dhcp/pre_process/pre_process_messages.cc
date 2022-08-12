// File created from ../../../../src/hooks/dhcp/pre_process/pre_process_messages.mes

#include <cstddef>
#include <log/message_types.h>
#include <log/message_initializer.h>

extern const isc::log::MessageID PRE_PROCESS_LOAD_ERROR = "PRE_PROCESS_LOAD_ERROR";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_ADD = "PRE_PROCESS_PROCESS_ADD";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_ERROR = "PRE_PROCESS_PROCESS_ERROR";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_REMOVE = "PRE_PROCESS_PROCESS_REMOVE";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_SUB_ADD = "PRE_PROCESS_PROCESS_SUB_ADD";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_SUB_CLIENT_CLASS = "PRE_PROCESS_PROCESS_SUB_CLIENT_CLASS";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_SUB_REMOVE = "PRE_PROCESS_PROCESS_SUB_REMOVE";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_SUB_SUPERSEDE = "PRE_PROCESS_PROCESS_SUB_SUPERSEDE";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_SUPERSEDE = "PRE_PROCESS_PROCESS_SUPERSEDE";
extern const isc::log::MessageID PRE_PROCESS_PROCESS_VENDOR_ID_MISMATCH = "PRE_PROCESS_PROCESS_VENDOR_ID_MISMATCH";
extern const isc::log::MessageID PRE_PROCESS_UNLOAD = "PRE_PROCESS_UNLOAD";

namespace {

const char* values[] = {
    "PRE_PROCESS_LOAD_ERROR", "loading Pre Process hooks library failed: %1",
    "PRE_PROCESS_PROCESS_ADD", "Added the option code %1 with value %2",
    "PRE_PROCESS_PROCESS_ERROR", "An error occurred processing query %1: %2",
    "PRE_PROCESS_PROCESS_REMOVE", "Removed option code %1",
    "PRE_PROCESS_PROCESS_SUB_ADD", "Added the sub-option code %1 in option code %2 with value %3",
    "PRE_PROCESS_PROCESS_SUB_CLIENT_CLASS", "Skip processing of the sub-option code %1 in option code %2 for class '%3'",
    "PRE_PROCESS_PROCESS_SUB_REMOVE", "Removed sub-option code %1 in option code %2",
    "PRE_PROCESS_PROCESS_SUB_SUPERSEDE", "Supersedes the sub-option code %1 in option code %2 with value %3",
    "PRE_PROCESS_PROCESS_SUPERSEDE", "Supersedes the option code %1 with value %2",
    "PRE_PROCESS_PROCESS_VENDOR_ID_MISMATCH", "Skip processing of vendor option code %1 with vendor id %2 not matching wanted %3",
    "PRE_PROCESS_UNLOAD", "Pre Process hooks library has been unloaded",
    NULL
};

const isc::log::MessageInitializer initializer(values);

} // Anonymous namespace

