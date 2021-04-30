//
// Created by gregory on 16.04.2021.
//

#ifndef LAB_02_SYMMETRIC_DIFFERENCE_TESTS_HPP
#define LAB_02_SYMMETRIC_DIFFERENCE_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(SymmetricDifferenceTest, EmptySets) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a.symmetric_difference(b), set<int>());
}

TEST(SymmetricDifferenceTest, EmptySetsOperator) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a ^ b, set<int>());
}

TEST(SymmetricDifferenceTest, EmptySetsOperator2) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a ^= b, set<int>());
}

TEST(SymmetricDifferenceTest, NonAndEmptySet) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>();
    EXPECT_EQ(a.symmetric_difference(b), (set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, NonAndEmptySetOperator) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>();
    EXPECT_EQ(a ^ b, (set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, NonAndEmptySetOperator2) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>();
    EXPECT_EQ(a ^= b, (set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, EmptyAndNonSet) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.symmetric_difference(b), (set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, EmptyAndNonSetOperator) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a ^ b, (set<int>{1, 2, 3, 4}));
}

TEST(SymmetricDifferenceTest, NonEmptySet) {
    auto a = set<int>{3, 4, 5, 6, 7, 8};
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.symmetric_difference(b), (set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator) {
    auto a = set<int>{3, 4, 5, 6, 7, 8};
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a ^ b, (set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator2) {
    auto a = set<int>{3, 4, 5, 6, 7, 8};
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a ^= b, (set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySet_2) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>{3, 4, 5, 6, 7, 8};
    EXPECT_EQ(a.symmetric_difference(b), (set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator_2) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>{3, 4, 5, 6, 7, 8};
    EXPECT_EQ(a ^ b, (set<int>{1, 2, 5, 6, 7, 8}));
}

TEST(SymmetricDifferenceTest, NonEmptySetOperator_22) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>{3, 4, 5, 6, 7, 8};
    EXPECT_EQ(a ^= b, (set<int>{1, 2, 5, 6, 7, 8}));
}

#endif//LAB_02_SYMMETRIC_DIFFERENCE_TESTS_HPP
