//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_OPERATORS_TESTS_HPP
#define LAB_02_OPERATORS_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(OperatorsTest, Assigment) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = a;
    EXPECT_EQ(b, a);
}

TEST(OperatorsTest, AssigmentClearing) {
    auto a = set<int>{1, 2, 3, 4};
    set<int> b;
    b = a;
    b.clear();
    EXPECT_EQ(b, set<int>());
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4}));
}

TEST(OperatorsTest, AddConst) {
    auto a = set<int>{1, 2, 3, 4};
    a += 10;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 10}));
}

TEST(OperatorsTest, AddVariable) {
    auto a = set<int>{1, 2, 3, 4};

    auto val = 21;
    a += ++val;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 22}));
}

TEST(OperatorsTest, AddSet) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>{11, 12, 13, 14};
    a += b;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 11, 12, 13, 14}));
}

TEST(OperatorsTest, SumSet) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>{5, 6, 7, 8};
    EXPECT_EQ(a + b, (set<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(OperatorsTest, SumConst) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a + 10 + 23, (set<int>{1, 2, 3, 4, 10, 23}));
}

TEST(OperatorsTest, SumVariable) {
    auto a = set<int>{1, 2, 3, 4};
    auto val = 10;
    EXPECT_EQ(a + val++ + val, (set<int>{1, 2, 3, 4, 10, 11}));
}

#endif//LAB_02_OPERATORS_TESTS_HPP
