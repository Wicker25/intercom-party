/*!
 * Title ---- tests/LocationTest.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include "LocationTest.hpp"

namespace tests { // Begin test namespace

TEST(LocationTest, create)
{
    auto location = Location::create();

    ASSERT_EQ(0.0, location.getLatitude());
    ASSERT_EQ(0.0, location.getLongitude());
}

TEST(LocationTest, fromCoordinates)
{
    auto location = Location::fromCoordinates(53.3393, -6.2576841);

    ASSERT_EQ(53.3393,    location.getLatitude());
    ASSERT_EQ(-6.2576841, location.getLongitude());
}

} // End of test namespace