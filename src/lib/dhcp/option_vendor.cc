// Copyright (C) 2013-2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <dhcp/dhcp4.h>
#include <dhcp/dhcp6.h>
#include <dhcp/option_vendor.h>
#include <sstream>

using namespace isc::dhcp;

OptionVendor::OptionVendor(Option::Universe u, const std::vector<uint32_t> vendor_ids)
    : Option(u, u == Option::V4 ?
             static_cast<uint16_t>(DHO_VIVSO_SUBOPTIONS) :
             static_cast<uint16_t>(D6O_VENDOR_OPTS)), vendor_ids_(vendor_ids),
             vendor_options_(std::make_shared<std::map<uint32_t, OptionCollection>>()) {
    if (universe_ == Option::V6 && vendor_ids_.size() > 1) {
        isc_throw(isc::BadValue, "Invalid number of enterprise IDs for universe type " << universe_);
    }
    if (vendor_ids_.size() == 0) {
        isc_throw(isc::BadValue, "Empty set of enterprise IDs for universe type " << universe_);
    }
}

OptionVendor::OptionVendor(Option::Universe u, OptionBufferConstIter begin,
                           OptionBufferConstIter end)
    : Option(u, u == Option::V4?
             static_cast<uint16_t>(DHO_VIVSO_SUBOPTIONS) :
             static_cast<uint16_t>(D6O_VENDOR_OPTS)),
             vendor_options_(std::make_shared<std::map<uint32_t, OptionCollection>>()) {
    unpack(begin, end);
}

OptionVendor::OptionVendor(const OptionVendor& option) : Option(option),
        vendor_ids_(option.vendor_ids_) {
    option.getOptionsCopy(vendor_options_);
}

OptionPtr
OptionVendor::clone() const {
    return (cloneInternal<OptionVendor>());
}

void OptionVendor::pack(isc::util::OutputBuffer& buf, bool check) const {
    packHeader(buf, check);

    for (auto const& vendor_id : vendor_ids_) {
        // Store vendor-id
        buf.writeUint32(vendor_id);

        // The format is slightly different for v4
        if (universe_ == Option::V4) {
            // Calculate and store data-len as follows:
            // data-len = total option length - header length
            //            - enterprise id field length - data-len field size
            // length of all suboptions
            uint8_t length = 0;
            for (auto const& opt : (*vendor_options_)[vendor_id]) {
                length += opt.second->len();
            }
            buf.writeUint8(length);
        }

        packVendorOptions(buf, vendor_id, check);
    }
}

void OptionVendor::packVendorOptions(isc::util::OutputBuffer& buf,
                                     uint32_t vendor_id,
                                     bool check) const {
    switch (universe_) {
    case V4:
        LibDHCP::packOptions4(buf, (*vendor_options_)[vendor_id], false, check);
        return;
    case V6:
        LibDHCP::packOptions6(buf, (*vendor_options_)[vendor_id]);
        return;
    default:
        isc_throw(isc::BadValue, "Invalid universe type " << universe_);
    }
}

void OptionVendor::unpack(OptionBufferConstIter begin,
                          OptionBufferConstIter end) {

    // We throw SkipRemainingOptionsError so callers can
    // abandon further unpacking, if desired.
    if (distance(begin, end) < sizeof(uint32_t)) {
        isc_throw(SkipRemainingOptionsError,
                  "Truncated vendor-specific information option"
                  << ", length=" << distance(begin, end));
    }

    uint32_t offset = 0;
    while (distance(begin + offset, end)) {
        uint32_t vendor_id = isc::util::readUint32(&(*begin) + offset, distance(begin, end));
        // don't add the same vendor ID twice, but still merge the entries together
        if (std::find(vendor_ids_.begin(), vendor_ids_.end(), vendor_id) == vendor_ids_.end()) {
            vendor_ids_.push_back(vendor_id);
        }
        offset += 4;

        OptionBuffer vendor_buffer(begin + offset, end);

        if (universe_ == Option::V6) {
            offset += LibDHCP::unpackVendorOptions6(vendor_id, vendor_buffer, (*vendor_options_)[vendor_id]);
        } else {
            offset += LibDHCP::unpackVendorOptions4(vendor_id, vendor_buffer, (*vendor_options_)[vendor_id]);
        }
    }
    if (universe_ == Option::V6 && vendor_ids_.size() > 1) {
        isc_throw(isc::BadValue, "Invalid number of enterprise IDs for universe type " << universe_);
    }
}

uint16_t OptionVendor::len() const {
    uint16_t length = getHeaderLen();

    length += sizeof(uint32_t) * vendor_ids_.size(); // Vendor-id field

    // Data-len field exists in DHCPv4 vendor options only
    if (universe_ == Option::V4) {
        length += sizeof(uint8_t) * vendor_ids_.size();  // data-len
    }

    // length of all suboptions
    for (auto const& vendor_id : vendor_ids_) {
        for (auto const& opt : (*vendor_options_)[vendor_id]) {
            length += opt.second->len();
        }
    }
    return (length);
}

std::string
OptionVendor::toText(int indent) const {
    std::stringstream output;
    output << headerToText(indent) << ": ";

    for (auto const& vendor_id : vendor_ids_) {
        output << vendor_id << " (uint32)";

        // For the DHCPv4 there is one more field.
        if (getUniverse() == Option::V4) {
            uint32_t length = 0;
            for (auto const& opt : (*vendor_options_)[vendor_id]) {
                length += opt.second->len();
            }
            output << " " << length << " (uint8)";
        }
        if ((*vendor_options_)[vendor_id].size()) {
            output << "," << std::endl << "options:";
            for (auto const& opt : (*vendor_options_)[vendor_id]) {
                output << std::endl << opt.second->toText(indent + 2);
            }
        }
    }

    return (output.str());
}

OptionPtr OptionVendor::getOption(uint32_t vendor_id, uint16_t type) const {
    auto const& vendor = vendor_options_->find(vendor_id);
    if (vendor != vendor_options_->end()) {
        auto const& option = vendor->second.find(type);
        if (option != vendor->second.end()) {
            return (option->second);
        }
    }
    return (OptionPtr());
}

void OptionVendor::addOption(uint32_t vendor_id, OptionPtr opt) {
    (*vendor_options_)[vendor_id].insert(std::make_pair(opt->getType(), opt));
}

bool OptionVendor::delOption(uint32_t vendor_id, uint16_t type) {
    auto const& vendor = vendor_options_->find(vendor_id);
    if (vendor != vendor_options_->end()) {
        auto const& x = vendor->second.find(type);
        if (x != vendor->second.end()) {
            vendor->second.erase(x);
            return (true); // delete successful
        }
    }
    return (false); // option not found, can't delete
}

const OptionCollection OptionVendor::getOptions(uint32_t vendor_id) const {
    auto const& vendor = vendor_options_->find(vendor_id);
    if (vendor == vendor_options_->end()) {
        return (OptionCollection());
    }
    return (vendor->second);
}

OptionVendor& OptionVendor::operator=(const OptionVendor& rhs) {
    if (&rhs != this) {
        Option::operator =(rhs);
        vendor_ids_ = rhs.vendor_ids_;
        rhs.getOptionsCopy(vendor_options_);
    }
    return (*this);
}

void OptionVendor::getOptionsCopy(std::shared_ptr<std::map<uint32_t, OptionCollection>>& options_copy) const {
    std::shared_ptr<std::map<uint32_t, OptionCollection>> local_options(std::make_shared<std::map<uint32_t, OptionCollection>>());
    for (auto const& vendor : *vendor_options_) {
        for (auto const& opt : vendor.second) {
            (*local_options)[vendor.first].insert(std::make_pair(opt.first, opt.second->clone()));
        }
    }
    // All options copied successfully, so assign them to the output
    // parameter.
    options_copy = local_options;
}
