/*!
 * Title ---- intercom-party/EventPlanner.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#ifndef __INTERCOM_PARTY_EVENT_PLANNER_HPP__
#define __INTERCOM_PARTY_EVENT_PLANNER_HPP__

#include <intercom-party.hpp>
#include <intercom-party/Exception.hpp>
#include <intercom-party/LocationManager.hpp>
#include <intercom-party/CustomerRepository.hpp>

#include <iostream>
#include <memory>

using namespace boost;

namespace intercom { // Begin main namespace

/*!
 * Defines the customer ID type.
 */
typedef std::size_t EventPlannerId;

/*!
 * The customer.
 */
class EventPlanner
{

public:

    /*!
     * Creates an event planner.
     *
     * @param[in] customerRepository The customer repository.
     *
     * @return The event planner.
     */
    static EventPlanner create(const std::shared_ptr<CustomerRepository> &customerRepository);

    /*!
     * Destructor method.
     */
    virtual ~EventPlanner();

    /*!
     * Throws a party for customers.
     *
     * @param[in] partyLocation The party location.
     * @param[in] maxDistance   The maximum distance of the customer.
     */
    void throwParty(const Location &partyLocation, double maxDistance);

protected:

    /*!
     * Constructor method.
     */
    EventPlanner();


    /*!
     * The customer repository.
     */
    std::shared_ptr<CustomerRepository> mCustomerRepository;
};

} // End of main namespace

#endif /* __INTERCOM_PARTY_EVENT_PLANNER_HPP__ */

// Include inline methods
#include <intercom-party/EventPlanner-inl.hpp>