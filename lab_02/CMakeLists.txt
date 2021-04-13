cmake_minimum_required(VERSION 3.19)
project(lab_02)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(COLLECTIONS_DOMAIN collections)
set(BASE_SRC
        ${COLLECTIONS_DOMAIN}/base_collection.hpp
        ${COLLECTIONS_DOMAIN}/errors.h)

set(SET_DOMEN collections/set)
set(SET_SRC
        ${SET_DOMEN}/set.hpp
        ${SET_DOMEN}/set.h
        ${SET_DOMEN}/set_tests.hpp)

set(SET_NODE_DOMEN ${SET_DOMEN}/node)
set(SET_NODE_SRC
        ${SET_NODE_DOMEN}/set_node.hpp
        ${SET_NODE_DOMEN}/set_node.h)

set(SET_ITERATOR_DOMEN ${SET_DOMEN}/iterator)
set(SET_ITERATOR_SRC
        ${SET_ITERATOR_DOMEN}/set_iterator.hpp
        ${SET_ITERATOR_DOMEN}/set_iterator.h)

set(SET_CONST_ITERATOR_DOMEN ${SET_DOMEN}/const_iterator)
set(SET_CONST_ITERATOR_SRC
        ${SET_CONST_ITERATOR_DOMEN}/const_set_iterator.hpp
        ${SET_CONST_ITERATOR_DOMEN}/const_set_iterator.h)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${COLLECTIONS_DOMAIN}
        ${SET_DOMEN}
        ${SET_NODE_DOMEN}
        ${SET_ITERATOR_DOMEN}
        ${SET_CONST_ITERATOR_DOMEN})

add_executable(lab_02
        main.cpp
        ${BASE_SRC}
        ${SET_SRC}
        ${SET_ITERATOR_SRC}
        ${SET_CONST_ITERATOR_SRC}
        ${SET_NODE_SRC})

target_link_libraries(
        lab_02 ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()