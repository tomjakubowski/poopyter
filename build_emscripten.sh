#!/bin/bash

[[ ! -d embuild ]] && \
  emcmake cmake -DCMAKE_BUILD_TYPE=Debug -Bembuild .

cmake --build embuild
