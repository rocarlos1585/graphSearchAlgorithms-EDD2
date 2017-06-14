cmake_minimum_required(VERSION 3.6)
project(graphSearchAlgorithms_EDD2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp grafo.h stack.h)
add_executable(graphSearchAlgorithms_EDD2 ${SOURCE_FILES})