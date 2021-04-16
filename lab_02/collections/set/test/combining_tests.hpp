//
// Created by gregory on 16.04.2021.
//

#ifndef LAB_02_COMBINING_TESTS_HPP
#define LAB_02_COMBINING_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(CombineTest, EmptyWithConst) {
    auto a = set<int>();
    auto t = a.combine(6);
    EXPECT_EQ(t, (set<int>{6}));
}

TEST(CombineTest, EmptyWithVariable) {
    auto a = set<int>();
    auto v = 6;
    auto t = a.combine(v);
    EXPECT_EQ(t, (set<int>{6}));
}

TEST(CombineTest, EmptyWithSet) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    auto t = a.combine(b);
    EXPECT_EQ(t, (set<int>{1, 2, 3, 4}));
}

TEST(CombineTest, EmptyWithConstOperator) {
    auto a = set<int>();
    auto t = a | 6;
    EXPECT_EQ(t, (set<int>{6}));
}

TEST(CombineTest, EmptyWithVariableOperator) {
    auto a = set<int>();
    auto v = 6;
    auto t = a | v;
    EXPECT_EQ(t, (set<int>{6}));
}

TEST(CombineTest, EmptyWithSetOperator) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    auto t = a | b;
    EXPECT_EQ(t, (set<int>{1, 2, 3, 4}));
}


#endif//LAB_02_COMBINING_TESTS_HPP
