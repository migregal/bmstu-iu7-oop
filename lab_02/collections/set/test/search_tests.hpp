//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_SEARCH_TESTS_HPP
#define LAB_02_SEARCH_TESTS_HPP

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(SearchTest, Found) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_NE(a.find(4), a.cend());
}

TEST(SearchTest, NotFound) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.find(5), a.cend());
}

#endif//LAB_02_SEARCH_TESTS_HPP
