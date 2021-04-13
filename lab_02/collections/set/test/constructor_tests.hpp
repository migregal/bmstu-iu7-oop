//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_CONSTRUCTOR_TESTS_HPP
#define LAB_02_CONSTRUCTOR_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(ConstructorTest, Default) {
    set<int> a;
    EXPECT_EQ(a.empty(), true);
}

TEST(ConstructorTest, Copy) {
    set<int> a{1, 2, 3, 4, 5};
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));

    auto b = a;
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, SortedInitList) {
    auto c = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(c, (set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, ReversedInitList) {
    auto d = set<int>{5, 4, 3, 2, 1};
    EXPECT_EQ(d, (set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, RandomInitList) {
    auto e = set<int>{5, 10, 1, 12, 4};
    EXPECT_EQ(e, (set<int>{1, 4, 5, 10, 12}));
}

TEST(ConstructorTest, RepeatedInitList) {
    auto f = set<int>{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    EXPECT_EQ(f, (set<int>{1, 2, 3, 4, 5}));
}

#endif//LAB_02_CONSTRUCTOR_TESTS_HPP
