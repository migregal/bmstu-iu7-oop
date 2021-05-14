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
        src/control_panel/control_panel.h
        src/control_panel/control_panel.cpp
        src/cabin/cabin.h
        src/cabin/cabin.cpp
        src/door/door.h
        src/door/door.cpp
        src/lift/lift.cpp
        src/constants.h
        )

set(PUB_INC
        include/driver/lift.h
        include/driver/pub_consts.h
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