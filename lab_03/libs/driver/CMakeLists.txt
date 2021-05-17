cmake_minimum_required(VERSION 3.0)

project(driver)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -lconfig++")

set(OBJECTS
        src/objects/object.h
        src/objects/model/details/point/point.h
        src/objects/model/details/point/point.cpp
        src/objects/model/details/edge/edge.h
        src/objects/model/details/edge/edge.cpp
        src/objects/model/details/details.h
        src/objects/model/details/details.cpp
        src/objects/model/model.h
        src/objects/model/model.cpp
        src/objects/camera/camera.h
        src/objects/camera/camera.cpp
        src/objects/composite/composite.h
        src/objects/composite/composite.cpp
        src/scene/scene.h
        src/scene/scene.cpp
        )

set(DRAWERS
        include/driver/drawer/abstract_drawer.h
        )

set(MANAGERS
        src/managers/base_manager.h

        src/managers/draw/draw_manager.h
        src/managers/draw/draw_manager.cpp
        src/managers/draw/draw_manager_creator.h
        src/managers/draw/draw_manager_creator.cpp

        src/managers/reform/reform_manager.h
        src/managers/reform/reform_manager.cpp
        src/managers/reform/reform_manager_creator.h
        src/managers/reform/reform_manager_creator.cpp

        src/managers/scene/scene_manager.h
        src/managers/scene/scene_manager.cpp
        src/managers/scene/scene_manager_creator.h
        src/managers/scene/scene_manager_creator.cpp

        src/managers/load/load_manager.h
        src/managers/load/load_manager.cpp
        src/managers/load/load_manager_creator.h
        src/managers/load/load_manager_creator.cpp

        src/visitor.h
        )

set(LOAD
        src/load_controller/abstract_load_controller.h
        src/load_controller/abstract_load_controller.cpp

        src/load_controller/model/model_load_controller.h
        src/load_controller/model/model_load_controller.cpp
        src/load_controller/model/model_load_controller_creator.h
        src/load_controller/model/model_load_controller_creator.cpp

        src/load_controller/scene/scene_load_controller.h
        src/load_controller/scene/scene_load_controller.cpp
        src/load_controller/scene/scene_load_controller_creator.h
        src/load_controller/scene/scene_load_controller_creator.cpp

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
        include/driver/drawer/abstract_drawer_factory.h
        )

set(CONFIGURATION
        include/driver/configuration/configuration_creator.h
        src/configuration/configuration_creator.cpp

        include/driver/configuration/abstract_configuration.h
        src/configuration/libconf/libconf_configuration.h
        src/configuration/libconf/libconf_configuration.cpp
        )

add_library(${PROJECT_NAME}
        ${OBJECTS}
        ${DRAWERS}
        ${MANAGERS}
        ${LOAD}
        ${FACADE}
        ${SRCS}
        ${PUB_INC}
        ${CONFIGURATION}
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ./include/driver/
        ./src/)

target_link_libraries(${PROJECT_NAME} config++)
