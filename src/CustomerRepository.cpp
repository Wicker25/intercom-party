/*!
 * Title ---- intercom-party/CustomerRepository.cpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include <intercom-party/CustomerRepository.hpp>

namespace intercom { // Begin main namespace

CustomerRepository
CustomerRepository::fromPath(const std::string &path)
{
    CustomerRepository customerRepository;
    CustomerList       customerList;

    std::ifstream input(path);

    if (!input.is_open()) {
        throw FileNotFoundException("Unable to open file '%1%'", path);
    }

    std::string line;
    std::size_t lineCounter = 0;

    // Decode the customer list
    for ( ; std::getline(input, line); ++lineCounter) {

        std::stringstream json;
        json << line;

        property_tree::ptree config;

        try {
            property_tree::read_json(json, config);

        } catch (property_tree::json_parser::json_parser_error) {
            throw SyntaxException("Invalid syntax at line %1%", lineCounter);
        }

        customerList.push_back(
            Customer::fromJson(config)
        );
    }

    // Sort the list by ID
    customerList.sort([](const Customer &first, const Customer &second) {
        return first.getId() < second.getId();
    });

    customerRepository.mCustomerList = customerList;

    return customerRepository;
}

CustomerRepository::CustomerRepository()
{

}

CustomerRepository::~CustomerRepository()
{

}

Customer
CustomerRepository::find(CustomerId id)
{
    auto first = mCustomerList.begin(),
         last  = mCustomerList.end();

    auto it = std::find_if(first, last, [id](const Customer &customer) {
        return customer.getId() == id;
    });

    if (it == mCustomerList.end()) {
        throw QueryException("Unable to find the customer with ID = %1%", id);
    }

    return *it;
}

CustomerList
CustomerRepository::findByName(const std::string &name)
{
    CustomerList result;

    auto first = mCustomerList.begin(),
         last  = mCustomerList.end();

    std::copy_if(first, last, std::back_inserter(result), [&name](const Customer &customer) {
        return customer.getName() == name;
    });

    return result;
}

CustomerList
CustomerRepository::findAll()
{
    return mCustomerList;
}

} // End of main namespace