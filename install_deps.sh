#!/usr/bin/env bash

ROOT_PATH="${PWD}"

GTEST_PATH="${ROOT_PATH}/lib/googletest"

set -e

# Retrieve some dependencies by using git
git submodule update --init --recursive

# Build Google Test
if [ ! -f "lib/googletest/Makefile" ]
then
  cd lib/googletest
  cmake -DCMAKE_INSTALL_PREFIX="${PWD}/install" .
  make
  make install
  cd "${ROOT_PATH}"
fi