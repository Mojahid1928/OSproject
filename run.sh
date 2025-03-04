#!/bin/bash

if [ ! -f "emulator" ]; then
    echo "Executable not found! Building the project..."
    ./build.sh
fi

echo "Running Device Driver Emulator..."
./emulator
