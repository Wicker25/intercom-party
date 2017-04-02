/*!
 * Title ---- tests/CustomerTest.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include "CustomerTest.hpp"

namespace tests { // Begin test namespace

TEST(CustomerTest, create)
{
    auto customer = Customer::create(25, "John Doe");

    ASSERT_EQ(25,         customer.getId());
    ASSERT_EQ("John Doe", customer.getName());
}

TEST(CustomerTest, fromJson)
{
    // TODO
}

TEST(CustomerTest, setName)
{
    auto customer = Customer::create(1, "John Doe");
    customer.setName("Jane Doe");

    ASSERT_EQ("Jane Doe", customer.getName());
}

TEST(CustomerTest, setLocation)
{
    auto customer = Customer::create(1, "John Doe");

    customer.setLocation(
        Location::fromCoordinates(53.3393, -6.2576841)
    );

    auto result = customer.getLocation();

    ASSERT_EQ(53.3393,    result.getLatitude());
    ASSERT_EQ(-6.2576841, result.getLongitude());
}

} // End of test namespace