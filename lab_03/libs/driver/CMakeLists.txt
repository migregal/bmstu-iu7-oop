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
        src/load_controller/abstract_load_controller.h
        src/load_controller/abstract_load_controller.cpp
        src/load_controller/model/model_load_controller.h
        src/load_controller/model/model_load_controller.cpp
        src/load_controller/scene/scene_load_controller.h
        src/load_controller/scene/scene_load_controller.cpp

        src/loader/base_loader.h
        src/loader/model/base_model_loader.h
        src/loader/model/file_model_loader.h
        src/loader/model/file_model_loader.cpp
        src/loader/camera/base_camera_loader.h
        src/loader/camera/file_camera_loader.h
        src/loader/camera/file_camera_loader.cpp
        src/loader/scene/base_scene_loader.h
        src/loader/scene/file_scene_loader.h
        src/loader/scene/file_scene_loader.cpp

        src/builder/base_builder.h
        src/builder/model/model_builder.h
        src/builder/model/model_builder.cpp
        src/builder/scene/scene_builder.h
        src/builder/scene/scene_builder.cpp
        src/builder/camera/camera_builder.h
        src/builder/camera/camera_builder.cpp
        )

set(FACADE
        include/driver/facade/facade.h
        src/facade/facade.cpp
        )

set(SRCS
        src/error/error.h
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
        ${FACADE}
        ${SRCS}
        ${PUB_INC}
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ./include/driver/
        ./src/)
