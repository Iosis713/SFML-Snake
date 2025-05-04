#!/bin/bash

if ! dpkg-query -l clang-tools-18 &>/dev/null; then
    echo "clang-tools-18 is not installed. Installing..."
    sudo apt update && sudo apt install -y clang-tools-18
else
    echo "clang-tools-18 is already installed."
fi

echo "Building main project..."

cmake -S. -B build -G Ninja -DCMAKE_CXX_COMPILER=clang++-18
cmake --build build

echo "Building proccess: FINISHED"
