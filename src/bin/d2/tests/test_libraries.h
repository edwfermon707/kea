// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef D2_TEST_LIBRARIES_H
#define D2_TEST_LIBRARIES_H

#include <config.h>

namespace {

// Names of the libraries used in these tests.  These libraries are built using
// libtool, so we need to look in the hidden ".libs" directory to locate the
// .so file.  Note that we access the .so file - libtool creates this as a
// like to the real shared library.

// Basic callout library with context_create and three "standard" callouts.
static const char* CALLOUT_LIBRARY = "/home/razvan/isc/git/kea-work/src/bin/d2/tests/.libs/libcallout.so";

} // anonymous namespace

#endif // D2_TEST_LIBRARIES_H
