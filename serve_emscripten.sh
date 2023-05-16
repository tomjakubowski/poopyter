#!/bin/bash

[[ ! -d embuild ]] && { echo "embuild not found"; exit 1; }

cd embuild
python3 -m http.server

