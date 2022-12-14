// Copyright (C) 2013-2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPTION_VENDOR_H
#define OPTION_VENDOR_H

#include <dhcp/libdhcp++.h>
#include <dhcp/option.h>
#include <dhcp/option_data_types.h>
#include <util/io_utilities.h>

#include <stdint.h>

namespace isc {
namespace dhcp {

/// Indexes for fields in vendor-class (17) DHCPv6 option
const int VENDOR_CLASS_ENTERPRISE_ID_INDEX = 0;
const int VENDOR_CLASS_DATA_LEN_INDEX = 1;
const int VENDOR_CLASS_STRING_INDEX = 2;

/// @brief This class represents vendor-specific information option.
///
/// As specified in RFC3925, the option formatting is slightly different
/// for DHCPv4 than DHCPv6. The DHCPv4 Option includes additional field
/// holding vendor data length.
class OptionVendor: public Option {
public:
    /// @brief Constructor.
    ///
    /// @param u universe (V4 or V6)
    /// @param vendor_id vendor enterprise-id (unique 32 bit integer)
    OptionVendor(Option::Universe u, const std::vector<uint32_t> vendor_ids);

    /// @brief Constructor.
    ///
    /// This constructor creates option from a buffer. This constructor
    /// may throw exception if \ref unpack function throws during buffer
    /// parsing.
    ///
    /// @param u universe (V4 or V6)
    /// @param begin iterator to first byte of option data.
    /// @param end iterator to end of option data (first byte after option end).
    ///
    /// @throw isc::OutOfRange if provided buffer is shorter than data size.
    /// @todo Extend constructor to set encapsulated option space name.
    OptionVendor(Option::Universe u, OptionBufferConstIter begin,
                 OptionBufferConstIter end);

    /// @brief Copy constructor.
    ///
    /// This constructor makes a deep copy of the option and all of the
    /// suboptions. It calls @ref getOptionsCopy to deep copy suboptions.
    ///
    /// @param source Option to be copied.
    OptionVendor(const OptionVendor& option);

    /// @brief Copies this option and returns a pointer to the copy.
    OptionPtr clone() const;

    /// @brief Writes option in wire-format to buf, returns pointer to first
    /// unused byte after stored option.
    ///
    /// @param [out] buf buffer (option will be stored here)
    /// @param check if set to false, allows options larger than 255 for v4
    virtual void pack(isc::util::OutputBuffer& buf, bool check = true) const;

    /// @brief Parses received buffer
    ///
    /// Parses received buffer and returns offset to the first unused byte after
    /// parsed option.
    ///
    /// @param begin iterator to first byte of option data
    /// @param end iterator to end of option data (first byte after option end)
    ///
    /// @throw isc::SkipRemainingOptionsBuffer if an error is encountered
    /// unpacking the option.  This exception is thrown to indicate to the
    /// caller that a: remaining options cannot be parsed and b: the packet
    /// should be considered for processing anyway.
    virtual void unpack(OptionBufferConstIter begin, OptionBufferConstIter end);

    /// @brief Sets enterprise identifier
    ///
    /// @param vendor_id vendor identifier
    void setVendorIds(const std::vector<uint32_t> vendor_ids) {
        if (universe_ == Option::V6 && vendor_ids.size() > 1) {
            isc_throw(isc::BadValue, "Invalid number of enterprise IDs for universe type " << universe_);
        }
        if (vendor_ids.size() == 0) {
            isc_throw(isc::BadValue, "Empty set of enterprise IDs for universe type " << universe_);
        }
        vendor_ids_ = vendor_ids;
        // erase options which are not correlated to any Enterprise ID
        auto vendor_options_copy = *vendor_options_;
        for (auto const& vendor : vendor_options_copy) {
            if (std::find(vendor_ids_.begin(), vendor_ids_.end(), vendor.first) == vendor_ids_.end()) {
                vendor_options_->erase(vendor.first);
            }
        }
    }

    /// @brief Returns enterprise identifier
    ///
    /// @return enterprise identifier
    std::vector<uint32_t> getVendorIds() const {
        return (vendor_ids_);
    }

    /// @brief Returns true if the vendor identifier is present in the option.
    ///
    /// @param id the vendor identifier which is searched
    ///
    /// @return true if the vendor identifier is present in the option, false
    /// otherwise
    bool hasVendorId(uint32_t id) const {
        for (auto const& vendor_id : vendor_ids_) {
            if (id == vendor_id) {
                return (true);
            }
        }
        return (false);
    }

    /// @brief returns complete length of option
    ///
    /// Returns length of this option, including option header and suboptions
    ///
    /// @return length of this option
    virtual uint16_t len() const;

    /// @brief Returns the option in the textual format.
    ///
    /// @param indent Number of spaces to be inserted before the text.
    ///
    /// @return Vendor option in the textual format.
    virtual std::string toText(int indent = 0) const;

    /// Returns shared_ptr to suboption of specific type
    ///
    /// @param vendor_id the vendor identifier suboption belongs to
    /// @param type type of requested suboption
    ///
    /// @return shared_ptr to requested suboption
    OptionPtr getOption(uint32_t vendor_id, uint16_t type) const;

    /// Attempts to delete first suboption of requested type
    ///
    /// @param vendor_id the vendor identifier suboption belongs to
    /// @param type Type of option to be deleted.
    ///
    /// @return true if option was deleted, false if no such option existed
    bool delOption(uint32_t vendor_id, uint16_t type);

    /// Adds a sub-option.
    ///
    /// Some DHCPv6 options can have suboptions. This method allows adding
    /// options within options.
    ///
    /// Note: option is passed by value. That is very convenient as it allows
    /// downcasting from any derived classes, e.g. shared_ptr<Option6_IA> type
    /// can be passed directly, without any casts. That would not be possible
    /// with passing by reference. addOption() is expected to be used in
    /// many places. Requiring casting is not feasible.
    ///
    /// @param vendor_id the vendor identifier suboption belongs to
    /// @param opt shared pointer to a suboption that is going to be added.
    void addOption(uint32_t vendor_id, OptionPtr opt);

    /// @brief Returns all encapsulated options for the respective vendor identifier.
    ///
    /// @param vendor_id the vendor identifier suboptions belongs to
    const OptionCollection getOptions(uint32_t vendor_id) const;

    /// @brief Assignment operator.
    ///
    /// The assignment operator performs a deep copy of the option and
    /// its suboptions. It calls @ref getOptionsCopy to deep copy
    /// suboptions.
    ///
    /// @param rhs Option to be assigned.
    OptionVendor& operator=(const OptionVendor& rhs);

private:

    /// @brief Store sub options in a buffer.
    ///
    /// This method stores all sub-options defined for a particular
    /// option in a on-wire format in output buffer provided.
    /// This function is called by pack function in this class or
    /// derived classes that override pack.
    ///
    /// @param [out] buf output buffer.
    /// @param check if set to false, allows options larger than 255 for v4
    ///
    /// @todo The set of exceptions thrown by this function depend on
    /// exceptions thrown by pack methods invoked on objects
    /// representing sub options. We should consider whether to aggregate
    /// those into one exception which can be documented here.
    void packVendorOptions(isc::util::OutputBuffer& buf, uint32_t vendor_id,
                           bool check = true) const;

    /// @brief Performs deep copy of suboptions.
    ///
    /// This method calls @ref clone method to deep copy each option.
    ///
    /// @param [out] options_copy Container where copied options are stored.
    void getOptionsCopy(std::shared_ptr<std::map<uint32_t, OptionCollection>>& options_copy) const;

    /// @brief Enterprise-ids
    std::vector<uint32_t> vendor_ids_;

    /// @brief Specific Enterprise-ids options
    std::shared_ptr<std::map<uint32_t, OptionCollection>> vendor_options_;

    /// @brief Deleted functions.
    /// @{
    OptionPtr getOption(uint16_t type) const = delete;

    bool delOption(uint16_t type) = delete;

    void addOption(OptionPtr opt) = delete;

    void getOptionsCopy(OptionCollection& options_copy) const = delete;

    std::string suboptionsToText(const int indent = 0) const = delete;

    const OptionCollection& getOptions() const = delete;
    /// @}
};

/// Pointer to a vendor option
typedef boost::shared_ptr<OptionVendor> OptionVendorPtr;

} // isc::dhcp namespace
} // isc namespace

#endif // OPTION_VENDOR_H
