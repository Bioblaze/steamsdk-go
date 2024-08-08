#!/bin/bash

# Directories
SDK_DIR="steamworks_sdk"
CPP_FILE="cpp/steamworks_wrapper.cpp"
OUTPUT_DIR="build/linux"

# Ensure output directory exists
mkdir -p $OUTPUT_DIR

# Build the shared library
g++ -shared -o $OUTPUT_DIR/libsteamworks_wrapper.so -fPIC $CPP_FILE -I$SDK_DIR/public/steam -L$SDK_DIR/redistributable_bin -lsteam_api

# Copy required files to output directory
cp $SDK_DIR/redistributable_bin/* $OUTPUT_DIR/

echo "Shared library built and copied to $OUTPUT_DIR"
