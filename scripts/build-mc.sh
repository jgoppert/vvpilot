#!/bin/bash
mkdir -p build-cbmc && cd build-cbmc && cmake -DCMAKE_TOOLCHAIN_FILE=cmake/goto-toolchain.cmake .. && make
