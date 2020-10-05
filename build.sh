#! /bin/sh

if [[ "$PWD" != pathsInMap ]]
then
    echo "Can't continue. Make sure you execute this script from the root of pathsInMap repo/direcotory"
else
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ./bin/unit_tests
fi
