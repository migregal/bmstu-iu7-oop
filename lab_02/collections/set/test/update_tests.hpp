//
// Created by gregory on 21.04.2021.
//

#include <gtest/gtest.h>
#include <set.h>

using namespace collections;

TEST(UpdateTest, ToEmptySet) {
    auto a = set<int>();
    auto v = 6;
    auto b = a.update(v);

    EXPECT_EQ(a, (set<int>{}));
    EXPECT_EQ(b, (set<int>{6}));
}

TEST(UpdateTest, ToEmptySetRValue) {
    auto a = set<int>();
    auto b = a.update(6);

    EXPECT_EQ(a, (set<int>{}));
    EXPECT_EQ(b, (set<int>{6}));
}

TEST(UpdateTest, SingleToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto v = 6;
    auto b = a.update(v);

    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(UpdateTest, SingleToNonEmptyRValue) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = a.update(6);

    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(UpdateTest, MultipleToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = a.update({8, 9, 10});

    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 5, 8, 9, 10}));
}

TEST(UpdateTest, MultipleRepeatedToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    auto b = a.update({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});

    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

TEST(UpdateTest, MultipleRepeatedArrayToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};

    int * b = new int[13]{3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21};
    auto c = a.update(b, 13);
    delete[] b;

    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));
    EXPECT_EQ(c, (set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}