#!/bin/bash

echo "Compiling Device Driver Emulator..."
g++ main.cpp cli.cpp core.cpp utils.cpp -o emulator

if [ $? -eq 0 ]; then
    echo "Build successful! Run './emulator' to start the program."
else
    echo "Build failed! Please check for errors."
fi
