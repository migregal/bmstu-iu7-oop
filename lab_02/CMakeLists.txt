cmake_minimum_required(VERSION 3.19)
project(lab_02)

set(CMAKE_CXX_STANDARD 11)

set(COLLECTIONS_DOMAIN collections)
set(BASE_SRC ${COLLECTIONS_DOMAIN}/base_collection.hpp)

set(SET_DOMEN collections/set)
set(SET_SRC
        ${SET_DOMEN}/set.cpp
        ${SET_DOMEN}/set.hpp)

set(SET_NODE_DOMEN ${SET_DOMEN}/node)
set(SET_NODE_SRC
        ${SET_NODE_DOMEN}/set_node.cpp
        ${SET_NODE_DOMEN}/set_node.hpp)

set(SET_ITERATOR_DOMEN ${SET_DOMEN}/iterator)
set(SET_ITERATOR_SRC
        ${SET_ITERATOR_DOMEN}/set_iterator.cpp
        ${SET_ITERATOR_DOMEN}/set_iterator.hpp)

include_directories(
        ${COLLECTIONS_DOMAIN}
        ${SET_DOMEN}
        ${SET_NODE_DOMEN}
        ${SET_ITERATOR_DOMEN})

add_executable(lab_02
        main.cpp
        ${BASE_SRC}
        ${SET_SRC}
        ${SET_ITERATOR_SRC}
        ${SET_NODE_SRC})