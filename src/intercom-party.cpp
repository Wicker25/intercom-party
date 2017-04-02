/*!
 * Title ---- intercom-party.cpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include <intercom-party.hpp>
#include <intercom-party/CustomerRepository.hpp>
#include <intercom-party/EventPlanner.hpp>

const std::string RepositoryPath = "resources/customers.db";

using namespace intercom;

int main(int argc, char **argv)
{
    /*
     * Creates the services
     */
    auto customerRepository = std::make_shared<CustomerRepository>(
        CustomerRepository::fromPath(RepositoryPath)
    );

    auto eventPlanner = std::make_shared<EventPlanner>(
        EventPlanner::create(customerRepository)
    );

    /*
     * Throws a party!
     */
    auto officeLocation = Location::fromCoordinates(53.3393, -6.2576841);

    eventPlanner->throwParty(officeLocation, 100.0);

    return 0;
}