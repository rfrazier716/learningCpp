# CMakeList.txt : CMake project for cmakeHelloWorld, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project ("learningCpp")

# Put executables in the bin subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# Add include directories
include_directories ("include")

# Hello world to make sure compiler works
add_executable(hello_world "src/hello_world.cpp")

# Smart pointers
add_executable(smart_pointers "src/smart_pointers/smart_pointers.cpp")

# fileIO
add_executable(fileIO "src/fileIO/fileIO.cpp")

# Classes
add_executable(classes "src/classes/classes.cpp")
add_library(pen "src/classes/pen.cpp")
target_link_libraries(classes pen)