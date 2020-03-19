cmake_minimum_required(VERSION 3.5)
project(nao2gto)

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

file(GLOB LIBS
        libs/*/*.h
        libs/*/*.hpp
        libs/*/*.cpp)

file(GLOB UNIT_TESTS
        tests/*.cpp)

include_directories(
        include
        src
        libs)

add_library(libnao2gto ${INCLUDE_FILES} ${SRC_FILES} ${LIBS} main.cpp src/InputHandler.cpp src/InputHandler.h src/exceptions/LoadException.h src/Orbital.cpp src/Orbital.h)

# Executable
add_executable(nao2gto ${INCLUDE_FILES} ${SRC_FILES} main.cpp)

# Tests suites
add_executable(tests ${INCLUDE_FILES} ${SRC_FILES} ${UNIT_TESTS} tests/OrbitalTest.cpp tests/InputHandlerTest.cpp tests/Test.cpp)