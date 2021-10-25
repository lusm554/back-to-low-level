#!/bin/bash

# Compile intermediate representation called object files
clang -c foo.c  # produces foo.o
clang -c bar.c  # produces bar.o

# Link those together into a single executable
clang foo.o bar.o

