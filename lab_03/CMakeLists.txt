cmake_minimum_required(VERSION 3.0)
project(lab_03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME}
        ./src/main.cpp
        src/gui/qt/mainwindow.h
        src/gui/qt/mainwindow.cpp
        src/qt/drawer/qt_drawer.h
        src/qt/drawer/qt_drawer.cpp
        src/qt/qt_drawer_factory.h
        src/qt/qt_drawer_factory.cpp
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        ./libs/driver/include
        ./src/
        )

add_subdirectory(./libs/driver)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} driver)
