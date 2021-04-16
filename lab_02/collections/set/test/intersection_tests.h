//
// Created by gregory on 16.04.2021.
//

#ifndef LAB_02_INTERSECTION_TESTS_H
#define LAB_02_INTERSECTION_TESTS_H

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(IntersectionTest, EmptySets) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a.intersect(b), (set<int>()));
}

TEST(IntersectionTest, EmptyAndConst) {
    auto a = set<int>();
    EXPECT_EQ(a.intersect(5), (set<int>()));
}

TEST(IntersectionTest, EmptyAndVariable) {
    auto a = set<int>();
    auto v = 5;
    EXPECT_EQ(a.intersect(v), (set<int>()));
}

TEST(IntersectionTest, NonAndEmptySet) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>();
    EXPECT_EQ(a.intersect(b), (set<int>()));
}

TEST(IntersectionTest, NonEmptySet) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{3, 4, 5, 6, 7};
    EXPECT_EQ(a.intersect(b), (set<int>{3, 4, 5}));
}

TEST(IntersectionTest, NonEmptyAndConst) {
    auto a = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(a.intersect(5), (set<int>{5}));
}

TEST(IntersectionTest, NonEmptyAndVariable) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto v = 5;
    EXPECT_EQ(a.intersect(v), (set<int>{5}));
}

TEST(IntersectionTest, EmptySetsOperator) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a & b, (set<int>()));
}

TEST(IntersectionTest, EmptySetAndConstOperator) {
    auto a = set<int>();
    EXPECT_EQ(a & 5, (set<int>()));
}

TEST(IntersectionTest, EmptySetsAndVariableOperator) {
    auto a = set<int>();
    auto v = 5;
    EXPECT_EQ(a & v, (set<int>()));
}

TEST(IntersectionTest, NonAndEmptySetOperator) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>();
    EXPECT_EQ(a & b, (set<int>()));
}

TEST(IntersectionTest, NonEmptySetOperator) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{3, 4, 5, 6, 7};
    EXPECT_EQ(a & b, (set<int>{3, 4, 5}));
}

TEST(IntersectionTest, NonEmptyAndConstOperator) {
    auto a = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(a & 5, (set<int>{5}));
}

TEST(IntersectionTest, NonEmptyAndVariableOperator) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto v = 5;
    EXPECT_EQ(a & v, (set<int>{5}));
}

#endif//LAB_02_INTERSECTION_TESTS_H
