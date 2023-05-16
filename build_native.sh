#!/bin/bash

[[ ! -d build ]] && cmake -Bbuild .
cmake --build build
