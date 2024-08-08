#!/bin/bash

# Directories
OUTPUT_DIR="build/linux"

# Ensure output directory exists
mkdir -p $OUTPUT_DIR

# Build the Go application
go build -o $OUTPUT_DIR/steamworks_app main.go

# Copy shared library to output directory
cp $OUTPUT_DIR/libsteamworks_wrapper.so $OUTPUT_DIR/

echo "Go application built and copied to $OUTPUT_DIR"
