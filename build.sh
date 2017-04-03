#!/usr/bin/env bash

ROOT_PATH="${PWD}"

GTEST_PATH="${ROOT_PATH}/lib/googletest"

set -e

cmake -DGTEST_ROOT="${GTEST_PATH}/install" .

make
