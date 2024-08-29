cmake_minimum_required(VERSION 3.30)
project(Simulator)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(Sparta REQUIRED)

# Might be necessary if Sparta was NOT installed in standard place:
include_directories(SYSTEM ${SPARTA_INCLUDE_DIRS})
include_directories(include)

add_subdirectory(tools)
add_subdirectory(lib)