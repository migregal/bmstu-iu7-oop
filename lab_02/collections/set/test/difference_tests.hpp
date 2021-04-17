//
// Created by gregory on 16.04.2021.
//

#ifndef LAB_02_DIFFERENCE_TESTS_HPP
#define LAB_02_DIFFERENCE_TESTS_HPP


#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(DifferenceTest, EmptySets) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a.difference(b), set<int>());
}

TEST(DifferenceTest, EmptySetsOperator) {
    auto a = set<int>();
    auto b = set<int>();
    EXPECT_EQ(a - b, set<int>());
}

TEST(DifferenceTest, EmptySetsOperator2) {
    auto a = set<int>();
    auto b = set<int>();
    a -= b;
    EXPECT_EQ(a, set<int>());
}

TEST(DifferenceTest, NonAndEmptySet) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>();
    EXPECT_EQ(a.difference(b), (set<int>{1, 2, 3, 4}));
}

TEST(DifferenceTest, NonAndEmptySetOperator) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>();
    EXPECT_EQ(a - b, (set<int>{1, 2, 3, 4}));
}

TEST(DifferenceTest, NonAndEmptySetOperator2) {
    auto a = set<int>{1, 2, 3, 4};
    auto b = set<int>();
    a -= b;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4}));
}

TEST(DifferenceTest, EmptyAndNonSet) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.difference(b), set<int>());
}

TEST(DifferenceTest, EmptyAndNonSetOperator) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a - b, set<int>());
}

TEST(DifferenceTest, EmptyAndNonSetOperator2) {
    auto a = set<int>();
    auto b = set<int>{1, 2, 3, 4};
    a -= b;
    EXPECT_EQ(a, set<int>());
}

TEST(DifferenceTest, NonEmptySet) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.difference(b), set<int>{5});
}

TEST(DifferenceTest, NonEmptySetOperator) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a - b, set<int>{5});
}

TEST(DifferenceTest, NonEmptySetOperator2) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{1, 2, 3, 4};
    a -= b;
    EXPECT_EQ(a, set<int>{5});
}

TEST(DifferenceTest, NonEmptySet_2) {
    auto a = set<int>{3, 4, 5, 6};
    auto b = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(a.difference(b), (set<int>{6}));
}

TEST(DifferenceTest, NonEmptySetOperator_2) {
    auto a = set<int>{3, 4, 5, 6};
    auto b = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(a - b, (set<int>{6}));
}

TEST(DifferenceTest, NonEmptySetOperator_2_2) {
    auto a = set<int>{3, 4, 5, 6};
    auto b = set<int>{1, 2, 3, 4, 5};
    a -= b;
    EXPECT_EQ(a, (set<int>{6}));
}

TEST(DifferenceTest, NonEmptySet_3) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{3, 4, 5, 6};
    EXPECT_EQ(a.difference(b), (set<int>{1, 2}));
}

TEST(DifferenceTest, NonEmptySetOperator_3) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{3, 4, 5, 6};
    EXPECT_EQ(a - b, (set<int>{1, 2}));
}

TEST(DifferenceTest, NonEmptySetOperator_32) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = set<int>{3, 4, 5, 6};
    a -= b;
    EXPECT_EQ(a, (set<int>{1, 2}));
}

#endif//LAB_02_DIFFERENCE_TESTS_HPP
