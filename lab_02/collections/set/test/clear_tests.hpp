//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_CLEAR_TESTS_HPP
#define LAB_02_CLEAR_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>


TEST(ClearTest, Empty) {
    auto a = set<int>();
    a.clear();
    EXPECT_EQ(a.empty(), true);
}

TEST(ClearTest, NonEmpty) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.clear();
    EXPECT_EQ(b.empty(), true);
}

#endif//LAB_02_CLEAR_TESTS_HPP
