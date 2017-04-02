/*!
 * Title ---- intercom-party/Customer.cpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include <intercom-party/Customer.hpp>

namespace intercom { // Begin main namespace

Customer
Customer::create(CustomerId id, const std::string &name)
{
    Customer customer;

    customer.mId   = id;
    customer.mName = name;

    return customer;
}

Customer
Customer::fromJson(property_tree::ptree &config)
{
    Customer customer;

    customer.mId   = config.get<std::size_t>("user_id");
    customer.mName = config.get<std::string>("name");

    auto latitude  = config.get<double>("latitude");
    auto longitude = config.get<double>("longitude");

    customer.mLocation = Location::fromCoordinates(latitude, longitude);

    return customer;
}

Customer::Customer()
{

}

Customer::~Customer()
{

}

} // End of main namespace