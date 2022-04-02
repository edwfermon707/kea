// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef RBAC_H
#define RBAC_H

#include <cc/data.h>
#include <cc/simple_parser.h>
#include <dhcp/classify.h>
#include <dhcp/libdhcp++.h>
#include <dhcp/option.h>
#include <dhcp/option_definition.h>
#include <dhcp/option_vendor.h>
#include <dhcp/std_option_defs.h>
#include <eval/evaluate.h>
#include <eval/token.h>
#include <util/strutil.h>

#include <map>
#include <string>

namespace isc {
namespace rbac {

/// @brief Role Based Access Control hook implementation.
class RbacImpl {
public:

    /// @brief Constructor.
    RbacImpl();

    /// @brief Destructor.
    ~RbacImpl();
};

/// @brief The type of shared pointers to Flex Option implementations.
typedef boost::shared_ptr<RbacImpl> RbacImplPtr;

} // end of namespace rbac
} // end of namespace isc
#endif
