/*!
 * Title ---- intercom-party/Location.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_LOCATION_HPP__
#define __INTERCOM_PARTY_LOCATION_HPP__

#include <intercom-party.hpp>
#include <intercom-party/Exception.hpp>

using namespace boost;

namespace intercom { // Begin main namespace

/*!
 * The location.
 */
class Location
{

public:

    /*!
     * Destructor method.
     */
    virtual ~Location();

    /*!
     * Creates a location.
     *
     * @return The location.
     */
    static Location create();

    /*!
     * Creates a location from coordinates.
     *
     * @param[in] latitude  The latitude.
     * @param[in] longitude The longitude.
     *
     * @return The location.
     */
    static Location fromCoordinates(double latitude, double longitude);

    /*!
     * Returns the latitude.
     */
    double getLatitude() const;

    /*!
     * Returns the longitude.
     */
    double getLongitude() const;

protected:

    /*!
     * Constructor method.
     */
    Location();


    /*!
     * The latitude.
     */
    double mLatitude;

    /*!
     * The longitude.
     */
    double mLongitude;
};

} // End of main namespace

#endif /* __INTERCOM_PARTY_LOCATION_HPP__ */

// Include inline methods
#include <intercom-party/Location-inl.hpp>