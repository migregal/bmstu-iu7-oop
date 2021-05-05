cmake_minimum_required(VERSION 3.19)

project(driver)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        src/object.h
        src/objects/point.h
        src/objects/point.cpp
        src/objects/edge.h
        src/objects/edge.cpp
        src/objects/details.h
        src/objects/details.cpp
        src/objects/model.h
        src/objects/model.cpp
        src/objects/camera.h
        src/objects/camera.cpp

        src/vector/vector.h
        src/vector/vector.hpp
        src/vector/iterator.h
        src/vector/iterator.hpp

        include/driver/visitor.h
        )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ./include/driver/
        ./src/)
