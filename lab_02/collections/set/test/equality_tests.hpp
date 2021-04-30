//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_EQUALITY_TESTS_HPP
#define LAB_02_EQUALITY_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(EqualTest, EmptyEqual) {
    set<int> a;
    EXPECT_EQ(a, set<int>());
}

TEST(EqualTest, NonEmptyEqual) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4}));
}

TEST(EqualTest, EmptyNonEqual) {
    set<int> a;
    EXPECT_NE(a, (set<int>{1}));
}

TEST(EqualTest, EmptyNotEqual) {
    set<int> b;
    EXPECT_EQ(set<int>{1} == b, false);
}

TEST(EqualTest, NonEmptyNonEqual) {
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_NE(b, set<int>());
}

TEST(EqualTest, NonEmptyNotEqual) {
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ((set<int>{5, 6, 7, 8} == b), false);
}

#endif//LAB_02_EQUALITY_TESTS_HPP
