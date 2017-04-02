project(IntercomParty)

cmake_minimum_required(VERSION 3.6)

set(INTERCOM_PARTY_VERSION_MAJOR  0)
set(INTERCOM_PARTY_VERSION_MINOR  1)
set(INTERCOM_PARTY_VERSION_PATCH  0)

set(INTERCOM_PARTY_VERSION  "${INTERCOM_PARTY_VERSION_MAJOR}.${INTERCOM_PARTY_VERSION_MINOR}.${INTERCOM_PARTY_VERSION_PATCH}")

set(INTERCOM_PARTY_DIR            ${PROJECT_SOURCE_DIR})
set(INTERCOM_PARTY_SOURCE_DIR     ${INTERCOM_PARTY_DIR}/src        )
set(INTERCOM_PARTY_INCLUDE_DIR    ${INTERCOM_PARTY_DIR}/include    )
set(INTERCOM_PARTY_LIB_DIR        ${INTERCOM_PARTY_DIR}/lib        )
set(INTERCOM_PARTY_BUILD_DIR      ${INTERCOM_PARTY_DIR}/bin        )
set(INTERCOM_PARTY_TESTS_DIR      ${INTERCOM_PARTY_DIR}/tests      )

set(LIBRARY_OUTPUT_PATH     ${INTERCOM_PARTY_BUILD_DIR})
set(EXECUTABLE_OUTPUT_PATH  ${INTERCOM_PARTY_BUILD_DIR})

add_definitions(
    -Wall
    -ansi
    -pedantic
    -pedantic-errors
    -Wno-deprecated-declarations
    -O2
    -std=c++14
    -static
)

set(Boost_USE_STATIC_LIBS    ON )
set(Boost_USE_MULTITHREADED  ON )
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.60 REQUIRED)
find_package(GTest      REQUIRED)

include_directories(
    ${INTERCOM_PARTY_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS}
)

link_directories(
    ${Boost_LIBRARY_DIRS}
)

configure_file(
    ${INTERCOM_PARTY_INCLUDE_DIR}/intercom-party/version.hpp.in
    ${INTERCOM_PARTY_INCLUDE_DIR}/intercom-party/version.hpp
    IMMEDIATE @ONLY
)

add_library(intercom
    ${INTERCOM_PARTY_SOURCE_DIR}/Location.cpp
    ${INTERCOM_PARTY_SOURCE_DIR}/LocationManager.cpp
    ${INTERCOM_PARTY_SOURCE_DIR}/Customer.cpp
    ${INTERCOM_PARTY_SOURCE_DIR}/CustomerRepository.cpp
    ${INTERCOM_PARTY_SOURCE_DIR}/EventPlanner.cpp
)

target_link_libraries(intercom
    ${Boost_LIBRARIES}
)

add_executable(intercom-party ${INTERCOM_PARTY_SOURCE_DIR}/intercom-party.cpp)

target_link_libraries(intercom-party intercom)

add_executable(intercom-party-tests
    ${INTERCOM_PARTY_TESTS_DIR}/LocationTest.cpp
    ${INTERCOM_PARTY_TESTS_DIR}/LocationManagerTest.cpp
    ${INTERCOM_PARTY_TESTS_DIR}/CustomerTest.cpp
    ${INTERCOM_PARTY_TESTS_DIR}/CustomerRepositoryTest.cpp
    ${INTERCOM_PARTY_TESTS_DIR}/intercom-party-tests.cpp
)

target_link_libraries(intercom-party-tests
    intercom
    ${GTEST_LIBRARIES}
)