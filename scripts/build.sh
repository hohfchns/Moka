#!/bin/sh

failed=0
mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 cmake .. -B . "$@"

if [ $? -eq 0 ]
then
    echo CMAKE CONFIGURE SUCCESS
else
    echo CMAKE CONFIGURE FAILED
    failed=1
fi

if [ $failed == 1 ]
then
    cont="n"
    read -p "Try to compile anyway? [y/n] " cont

    if [[ $cont != y* ]]
    then
        exit 0
    fi
fi

cmake --build . -j$(nproc)

if [ $? -eq 0 ]
then
    echo BUILD SUCCESS
else
    echo BUILD FAILED
    failed=1
fi
