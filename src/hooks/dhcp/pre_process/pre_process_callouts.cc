// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <pre_process.h>
#include <pre_process_log.h>
#include <cc/command_interpreter.h>
#include <hooks/hooks.h>
#include <dhcp/pkt4.h>
#include <dhcp/pkt6.h>
#include <dhcpsrv/cfgmgr.h>
#include <process/daemon.h>

namespace isc {
namespace pre_process {

PreProcessImplPtr impl;

} // end of namespace pre_process
} // end of namespace isc

using namespace isc;
using namespace isc::data;
using namespace isc::dhcp;
using namespace isc::pre_process;
using namespace isc::hooks;
using namespace isc::process;

// Functions accessed by the hooks framework use C linkage to avoid the name
// mangling that accompanies use of the C++ compiler as well as to avoid
// issues related to namespaces.
extern "C" {

/// @brief This callout is called at the "pkt4_receive" hook.
///
/// It retrieves v4 query packet, and then adds, supersedes or removes
/// option values in the query according to evaluated expressions.
///
/// @param handle CalloutHandle.
///
/// @return 0 upon success, non-zero otherwise
int pkt4_receive(CalloutHandle& handle) {
    CalloutHandle::CalloutNextStep status = handle.getStatus();
    if ((status == CalloutHandle::NEXT_STEP_SKIP) ||
        (status == CalloutHandle::NEXT_STEP_DROP)) {
        return (0);
    }

    // Sanity.
    if (!impl) {
        return (0);
    }

    // Get the parameters.
    Pkt4Ptr query;
    handle.getArgument("query4", query);

    try {
        impl->process<Pkt4Ptr>(Option::V4, query);
    } catch (const std::exception& ex) {
        LOG_ERROR(pre_process_logger, PRE_PROCESS_PROCESS_ERROR)
            .arg(query->getLabel())
            .arg(ex.what());
    }

    return (0);
}

/// @brief This callout is called at the "pkt6_receive" hook.
///
/// It retrieves v6 query packet, and then adds, supersedes or removes
/// option values in the query according to evaluated expressions.
///
/// @param handle CalloutHandle.
///
/// @return 0 upon success, non-zero otherwise
int pkt6_receive(CalloutHandle& handle) {
    CalloutHandle::CalloutNextStep status = handle.getStatus();
    if ((status == CalloutHandle::NEXT_STEP_SKIP) ||
        (status == CalloutHandle::NEXT_STEP_DROP)) {
        return (0);
    }

    // Sanity.
    if (!impl) {
        return (0);
    }

    // Get the parameters.
    Pkt6Ptr query;
    handle.getArgument("query6", query);

    try {
        impl->process<Pkt6Ptr>(Option::V6, query);
    } catch (const std::exception& ex) {
        LOG_ERROR(pre_process_logger, PRE_PROCESS_PROCESS_ERROR)
            .arg(query->getLabel())
            .arg(ex.what());
    }

    return (0);
}

/// @brief This function is called when the library is loaded.
///
/// @param handle library handle
/// @return 0 when initialization is successful, 1 otherwise
int load(LibraryHandle& handle) {
    try {
        // Make the hook library not loadable by d2 or ca.
        uint16_t family = CfgMgr::instance().getFamily();
        const std::string& proc_name = Daemon::getProcName();
        if (family == AF_INET) {
            if (proc_name != "kea-dhcp4") {
                isc_throw(isc::Unexpected, "Bad process name: " << proc_name
                          << ", expected kea-dhcp4");
            }
        } else {
            if (proc_name != "kea-dhcp6") {
                isc_throw(isc::Unexpected, "Bad process name: " << proc_name
                          << ", expected kea-dhcp6");
            }
        }

        impl.reset(new PreProcessImpl());
        ConstElementPtr options = handle.getParameter("options");
        impl->configure(options);
    } catch (const std::exception& ex) {
        LOG_ERROR(pre_process_logger, PRE_PROCESS_LOAD_ERROR)
            .arg(ex.what());
        return (1);
    }

    return (0);
}

/// @brief This function is called when the library is unloaded.
///
/// @return always 0.
int unload() {
    impl.reset();
    LOG_INFO(pre_process_logger, PRE_PROCESS_UNLOAD);
    return (0);
}

/// @brief This function is called to retrieve the multi-threading compatibility.
///
/// @return 1 which means compatible with multi-threading.
int multi_threading_compatible() {
    return (1);
}

} // end extern "C"
