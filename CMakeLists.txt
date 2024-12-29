# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(CustomSTL)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the include directory for headers
include_directories(include)

# Add the source files
add_executable(main src/main.cpp)