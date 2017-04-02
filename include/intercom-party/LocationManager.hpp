/*!
 * Title ---- intercom-party/LocationManager.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_LOCATION_MANAGER_HPP__
#define __INTERCOM_PARTY_LOCATION_MANAGER_HPP__

#include <intercom-party.hpp>
#include <intercom-party/Exception.hpp>
#include <intercom-party/Location.hpp>

#include <cmath>

#include <boost/math/constants/constants.hpp>

using namespace boost;

namespace intercom { // Begin main namespace

/*!
 * The location manager.
 */
class LocationManager
{

public:

    /*!
     * The Earth radius in km.
     */
    static constexpr double EarthRadius = 6'371.0;

    /*!
     * Converts degrees in radians.
     *
     * @return The distance (km).
     */
    static double getRadians(double degrees);

    /*!
     * Returns the distance between two locations.
     *
     * @return The distance (km).
     */
    static double getDistance(const Location &first, const Location &second);
};

} // End of main namespace

#endif /* __INTERCOM_PARTY_LOCATION_MANAGER_HPP__ */

// Include inline methods
#include <intercom-party/LocationManager-inl.hpp>