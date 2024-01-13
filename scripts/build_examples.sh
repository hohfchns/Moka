#!/bin/bash

./scripts/build.sh
./scripts/organize.sh

EXAMPLES=(basic_project renderer_project)

for example in ${EXAMPLES[@]};
do
  cp -rf ./build/moka ./examples/$example/vendor

  cd examples/$example

  mkdir -p build
  cd build

  cmake .. 
  cmake --build . -j$(nproc)

  cd ../../..
done
