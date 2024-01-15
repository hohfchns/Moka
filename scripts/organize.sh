#!/bin/bash

MOKA_LIBS=("MokaUtils" "MokaECS" "MokaWorld" "MokaRenderer" "MokaLogger")

curdir=$(basename "$(pwd)")

if [ "$curdir" == "build" ]; then
  cd ..
fi

mkdir -p ./build/moka/inc
mkdir -p ./build/moka/lib

for lib in ${MOKA_LIBS[@]};
do
  cp -rf "./$lib/inc/" ./build/moka/
  cp -rf "./build/$lib/lib$lib.a" ./build/moka/lib
done

