cmake_minimum_required(VERSION 3.6)
project(node)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(node ${SOURCE_FILES})