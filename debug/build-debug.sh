#!/usr/bin/env bash

cmake -DCMAKE_BUILD_TYPE=Debug -DDATAPATH=../data  ..
make -j2
