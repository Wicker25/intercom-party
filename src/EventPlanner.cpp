/*!
 * Title ---- intercom-party/EventPlanner.cpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include <intercom-party/EventPlanner.hpp>

namespace intercom { // Begin main namespace

EventPlanner
EventPlanner::create(const std::shared_ptr<CustomerRepository> &customerRepository)
{
    EventPlanner eventPlanner;

    eventPlanner.mCustomerRepository = customerRepository;

    return eventPlanner;
}

EventPlanner::EventPlanner()
{

}

EventPlanner::~EventPlanner()
{

}

void
EventPlanner::throwParty(const Location &partyLocation, double maxDistance)
{
    auto customerList = mCustomerRepository->findAll();

    for (auto &customer : customerList) {

        auto distance = LocationManager::getDistance(customer.getLocation(), partyLocation);

        if (distance <= maxDistance) {
            std::cout << customer.getId() << ") " << customer.getName() << " [" << distance << " km]\n";
        }
    }

}

} // End of main namespace