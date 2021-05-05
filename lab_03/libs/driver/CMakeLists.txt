cmake_minimum_required(VERSION 3.19)

project(driver)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/object.h
        src/objects/point.h
        src/objects/point.cpp
        src/objects/edge.h
        src/objects/edge.cpp
        src/vector/vector.h
        src/vector/vector.hpp
        src/vector/iterator.h
        src/vector/iterator.hpp
        )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ./include/driver/
        ./src/)
