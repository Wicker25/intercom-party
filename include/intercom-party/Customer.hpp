/*!
 * Title ---- intercom-party/Customer.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_CUSTOMER_HPP__
#define __INTERCOM_PARTY_CUSTOMER_HPP__

#include <intercom-party.hpp>
#include <intercom-party/Exception.hpp>
#include <intercom-party/Location.hpp>

#include <boost/property_tree/ptree.hpp>

using namespace boost;

namespace intercom { // Begin main namespace

/*!
 * Defines the customer ID type.
 */
typedef std::size_t CustomerId;

/*!
 * The customer.
 */
class Customer
{

public:

    /*!
     * Creates a customer.
     *
     * @param[in] id   The customer ID.
     * @param[in] name The customer name.
     *
     * @return The customer.
     */
    static Customer create(CustomerId id, const std::string &name);

    /*!
     * Creates a customer from JSON.
     *
     * @param[in] config The property tree.
     *
     * @return The customer.
     */
    static Customer fromJson(property_tree::ptree &config);

    /*!
     * Destructor method.
     */
    virtual ~Customer();

    /*!
     * Returns the ID.
     */
    CustomerId getId() const;

    /*!
     * Sets the name.
     */
    Customer &setName(const std::string &name);

    /*!
     * Returns the name.
     */
    const std::string &getName() const;

    /*!
     * Sets the location.
     */
    Customer &setLocation(const Location &location);

    /*!
     * Returns the location.
     */
    const Location &getLocation() const;

protected:

    /*!
     * Constructor method.
     */
    Customer();


    /*!
     * The customer ID.
     */
    CustomerId mId;

    /*!
     * The customer name.
     */
    std::string mName;

    /*!
     * The customer location.
     */
    Location mLocation = Location::create();
};

} // End of main namespace

#endif /* __INTERCOM_PARTY_CUSTOMER_HPP__ */

// Include inline methods
#include <intercom-party/Customer-inl.hpp>