cmake_minimum_required(VERSION 3.17)
project(Refractor)

set(CMAKE_CXX_STANDARD 20)
configure_file(indextest.ind ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
add_executable(Refractor main.cpp loadIndex.cpp loadIndex.h)