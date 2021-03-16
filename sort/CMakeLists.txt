cmake_minimum_required(VERSION 3.17)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(main ${PROJECT_SOURCE_DIR}/insertionsort.cpp)