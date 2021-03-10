cmake_minimum_required(VERSION 3.17)
project(lab_01)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(UI_DOMAIN ./ui)
set(LOGIC_DOMAIN ./logic)
set(MEDIATOR_DOMAIN ./mediator)

include_directories(${UI_DOMAIN})
include_directories(${LOGIC_DOMAIN})
include_directories(${LOGIC_DOMAIN}/drawer)
include_directories(${LOGIC_DOMAIN}/dataset)
include_directories(${LOGIC_DOMAIN}/dataset/edges)
include_directories(${LOGIC_DOMAIN}/dataset/vertices)
include_directories(${LOGIC_DOMAIN}/dataset/transformation)
include_directories(${LOGIC_DOMAIN}/errors)
include_directories(${LOGIC_DOMAIN}/provider)
include_directories(${MEDIATOR_DOMAIN})

add_executable(
        ${PROJECT_NAME}
        ${UI_DOMAIN}/main.cpp
        ${UI_DOMAIN}/MainWindow.cpp
        ${UI_DOMAIN}/MainWindow.h
        ${LOGIC_DOMAIN}/provider/provider.cpp
        ${LOGIC_DOMAIN}/provider/provider.h
        ${LOGIC_DOMAIN}/errors/errors.cpp
        ${LOGIC_DOMAIN}/errors/errors.h
        ${LOGIC_DOMAIN}/drawer/drawer.h
        ${LOGIC_DOMAIN}/dataset/dataset.cpp
        ${LOGIC_DOMAIN}/dataset/dataset.cpp
        ${LOGIC_DOMAIN}/dataset/dataset.h
        ${LOGIC_DOMAIN}/dataset/edges/edges.cpp
        ${LOGIC_DOMAIN}/dataset/edges/edges.h
        ${LOGIC_DOMAIN}/dataset/vertices/vertices.cpp
        ${LOGIC_DOMAIN}/dataset/vertices/vertices.h
        ${LOGIC_DOMAIN}/dataset/transformation/transformation.cpp
        ${LOGIC_DOMAIN}/dataset/transformation/transformation.h
        ${LOGIC_DOMAIN}/drawer/drawer.cpp
        ${MEDIATOR_DOMAIN}/drawer_mediator.h
        ${MEDIATOR_DOMAIN}/drawer_mediator.cpp)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
