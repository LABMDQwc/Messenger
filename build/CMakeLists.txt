cmake_minimum_required(VERSION 3.2)

project(messenger)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/debug)

add_executable(_messenger ../src/main.cpp)
