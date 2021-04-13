//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_INSERTION_TESTS_HPP
#define LAB_02_INSERTION_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(InsertTest, ToEmptySet) {
    auto a = set<int>();
    auto v = 6;
    a.insert(v);
    EXPECT_EQ(a, (set<int>{6}));
}

TEST(InsertTest, ToEmptySetRValue) {
    auto a = set<int>();
    a.insert(6);
    EXPECT_EQ(a, (set<int>{6}));
}

TEST(InsertTest, SingleToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto v = 6;
    a.insert(v);
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(InsertTest, SingleToNonEmptyRValue) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert(6);
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(InsertTest, MultipleToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert({8, 9, 10});
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 8, 9, 10}));
}

TEST(InsertTest, MultipleRepeatedToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

#endif//LAB_02_INSERTION_TESTS_HPP
