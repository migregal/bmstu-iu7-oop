cmake_minimum_required(VERSION 3.0)

project(driver)

set(CMAKE_CXX_STANDARD 20)

set(OBJECTS
        src/objects/object.h
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
        )

set(DRAWERS
        include/driver/base_drawer.h
        )

set(MANAGERS
        src/managers/base_manager.h
        src/managers/draw_manager.h
        src/managers/draw_manager.cpp
        src/managers/reform_manager.h
        src/managers/reform_manager.cpp
        src/managers/scene_manager.h
        src/managers/scene_manager.cpp
        src/managers/load_manager.h
        src/managers/load_manager.cpp
        src/visitor.h
        )

set(LOAD
        src/load/abstract_loader.h
        src/load/abstract_loader.cpp
        src/load/model_loader.h
        src/load/model_loader.cpp

        src/load/base_loader.h
        src/load/file_loader.h
        src/load/file_loader.cpp

        src/load/base_builder.h
        src/load/model_builder.h
        src/load/model_builder.cpp
        )

set(CONTROLLER
        src/controller/abstract_controller_creator.h
        src/controller/base_controller_creator.h
        src/controller/base_controller_creator.cpp
        src/controller/abstract_controller.h
        src/controller/base_controller.h
        src/controller/base_controller.cpp
        include/driver/facade/facade.h
        src/facade/facade.cpp
        )

set(PUB_INC
        include/driver/commands/base_command.h
        include/driver/commands/camera_command.h
        src/command/camera_command.cpp
        include/driver/commands/model_command.h
        src/command/model_command.cpp
        include/driver/commands/scene_command.h
        src/command/scene_command.cpp
        include/driver/error.h
        include/driver/abstract_fabric.h
        )

add_library(${PROJECT_NAME}
        ${OBJECTS}
        ${DRAWERS}
        ${MANAGERS}
        ${LOAD}
        ${CONTROLLER}
        ${PUB_INC}
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ./include/driver/
        ./src/)
