// Copyright (C) 2018-2019,2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <yang/translator.h>

using namespace std;
using namespace isc::data;
using namespace libyang;
using namespace sysrepo;

namespace isc {
namespace yang {

TranslatorBasic::TranslatorBasic(Session session, const string& model)
    : session_(session), model_(model) {
}

ElementPtr
TranslatorBasic::leaf(optional<DataNode> const& data_node) {
    DataNodeTerm const& leaf(data_node->asTerm());
    Value const& value(leaf.value());
    if (holds_alternative<string>(value)) {
        // Should be a string. Call create(). Should be slightly faster
        // than wrapping value in double quotes and calling fromJSON().
        return Element::create(string(leaf.valueStr()));
    } else {
        // This can be various types so defer to fromJSON().
        return Element::fromJSON(string(leaf.valueStr()));
    }
}

ElementPtr
TranslatorBasic::translate(optional<DataNode> const& data_node) {
    if (!data_node) {
        return ElementPtr();
    }

    NodeType const node_type(data_node->schema().nodeType());
    ElementPtr result;
    if (node_type == NodeType::Container) {
        for (DataNode const& child : data_node->immediateChildren()) {
            // Recurse.
            ElementPtr const& element(translate(child));

            // If we have a non-null element, set it in a map.
            if (element) {
                // Create a map now and not earlier to make sure that we don't
                // end up with an empty map in case there are no elements.
                if (!result) {
                    result = Element::createMap();
                }

                SchemaNode const& child_schema(child.schema());
                string const key(child_schema.name());
                result->set(key, element);
            }
        }
    } else if (node_type == NodeType::List) {
        SchemaNode const& schema(data_node->schema());
        List const& list(schema.asList());
        std::vector<Leaf> const& list_keys(list.keys());

        // Children of the list type are always maps. It would have been a
        // leaf list if they weren't. We rely on the guarantee that
        // insertion order is kept. If we have elements, it is sufficient to
        // check if the latest element contains the keys to see if {child}
        // belongs to it or to a new element.
        ElementPtr underlying_map;
        if (result && !result->empty()) {
            underlying_map = result->getNonConst(result->size() - 1);
            for (Leaf l : list_keys) {
                string const leaf_name(l.name());
                optional<DataNode> key_child(data_node->findPath(leaf_name));

                if (!key_child) {
                    isc_throw(SysrepoError, "sysrepo data node does not contain key form schema");
                }

                if (!underlying_map->get(leaf_name) ||
                    underlying_map->get(leaf_name)->str() != key_child->asTerm().valueStr()) {
                    // At least a key doesn't exist or match so break.
                    // A new map should be created outside the loop.
                    break;
                }
            }
        }

        for (DataNode child : data_node->immediateChildren()) {
            // Recurse.
            ElementPtr element(translate(child));

            // If we have a non-null element, set it in a list.
            if (element) {
                if (!underlying_map) {
                    underlying_map = Element::createMap();

                    // Set all the siblings that are keys. This is done only once.
                    // The second time, the map should be matched in the loop above.
                    // This step is needed especially for lists with multiple keys.
                    // If there were a single key, it's probable that it is {child}.
                    for (Leaf l : list_keys) {
                        string const leaf_name(l.name());
                        optional<DataNode> key_child(data_node->findPath(leaf_name));

                        if (!key_child) {
                            isc_throw(SysrepoError, "sysrepo data node does not contain key form schema");
                        }

                        underlying_map->set(leaf_name, leaf(key_child));
                    }
                    if (!result) {
                        result = Element::createList();
                        result->add(underlying_map);
                    }
                }

                SchemaNode const& child_schema(child.schema());
                string const key(child_schema.name());
                underlying_map->set(key, element);
            }
        }
    } else if (node_type == NodeType::Leaf) {
        result = leaf(data_node);
    } else if (node_type == NodeType::Unknown) {
        isc_throw(SysrepoError, "Unhandled node type: Unknown");
    } else if (node_type == NodeType::Choice) {
        isc_throw(SysrepoError, "Unhandled node type: Choice");
    } else if (node_type == NodeType::Leaflist) {
        isc_throw(SysrepoError, "Unhandled node type: Leaflist");
    } else if (node_type == NodeType::AnyXML) {
        isc_throw(SysrepoError, "Unhandled node type: AnyXML");
    } else if (node_type == NodeType::AnyData) {
        isc_throw(SysrepoError, "Unhandled node type: AnyData");
    } else if (node_type == NodeType::Case) {
        isc_throw(SysrepoError, "Unhandled node type: Case");
    } else if (node_type == NodeType::RPC) {
        isc_throw(SysrepoError, "Unhandled node type: RPC");
    } else if (node_type == NodeType::Action) {
        isc_throw(SysrepoError, "Unhandled node type: Action");
    } else if (node_type == NodeType::Notification) {
        isc_throw(SysrepoError, "Unhandled node type: Notification");
    } else if (node_type == NodeType::Uses) {
        isc_throw(SysrepoError, "Unhandled node type: Uses");
    } else if (node_type == NodeType::Input) {
        isc_throw(SysrepoError, "Unhandled node type: Input");
    } else if (node_type == NodeType::Output) {
        isc_throw(SysrepoError, "Unhandled node type: Output");
    } else if (node_type == NodeType::Grouping) {
        isc_throw(SysrepoError, "Unhandled node type: Grouping");
    } else if (node_type == NodeType::Augment) {
        isc_throw(SysrepoError, "Unhandled node type: Augment");
    } else {
        isc_throw(SysrepoError, "Unhandled node type: " << node_type);
    }
    return result;
}

void
TranslatorBasic::set(string const& xpath, ElementPtr const& element) {
    std::cout << xpath << std::endl;
    Context const& context(session_.getContext());
    SchemaNode const& schema(context.findPath(xpath));
    NodeType const node_type(schema.nodeType());

    if (node_type == NodeType::Container) {
        for (auto kv : element->mapValue()) {
            stringstream child_xpath;
            child_xpath << xpath << "/" << kv.first;
            set(child_xpath.str(), boost::const_pointer_cast<Element>(kv.second));
        }
    } else if (node_type == NodeType::List) {
        List const& list(schema.asList());
        std::vector<Leaf> const& list_keys(list.keys());
        stringstream child_xpath;
        child_xpath << xpath;
        for (Leaf const& l : list_keys) {
            string const leaf_name(l.name());
            ElementPtr child_element(element->getNonConst(leaf_name));
            child_xpath << "[" << leaf_name << "="
                        << "'" << child_element->str() << "']";
        }
        for (ElementPtr i : element->listValue()) {
            set(child_xpath.str(), i);
        }
    } else if (node_type == NodeType::Leaf) {
        setItem(xpath, element);
    } else if (node_type == NodeType::Leaflist) {
        for (ElementPtr i : element->listValue()) {
            set(xpath, i);
        }
    } else if (node_type == NodeType::Unknown) {
        isc_throw(SysrepoError, "Unhandled node type: Unknown");
    } else if (node_type == NodeType::Choice) {
        isc_throw(SysrepoError, "Unhandled node type: Choice");
    } else if (node_type == NodeType::AnyXML) {
        isc_throw(SysrepoError, "Unhandled node type: AnyXML");
    } else if (node_type == NodeType::AnyData) {
        isc_throw(SysrepoError, "Unhandled node type: AnyData");
    } else if (node_type == NodeType::Case) {
        isc_throw(SysrepoError, "Unhandled node type: Case");
    } else if (node_type == NodeType::RPC) {
        isc_throw(SysrepoError, "Unhandled node type: RPC");
    } else if (node_type == NodeType::Action) {
        isc_throw(SysrepoError, "Unhandled node type: Action");
    } else if (node_type == NodeType::Notification) {
        isc_throw(SysrepoError, "Unhandled node type: Notification");
    } else if (node_type == NodeType::Uses) {
        isc_throw(SysrepoError, "Unhandled node type: Uses");
    } else if (node_type == NodeType::Input) {
        isc_throw(SysrepoError, "Unhandled node type: Input");
    } else if (node_type == NodeType::Output) {
        isc_throw(SysrepoError, "Unhandled node type: Output");
    } else if (node_type == NodeType::Grouping) {
        isc_throw(SysrepoError, "Unhandled node type: Grouping");
    } else if (node_type == NodeType::Augment) {
        isc_throw(SysrepoError, "Unhandled node type: Augment");
    } else {
        isc_throw(SysrepoError, "Unhandled node type: " << node_type);
    }
}

ElementPtr
TranslatorBasic::getItem(const string& xpath) {
    ElementPtr item;
    try {
        optional<DataNode> node(session_.getData(xpath));
        item = translate(node);
    } catch (const Error& ex) {
        isc_throw(SysrepoError, "sysrepo error getting item '"
                                    << "' at '" << xpath << "': " << ex.what());
    } catch (const ErrorWithCode& ex) {
        isc_throw(SysrepoError, "sysrepo error getting item '"
                                    << "' at '" << xpath << "': " << ex.what());
    }

    // If there is no item, assume empty JSON.
    if (!item) {
        item = Element::createMap();
    }

    return item;
}

void
TranslatorBasic::setItem(const string& xpath, ConstElementPtr elem) {
    try {
        Context context(session_.getContext());
        SchemaNode schema(context.findPath(xpath));
        if (schema.asLeaf().valueType().base() == LeafBaseType::Enum) {
            // Enums are strings in ElementPtr and are accepted without
            // the double quotes in sysrepo.
            session_.setItem(xpath, elem->stringValue());
        } else {
            session_.setItem(xpath, elem->str());
        }
        session_.applyChanges();
    } catch (const Error& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error setting item '" << elem->str()
                  << "' at '" << xpath << "': " << ex.what());
    } catch (const ErrorWithCode& ex) {
        isc_throw(SysrepoError,
                  "sysrepo error setting item '" << elem->str()
                  << "' at '" << xpath << "': " << ex.what());
    }
}

void
TranslatorBasic::checkAndGetLeaf(ElementPtr& storage,
                                 const string& xpath,
                                 const string& name) {
    ConstElementPtr x = getItem(xpath + "/" + name);
    if (x) {
        storage->set(name, x);
    }
}

void TranslatorBasic::checkAndSetLeaf(ConstElementPtr const& from,
                                      string const& xpath,
                                      string const& name) {
    ConstElementPtr const& x(from->get(name));
    if (x) {
        setItem(xpath + "/" + name, x);
    }
}

void
TranslatorBasic::delItem(const string& xpath) {
    try {
        session_.deleteItem(xpath.c_str());
    } catch (const ErrorWithCode& ex) {
        if (string(ex.what()).find("Invalid argument") != string::npos) {
            // The YANG configuration node was not there.
            return;
        }
        isc_throw(SysrepoError,
                  "sysrepo error deleting item at '"
                  << xpath << "': " << ex.what());
    }
    session_.applyChanges();
}

}  // namespace yang
}  // namespace isc
