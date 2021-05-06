cmake_minimum_required(VERSION 3.19)

project(driver)

set(CMAKE_CXX_STANDARD 20)

set(OBJECTS
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
        src/objects/composite.h
        src/objects/composite.cpp
        src/scene/scene.h
        src/scene/scene.cpp

        src/drawer/drawer.h
        )

set(DRAWERS
        src/drawer/drawer.h
        )

set(MANAGERS
        src/managers/base_manager.h
        src/managers/draw_manager.h
        src/managers/draw_manager.cpp
        src/managers/reform_manager.h
        src/managers/reform_manager.cpp
        src/managers/scene_manager.h
        src/managers/scene_manager.cpp
        )

set(COLLECTIONS
        src/vector/vector.h
        src/vector/vector.hpp
        src/vector/iterator.h
        src/vector/iterator.hpp
        )

set(PUB_INC
        include/driver/visitor.h
        include/driver/error.h
        )

add_library(${PROJECT_NAME} ${OBJECTS} ${DRAWERS} ${MANAGERS} ${COLLECTIONS} ${PUB_INC})

target_include_directories(${PROJECT_NAME} PRIVATE
        ./include/driver/
        ./src/)
