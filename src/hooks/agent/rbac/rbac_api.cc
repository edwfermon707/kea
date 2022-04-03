// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac_api.h>
#include <exceptions/exceptions.h>

using namespace isc;
using namespace isc::rbac;
using namespace std;

namespace isc {
namespace rbac {

ApiTable apiTable;

ApiPtr
Api::getApiByName(const string& name) {
    auto const& it = apiTable.find(name);
    if (it == apiTable.cend()) {
        return (ApiPtr());
    }
    return (*it);
}

void
Api::fillApiTable(const string& dirname) {
    isc_throw(NotImplemented, "Api::fillApiTable(" << dirname << ") to do...");
}

} // end of namespace rbac
} // end of namespace isc
