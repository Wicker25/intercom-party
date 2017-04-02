/*!
 * Title ---- intercom-party/Location.cpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include <intercom-party/Location.hpp>

namespace intercom { // Begin main namespace

Location
Location::create()
{
    Location location;

    location.mLatitude  = 0.0;
    location.mLongitude = 0.0;

    return location;
}

Location
Location::fromCoordinates(double latitude, double longitude)
{
    Location location;

    location.mLatitude  = latitude;
    location.mLongitude = longitude;

    return location;
}

Location::Location()
{

}

Location::~Location()
{

}

} // End of main namespace