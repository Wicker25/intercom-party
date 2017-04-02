/*!
 * Title ---- intercom-party/Customer-inl.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_CUSTOMER_INL_HPP__
#define __INTERCOM_PARTY_CUSTOMER_INL_HPP__

namespace intercom { // Begin main namespace

inline CustomerId
Customer::getId() const
{
    return mId;
}

inline Customer &
Customer::setName(const std::string &name)
{
    mName = name;
    return *this;
}

inline const std::string &
Customer::getName() const
{
    return mName;
}

inline Customer &
Customer::setLocation(const Location &location)
{
    mLocation = location;
    return *this;
}

inline const Location &
Customer::getLocation() const
{
    return mLocation;
}

} // End of main namespace

#endif /* __INTERCOM_PARTY_CUSTOMER_INL_HPP__ */