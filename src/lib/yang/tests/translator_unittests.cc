// Copyright (C) 2018-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
#if false
#include <config.h>

#include <testutils/gtest_utils.h>
#include <yang/translator.h>

#include <sysrepo-cpp/Connection.hpp>

#include <boost/scoped_ptr.hpp>

#include <gtest/gtest.h>

using namespace std;
using namespace isc;
using namespace isc::data;
using namespace isc::yang;
using namespace sysrepo;

using libyang::DataNode;

namespace {

// Test constructor.
TEST(TranslatorBasicTest, constructor) {
    // Get a session.
    Session sess(Connection{}.sessionStart());
    // Get a translator object.
    boost::scoped_ptr<TranslatorBasic> t_obj;
    EXPECT_NO_THROW(t_obj.reset(new TranslatorBasic(sess, "")));
}

// Test basic yang value to JSON using sysrepo test models.
TEST(TranslatorBasicTest, getItem) {
    // Get a translator object to play with.
    Session sess(Connection{}.sessionStart());
    sess.switchDatastore(sysrepo::Datastore::Candidate);
    boost::scoped_ptr<TranslatorBasic> t_obj;
    ASSERT_NO_THROW_LOG(t_obj.reset(new TranslatorBasic(sess, "")));
    ConstElementPtr elem;
    string xpath;

    // String.
    xpath = "/keatest-module:main/string";
    EXPECT_NO_THROW(sess.setItem(xpath, "\"str\""));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::string, elem->getType());
    EXPECT_EQ("str", elem->stringValue());
    elem.reset();

    // Bool.
    xpath = "/keatest-module:main/boolean";
    EXPECT_NO_THROW(sess.setItem(xpath, "true"));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::boolean, elem->getType());
    EXPECT_TRUE(elem->boolValue());
    elem.reset();

    // Unsigned 8 bit integer.
    xpath = "/keatest-module:main/ui8";
    uint8_t u8(8);
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(u8)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::integer, elem->getType());
    EXPECT_EQ(8, elem->intValue());
    elem.reset();

    // Unsigned 16 bit integer.
    xpath = "/keatest-module:main/ui16";
    uint16_t u16(16);
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(u16)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::integer, elem->getType());
    EXPECT_EQ(16, elem->intValue());
    elem.reset();

    // Unsigned 32 bit integer.
    xpath = "/keatest-module:main/ui32";
    uint32_t u32(32);
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(u32)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::integer, elem->getType());
    EXPECT_EQ(32, elem->intValue());
    elem.reset();

    // Signed 8 bit integer.
    xpath = "/keatest-module:main/i8";
    int8_t s8(8);
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(s8)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::integer, elem->getType());
    EXPECT_EQ(8, elem->intValue());
    elem.reset();

    // Signed 16 bit integer.
    xpath = "/keatest-module:main/i16";
    int16_t s16(16);
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(s16)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::integer, elem->getType());
    EXPECT_EQ(16, elem->intValue());
    elem.reset();

    // Signed 32 bit integer.
    xpath = "/keatest-module:main/i32";
    int32_t s32(32);
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(s32)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::integer, elem->getType());
    EXPECT_EQ(32, elem->intValue());
    elem.reset();

    // Identity reference.
    xpath = "/keatest-module:main/id_ref";
    EXPECT_NO_THROW(sess.setItem(xpath, "keatest-module:id_1"));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::string, elem->getType());
    EXPECT_EQ("keatest-module:id_1", elem->stringValue());
    elem.reset();

    // Enumeration item.
    xpath = "/keatest-module:main/enum";
    EXPECT_NO_THROW(sess.setItem(xpath, "\"maybe\""));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::string, elem->getType());
    EXPECT_EQ("maybe", elem->stringValue());
    elem.reset();

    // Binary.
    xpath = "/keatest-module:main/raw";
    EXPECT_NO_THROW(sess.setItem(xpath, "\"Zm9vYmFy\""));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::string, elem->getType());
    EXPECT_EQ("foobar", elem->stringValue());
    elem.reset();

    // Leaf-list: not yet exist.
    xpath = "/keatest-module:main/numbers";
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    EXPECT_FALSE(elem);
    elem.reset();

    // No easy way to create it empty.

    // Leaf-list: 1, 2 and 3.
    u8 = 1;
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(u8)));
    u8 = 2;
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(u8)));
    u8 = 3;
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(u8)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::list, elem->getType());
    EXPECT_EQ(3, elem->size());
    EXPECT_EQ("[ 1, 2, 3 ]", elem->str());
    elem.reset();

    // Unknown / unsupported.
    xpath = "/keatest-module:main/dec64";
    EXPECT_NO_THROW(sess.setItem(xpath, to_string(9.85)));
    EXPECT_NO_THROW(elem = t_obj->getItem(xpath));
    ASSERT_TRUE(elem);
    ASSERT_EQ(Element::real, elem->getType());
    EXPECT_EQ("9.85", elem->str());
    elem.reset();

    // Not found.
    xpath = "/keatest-module:main/no_such_string";

    // libyang::ErrorWithCode: "Invalid argument"
    EXPECT_THROW(sess.deleteItem(xpath), libyang::ErrorWithCode);
    EXPECT_THROW(elem = t_obj->getItem(xpath), SysrepoError);
    EXPECT_FALSE(elem);
    elem.reset();

    // Check error.
    xpath = "null";
    try {
        elem = t_obj->getItem(xpath);
        ADD_FAILURE() << "expected exception";
    } catch (const SysrepoError& ex) {
        EXPECT_EQ("sysrepo error getting item at 'null': libyang error",
                  string(ex.what()));
    } catch (const std::exception& ex) {
        ADD_FAILURE() << "unexpected exception with: " << ex.what();
    }
}

// Test JSON to basic yang value using sysrepo test models.
TEST(TranslatorBasicTest, setItem) {
    // Get a translator object to play with.
    Session sess(Connection{}.sessionStart());
    sess.switchDatastore(sysrepo::Datastore::Candidate);
    boost::scoped_ptr<TranslatorBasic> t_obj;
    ASSERT_NO_THROW_LOG(t_obj.reset(new TranslatorBasic(sess, "")));

    // Container.
    string xpath = "/keatest-module:container";
    ConstElementPtr elem = Element::createMap();
    EXPECT_THROW(t_obj->setItem(xpath, elem), NotImplemented);
    EXPECT_THROW(t_obj->setItem(xpath, elem), NotImplemented);

    // String.
    std::optional<DataNode> data_node;
    xpath = "/keatest-module:main/string";
    elem = Element::create(string("str"));
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("str", string(data_node->asTerm().valueStr()));
    data_node.reset();

    // Bool.
    xpath = "/keatest-module:main/boolean";
    elem = Element::create(true);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    ASSERT_EQ("true", data_node->asTerm().valueStr());
    data_node.reset();

    // Unsigned 8 bit integer.
    xpath = "/keatest-module:main/ui8";
    elem = Element::create(8);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("8", data_node->asTerm().valueStr());
    data_node.reset();

    // Unsigned 16 bit integer.
    xpath = "/keatest-module:main/ui16";
    elem = Element::create(16);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("16", data_node->asTerm().valueStr());
    data_node.reset();

    // Unsigned 32 bit integer.
    xpath = "/keatest-module:main/ui32";
    elem = Element::create(32);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("32", data_node->asTerm().valueStr());
    data_node.reset();

    // Signed 8 bit integer.
    xpath = "/keatest-module:main/i8";
    elem = Element::create(8);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("8", data_node->asTerm().valueStr());
    data_node.reset();

    // Signed 16 bit integer.
    xpath = "/keatest-module:main/i16";
    elem = Element::create(16);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("16", data_node->asTerm().valueStr());
    data_node.reset();

    // Signed 32 bit integer.
    xpath = "/keatest-module:main/i32";
    elem = Element::create(32);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("32", data_node->asTerm().valueStr());
    data_node.reset();

    // Identity reference.
    xpath = "/keatest-module:main/id_ref";
    elem = Element::create(string("keatest-module:id_1"));
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("keatest-module:id_1", string(data_node->asTerm().valueStr()));
    data_node.reset();

    // Enumeration item.
    xpath = "/keatest-module:main/enum";
    elem = Element::create(string("maybe"));
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("maybe", string(data_node->asTerm().valueStr()));
    data_node.reset();

    // Binary.
    xpath = "/keatest-module:main/raw";
    elem = Element::create(string("foobar"));
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("Zm9vYmFy", string(data_node->asTerm().valueStr()));
    data_node.reset();

    // Decimal 64.
    xpath = "/keatest-module:main/dec64";
    double d64(9.85);
    elem = Element::create(d64);
    EXPECT_NO_THROW(t_obj->setItem(xpath, elem));
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    ASSERT_TRUE(data_node);
    ASSERT_EQ(libyang::NodeType::Leaf, data_node->schema().nodeType());
    EXPECT_EQ("9.85", data_node->asTerm().valueStr());
    data_node.reset();

    // Fill it.
    sess.setItem(xpath, "1");
    sess.setItem(xpath, "2");
    sess.setItem(xpath, "3");
    sess.applyChanges();

    // Clean it.
    EXPECT_NO_THROW(t_obj->delItem(xpath));

    // Bad xpath.
    xpath = "/keatest-module:main/no_such_string";
    elem = Element::create(string("str"));
    try {
        t_obj->setItem(xpath, elem);
        ADD_FAILURE() << "expected exception";
    } catch (const SysrepoError& ex) {
        string expected = "sysrepo error setting item '\"str\"' at '" +
            xpath + "': Invalid argument";
        EXPECT_EQ(expected, string(ex.what()));
    } catch (const std::exception& ex) {
        ADD_FAILURE() << "unexpected exception with: " << ex.what();
    }

    // Bad type.
    xpath = "/keatest-module:main/string";
    elem = Element::create(true);
    try {
        t_obj->setItem(xpath, elem);
    } catch (const SysrepoError& ex) {
        ADD_FAILURE() << "unexpected exception with: " << ex.what();
    } catch (const std::exception& ex) {
        ADD_FAILURE() << "unexpected exception with: " << ex.what();
    }

    // In sysrepo 1.x, setItem() is based on setItem_str() which sets the
    // value in textual format. After setting a value with libyang::NodeType::Leaf, it's value
    // is now "true". :)
    elem = t_obj->getItem(xpath);
    ASSERT_TRUE(elem);
    EXPECT_EQ(elem->getType(), Element::string);
    EXPECT_EQ(elem->str(), "\"true\"");

    // Delete (twice).
    xpath = "/keatest-module:main/string";
    EXPECT_NO_THROW(data_node = sess.getData(xpath));
    EXPECT_TRUE(data_node);
    data_node.reset();
    EXPECT_NO_THROW(t_obj->delItem(xpath));

    // libyang::ErrorWithCode: "Item not found"
    EXPECT_THROW(data_node = sess.getData(xpath), libyang::ErrorWithCode);
    EXPECT_FALSE(data_node);
    EXPECT_NO_THROW(t_obj->delItem(xpath));
}

// Test yang list item retrieval.
TEST(TranslatorBasicTest, list) {
    // Get a translator object to play with.
    Session sess(Connection{}.sessionStart());
    sess.switchDatastore(sysrepo::Datastore::Candidate);
    boost::scoped_ptr<TranslatorBasic> t_obj;
    ASSERT_NO_THROW_LOG(t_obj.reset(new TranslatorBasic(sess, "")));
    string xpath;

    // Empty list.
    ElementPtr element;
    EXPECT_NO_THROW(element = t_obj->getItem("/keatest-module:container/list"));
    EXPECT_FALSE(element);
    element.reset();

    // Retried with a filled list.
    xpath = "/keatest-module:container/list[key1='key1'][key2='key2']/leaf";
    EXPECT_NO_THROW(sess.setItem(xpath, "leaf value"));
    EXPECT_NO_THROW(element = t_obj->getItem("/keatest-module:container/list"));
    ASSERT_TRUE(element);
    EXPECT_NO_THROW(element = t_obj->getItem("/keatest-module:container/list[key1='key1'][key2='key2']"));
    ASSERT_TRUE(element);
}

} // anonymous namespace
#endif