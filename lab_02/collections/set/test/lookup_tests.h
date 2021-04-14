//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_LOOKUP_TESTS_H
#define LAB_02_LOOKUP_TESTS_H

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(LookupTest, EmptySet) {
    auto a = set<int>();
    EXPECT_EQ(a.empty(), true);
}

TEST(LookupTest, EmptySetNonEmpty) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.empty(), false);
}

TEST(LookupTest, EmptySetCount) {
    auto a = set<int>();
    EXPECT_EQ(a.get_size(), 0);
}

TEST(LookupTest, NonEmptySetCount) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.get_size(), 4);
}

#endif//LAB_02_LOOKUP_TESTS_H
