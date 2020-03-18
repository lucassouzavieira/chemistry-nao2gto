cmake_minimum_required(VERSION 3.5)
project(chemistry-nao2gto)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_LINK_LIBRARY_FLAG)

set(SOURCE_FILES
        main.c)

file(GLOB INCLUDE_FILES
        include/*.cpp
        include/*.hpp
        include/*.h)

file(GLOB SRC_FILES
        src/*.cpp
        src/*.h)

file(GLOB THRD_PARTY
        libs/*/*.h
        libs/*/*.hpp
        libs/*/*.cpp)

file(GLOB UNIT_TESTS
        tests/*.h)

include_directories(
        include
        src
        libs)

add_library(chemistry-nao2gto ${INCLUDE_FILES} ${SRC_FILES} ${THRD_PARTY}  main.cpp)

# Executable
add_executable(executable ${INCLUDE_FILES} ${SRC_FILES} main.cpp)

# Tests suites
#add_executable(tests ${INCLUDE_FILES} ${SRC_FILES} ${UNIT_TESTS} tests/unit_tests.c)