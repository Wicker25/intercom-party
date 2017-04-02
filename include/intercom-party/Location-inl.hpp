/*!
 * Title ---- intercom-party/Location-inl.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_LOCATION_INL_HPP__
#define __INTERCOM_PARTY_LOCATION_INL_HPP__

namespace intercom { // Begin main namespace

inline double
Location::getLatitude() const
{
    return mLatitude;
}

inline double
Location::getLongitude() const
{
    return mLongitude;
}

} // End of main namespace

#endif /* __INTERCOM_PARTY_LOCATION_INL_HPP__ */