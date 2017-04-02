/*!
 * Title ---- intercom-party/QueryException.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_QUERY_EXCEPTION_HPP__
#define __INTERCOM_PARTY_QUERY_EXCEPTION_HPP__

#include <intercom-party/Exception.hpp>

namespace intercom { // Begin main namespace

/*!
 * The query exception.
 */
class QueryException : public Exception
{
    using Exception::Exception;
};

} // End of main namespace

#endif /* __INTERCOM_PARTY_QUERY_EXCEPTION_HPP__ */
