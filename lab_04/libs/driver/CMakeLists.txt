cmake_minimum_required(VERSION 3.0)

project(driver)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(SOURCES
        src/button.h
        src/button.cpp
        src/cabin.h
        src/cabin.cpp
        src/controller.h
        src/controller.cpp
        src/Door.h
        src/Door.cpp
        src/lift.cpp
        )

set(PUB_INC
        include/driver/lift.h
        )

add_library(${PROJECT_NAME}
        ${SOURCES}
        ${PUB_INC}
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ./include/driver/
        ./src/)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})