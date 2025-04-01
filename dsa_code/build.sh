#!/bin/bash
mkdir -p build
cd build
cmake ..
make
./linked_list_tests