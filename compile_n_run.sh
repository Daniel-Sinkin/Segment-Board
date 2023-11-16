#!/bin/bash

# Compile the C code
gcc main.c boards.c -o boarding

# Run the executable and redirect the output to a file
./boarding > output.txt
