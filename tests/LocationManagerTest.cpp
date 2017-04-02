/*!
 * Title ---- tests/LocationManagerTest.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include "LocationManagerTest.hpp"

namespace tests { // Begin test namespace

TEST(LocationManagerTest, getRadians)
{
    auto radians = LocationManager::getRadians(45.0);

    ASSERT_NEAR(0.785398, radians, 0.001);
}

TEST(LocationManagerTest, getDistance)
{
    auto location0 = Location::fromCoordinates(40.76, -73.984);
    auto location1 = Location::fromCoordinates(41.89,  12.492);

    auto distance = LocationManager::getDistance(location0, location1);

    ASSERT_NEAR(6885.9, distance, 0.1);
}

} // End of test namespace