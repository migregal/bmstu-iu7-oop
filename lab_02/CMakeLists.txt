cmake_minimum_required(VERSION 3.19)
project(lab_02)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#########
#  SRC  #
#########

set(COLLECTIONS_DOMAIN collections)
set(BASE_SRC
        ${COLLECTIONS_DOMAIN}/base_collection.hpp
        ${COLLECTIONS_DOMAIN}/errors.h)

set(SET_DOMAIN collections/set)
set(SET_SRC
        ${SET_DOMAIN}/set.hpp
        ${SET_DOMAIN}/set.h)

set(SET_NODE_DOMAIN ${SET_DOMAIN}/node)
set(SET_NODE_SRC
        ${SET_NODE_DOMAIN}/set_node.hpp
        ${SET_NODE_DOMAIN}/set_node.h)

set(SET_CONST_ITERATOR_DOMAIN ${SET_DOMAIN}/const_iterator)
set(SET_CONST_ITERATOR_SRC
        ${SET_CONST_ITERATOR_DOMAIN}/const_set_iterator.hpp
        ${SET_CONST_ITERATOR_DOMAIN}/const_set_iterator.h)

###########
#  Tests  #
###########

set(SET_TESTS_DOMAIN ${SET_DOMAIN}/test)
set(TESTS_SRC
        ${SET_TESTS_DOMAIN}/set_tests.hpp
        ${SET_TESTS_DOMAIN}/constructor_tests.hpp
        ${SET_TESTS_DOMAIN}/equality_tests.hpp
        ${SET_TESTS_DOMAIN}/insertion_tests.hpp
        ${SET_TESTS_DOMAIN}/erase_tests.hpp
        ${SET_TESTS_DOMAIN}/clear_tests.hpp
        ${SET_TESTS_DOMAIN}/operators_tests.hpp
        ${SET_TESTS_DOMAIN}/search_tests.hpp
        ${SET_TESTS_DOMAIN}/lookup_tests.h
        ${SET_TESTS_DOMAIN}/combining_tests.hpp
        ${SET_TESTS_DOMAIN}/intersection_tests.h)

##############
#  Dir conf  #
##############

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${COLLECTIONS_DOMAIN}
        ${SET_DOMAIN}
        ${SET_NODE_DOMAIN}
        ${SET_CONST_ITERATOR_DOMAIN}
        ${SET_TESTS_DOMAIN})

################
#  Executable  #
################

add_executable(lab_02
        main.cpp
        ${BASE_SRC}
        ${SET_SRC}
        ${SET_ITERATOR_SRC}
        ${SET_CONST_ITERATOR_SRC}
        ${SET_NODE_SRC}
        ${TESTS_SRC})

##########
#  Libs  #
##########

target_link_libraries(
        lab_02 ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()