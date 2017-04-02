/*!
 * Title ---- intercom-party/LocationManager.cpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include <intercom-party/LocationManager.hpp>

namespace intercom { // Begin main namespace

double
LocationManager::getDistance(const Location &first, const Location &second)
{
    // Apply the Haversine formula

    auto latitude0 = getRadians(first.getLatitude());
    auto latitude1 = getRadians(second.getLatitude());

    auto deltaLatitude  = getRadians(first.getLatitude()  - second.getLatitude());
    auto deltaLongitude = getRadians(first.getLongitude() - second.getLongitude());

    auto a = std::sin(deltaLatitude  / 2.0) * std::sin(deltaLatitude  / 2.0) +
             std::cos(latitude0)            * std::cos(latitude1) *
             std::sin(deltaLongitude / 2.0) * std::sin(deltaLongitude / 2.0);

    auto c = 2 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

    return EarthRadius * c;
}

} // End of main namespace