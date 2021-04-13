//
// Created by gregory on 14.04.2021.
//

#ifndef LAB_02_ERASE_TESTS_HPP
#define LAB_02_ERASE_TESTS_HPP


#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(EraseTest, Empty) {
    auto b = set<int>{};
    EXPECT_THROW(b.erase(b.find(5)), size_error);
}

TEST(EraseTest, NonEmptyIncorrect) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};

    EXPECT_THROW(b.erase(b.find(10)), iterator_error);
}

TEST(EraseTest, NonEmptyCorrect) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.erase(b.find(5));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 9, 12, 21}));
}

TEST(EraseTest, EmptyIncorrectList) {
    set<int> b;
    EXPECT_THROW(b.erase(b.find(0), b.find(13)), size_error);
}

TEST(EraseTest, NonEmptyIncorrectList) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    EXPECT_THROW(b.erase(b.find(0), b.find(13)), iterator_error);
}

TEST(EraseTest, NonEmptyPartialList) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    EXPECT_THROW(b.erase(b.find(4), b.find(13)), iterator_error);
}

TEST(EraseTest, NonEmptyCorrectList) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.erase(b.find(5), b.find(12));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 12, 21}));
}

#endif//LAB_02_ERASE_TESTS_HPP
