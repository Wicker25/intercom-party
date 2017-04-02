/*!
 * Title ---- intercom-party/CustomerRepository.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_CUSTOMER_REPOSITORY_HPP__
#define __INTERCOM_PARTY_CUSTOMER_REPOSITORY_HPP__

#include <intercom-party.hpp>
#include <intercom-party/Exception.hpp>
#include <intercom-party/FileNotFoundException.hpp>
#include <intercom-party/SyntaxException.hpp>
#include <intercom-party/QueryException.hpp>
#include <intercom-party/Customer.hpp>

#include <fstream>
#include <sstream>
#include <list>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace intercom { // Begin main namespace

/*!
 * Defines the customer list type.
 */
typedef std::list<Customer> CustomerList;

/*!
 * The customer repository.
 */
class CustomerRepository
{

public:

    /*!
     * Creates a customer repository from a file.
     *
     * @param[in] path The repository path.
     *
     * @return The customer.
     */
    static CustomerRepository fromPath(const std::string &path);

    /*!
     * Destructor method.
     */
	virtual ~CustomerRepository();

    /*!
     * Finds a customer by ID.
     *
     * @param[in] id The customer ID.
     *
     * @return The customer.
     */
    Customer find(CustomerId id);

    /*!
     * Finds a customer by name.
     *
     * @param[in] name The customer name.
     *
     * @return The customer list.
     */
    CustomerList findByName(const std::string &name);

    /*!
     * Finds all customers.
     */
    CustomerList findAll();

protected:

    /*!
     * Constructor method.
     */
    CustomerRepository();


    /*!
     * The customer list.
     */
    CustomerList mCustomerList;
};

} // End of main namespace

#endif /* __INTERCOM_PARTY_CUSTOMER_REPOSITORY_HPP__ */

// Include inline methods
#include <intercom-party/CustomerRepository-inl.hpp>