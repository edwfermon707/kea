// Copyright (C) 2010  Internet Systems Consortium, Inc. ("ISC")
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#include <string>

#include <exceptions/exceptions.h>

#include <util/buffer.h>
#include <dns/messagerenderer.h>
#include <dns/rdata.h>
#include <dns/rdataclass.h>
#include <dns/rrclass.h>
#include <dns/rrtype.h>

#include <gtest/gtest.h>

#include <dns/tests/unittest_util.h>
#include <dns/tests/rdata_unittest.h>

using isc::UnitTestUtil;
using namespace std;
using namespace isc;
using namespace isc::dns;
using namespace isc::util;
using namespace isc::dns::rdata;

namespace {
class Rdata_DNSKEY_Test : public RdataTest {
protected:
    Rdata_DNSKEY_Test() :
        dnskey_txt("257 3 5 BEAAAAOhHQDBrhQbtphgq2wQUpEQ5t4DtUHxoMV"
                   "Fu2hWLDMvoOMRXjGrhhCeFvAZih7yJHf8ZGfW6hd38hXG/x"
                   "ylYCO6Krpbdojwx8YMXLA5/kA+u50WIL8ZR1R6KTbsYVMf/"
                   "Qx5RiNbPClw+vT+U8eXEJmO20jIS1ULgqy347cBB1zMnnz/"
                   "4LJpA0da9CbKj3A254T515sNIMcwsB8/2+2E63/zZrQzBkj"
                   "0BrN/9Bexjpiks3jRhZatEsXn3dTy47R09Uix5WcJt+xzqZ"
                   "7+ysyLKOOedS39Z7SDmsn2eA0FKtQpwA6LXeG2w+jxmw3oA"
                   "8lVUgEf/rzeC/bByBNsO70aEFTd"),
        dnskey_txt2("257 3 5 YmluZDEwLmlzYy5vcmc="),
        rdata_dnskey(dnskey_txt),
        rdata_dnskey2(dnskey_txt2)
    {}

    void checkFromText_None(const string& rdata_str) {
        checkFromText<generic::DNSKEY, isc::Exception, isc::Exception>(
            rdata_str, rdata_dnskey2, false, false);
    }

    void checkFromText_InvalidText(const string& rdata_str) {
        checkFromText<generic::DNSKEY, InvalidRdataText, InvalidRdataText>(
            rdata_str, rdata_dnskey2, true, true);
    }

    void checkFromText_InvalidLength(const string& rdata_str) {
        checkFromText<generic::DNSKEY, InvalidRdataLength, InvalidRdataLength>(
            rdata_str, rdata_dnskey2, true, true);
    }

    void checkFromText_BadValue(const string& rdata_str) {
        checkFromText<generic::DNSKEY, BadValue, BadValue>(
            rdata_str, rdata_dnskey2, true, true);
    }

    void checkFromText_LexerError(const string& rdata_str) {
        checkFromText
            <generic::DNSKEY, InvalidRdataText, MasterLexer::LexerError>(
                rdata_str, rdata_dnskey2, true, true);
    }

    const string dnskey_txt;
    const string dnskey_txt2;
    const generic::DNSKEY rdata_dnskey;
    const generic::DNSKEY rdata_dnskey2;
};

TEST_F(Rdata_DNSKEY_Test, fromText) {
    EXPECT_EQ(dnskey_txt, rdata_dnskey.toText());

    // Space in key data is OK
    checkFromText_None("257 3 5 YmluZDEw LmlzYy5vcmc=");

    // Delimited number in key data is OK
    checkFromText_None("257 3 5 YmluZDEwLmlzYy 5 vcmc=");

    // Key data missing
    checkFromText_InvalidText("257 3 5");

    // Flags field out of range
    checkFromText_InvalidText("65536 3 5 YmluZDEwLmlzYy5vcmc=");

    // Protocol field out of range
    checkFromText_InvalidText("257 256 5 YmluZDEwLmlzYy5vcmc=");

    // Algorithm field out of range
    checkFromText_InvalidText("257 3 256 YmluZDEwLmlzYy5vcmc=");

    // Missing algorithm field
    checkFromText_LexerError("257 3 YmluZDEwLmlzYy5vcmc=");

    // Invalid key data field (not Base64)
    checkFromText_BadValue("257 3 5 BAAAAAAAAAAAD");

    // Key data too short for algorithm=1
    checkFromText_InvalidLength("1 1 1 YQ==");

    // String instead of number
    checkFromText_LexerError("foo 3 5 YmFiYWJhYmE=");
    checkFromText_LexerError("257 foo 5 YmFiYWJhYmE=");
    checkFromText_LexerError("257 3 foo YmFiYWJhYmE=");
}

TEST_F(Rdata_DNSKEY_Test, assign) {
    generic::DNSKEY rdata_dnskey2 = rdata_dnskey;
    EXPECT_EQ(0, rdata_dnskey.compare(rdata_dnskey2));
}

TEST_F(Rdata_DNSKEY_Test, createFromLexer) {
    EXPECT_EQ(0, rdata_dnskey.compare(
        *test::createRdataUsingLexer(RRType::DNSKEY(), RRClass::IN(),
                                     dnskey_txt)));
}

TEST_F(Rdata_DNSKEY_Test, toWireRenderer) {
    renderer.skip(2);
    rdata_dnskey.toWire(renderer);

    vector<unsigned char> data;
    UnitTestUtil::readWireData("rdata_dnskey_fromWire.wire", data);
    EXPECT_PRED_FORMAT4(UnitTestUtil::matchWireData,
                        static_cast<const uint8_t *>(renderer.getData()) + 2,
                        renderer.getLength() - 2, &data[2], data.size() - 2);
}

TEST_F(Rdata_DNSKEY_Test, toWireBuffer) {
    rdata_dnskey.toWire(obuffer);

    vector<unsigned char> data;
    UnitTestUtil::readWireData("rdata_dnskey_fromWire.wire", data);
    EXPECT_PRED_FORMAT4(UnitTestUtil::matchWireData,
                        obuffer.getData(), obuffer.getLength(),
                        &data[2], data.size() - 2);
}

TEST_F(Rdata_DNSKEY_Test, createFromWire) {
    EXPECT_EQ(0, rdata_dnskey.compare(
                  *rdataFactoryFromFile(RRType("DNSKEY"), RRClass("IN"),
                                        "rdata_dnskey_fromWire.wire")));
    // Empty keydata should throw
    EXPECT_THROW(rdataFactoryFromFile
                 (RRType("DNSKEY"), RRClass("IN"),
                  "rdata_dnskey_empty_keydata_fromWire.wire"),
                 InvalidRdataLength);
    // Short keydata for RSA/MD5 should throw
    EXPECT_THROW(rdataFactoryFromFile
                 (RRType("DNSKEY"), RRClass("IN"),
                  "rdata_dnskey_short_keydata1_fromWire.wire"),
                 InvalidRdataLength);
}

TEST_F(Rdata_DNSKEY_Test, getTag) {
    EXPECT_EQ(12892, rdata_dnskey.getTag());
}

TEST_F(Rdata_DNSKEY_Test, getAlgorithm) {
    EXPECT_EQ(5, rdata_dnskey.getAlgorithm());
}

TEST_F(Rdata_DNSKEY_Test, getFlags) {
    EXPECT_EQ(257, rdata_dnskey.getFlags());
}

}
