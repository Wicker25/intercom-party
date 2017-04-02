/*!
 * Title ---- intercom-party/LocationManager-inl.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_LOCATION_MANAGER_INL_HPP__
#define __INTERCOM_PARTY_LOCATION_MANAGER_INL_HPP__

namespace intercom { // Begin main namespace

inline double
LocationManager::getRadians(double degrees) {

    return (degrees * math::constants::pi<double>()) / 180.0;
}

} // End of main namespace

#endif /* __INTERCOM_PARTY_LOCATION_MANAGER_INL_HPP__ */