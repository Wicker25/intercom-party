/*!
 * Title ---- tests/CustomerRepositoryTest.hpp
 * Author --- Giacomo Trudu aka `Wicker25` - wicker25[at]gmail[dot]com
 *
 * Copyright (C) 2017 by Giacomo Trudu.
 * All rights reserved.
 */

#include "CustomerRepositoryTest.hpp"

namespace tests { // Begin test namespace

TEST(CustomerRepositoryTest, fromPath)
{
    ASSERT_NO_THROW({
        auto customerRepository = CustomerRepository::fromPath("tests/fixtures/customers.db");
    });
}

TEST(CustomerRepositoryTest, fromPathWithWrongPath)
{
    ASSERT_THROW({
        auto customerRepository = CustomerRepository::fromPath("wrong-path/customers.db");

    }, FileNotFoundException);
}

TEST(CustomerRepositoryTest, fromPathWithBadContent)
{
    ASSERT_THROW({
        auto customerRepository = CustomerRepository::fromPath("tests/fixtures/bad-content.db");

    }, SyntaxException);
}

TEST(CustomerRepositoryTest, find)
{
    auto customerRepository = CustomerRepository::fromPath("tests/fixtures/customers.db");

    ASSERT_NO_THROW({
        auto consumer = customerRepository.find(9);
    });
}


TEST(CustomerRepositoryTest, findWithNoMatch)
{
    auto customerRepository = CustomerRepository::fromPath("tests/fixtures/customers.db");

    ASSERT_THROW({
        auto consumer = customerRepository.find(999);

    }, QueryException);
}

TEST(CustomerRepositoryTest, findByName)
{
    auto customerRepository = CustomerRepository::fromPath("tests/fixtures/customers.db");

    ASSERT_NO_THROW({
        auto customerList = customerRepository.findByName("Nora Dempsey");
    });
}

TEST(CustomerRepositoryTest, findByNameWithNoMatch)
{
    auto customerRepository = CustomerRepository::fromPath("tests/fixtures/customers.db");

    auto customerList = customerRepository.findByName("John Doe");

    ASSERT_EQ(0, customerList.size());
}

TEST(CustomerRepositoryTest, findAll)
{
    auto customerRepository = CustomerRepository::fromPath("tests/fixtures/customers.db");

    ASSERT_NO_THROW({
        auto customerList = customerRepository.findAll();
    });
}

} // End of test namespace