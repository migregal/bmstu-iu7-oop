//
// Created by gregory on 12.04.2021.
//

#ifndef LAB_02_SET_TESTS_HPP
#define LAB_02_SET_TESTS_HPP

#include <set.h>
#include <gtest/gtest.h>

TEST(EqualTest, EmptyEqual) {
    set<int> a;
    EXPECT_EQ(a, set<int>());
}

TEST(EqualTest, NonEmptyEqual) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4}));
}

TEST(EqualTest, EmptyNonEqual) {
    set<int> a;
    EXPECT_NE(a, (set<int>{1}));
}

TEST(EqualTest, NonEmptyNonEqual) {
    auto b = set<int>{1, 2, 3, 4};
    EXPECT_NE(b, set<int>());
}

TEST(ConstructorTest, Default) {
    set<int> a;
    EXPECT_EQ(a.empty(), true);
}

TEST(ConstructorTest, Copy) {
    set<int> a{1, 2, 3, 4, 5};
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5}));

    auto b = a;
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, SortedInitList) {
    auto c = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(c, (set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, ReversedInitList) {
    auto d = set<int>{5, 4, 3, 2, 1};
    EXPECT_EQ(d, (set<int>{1, 2, 3, 4, 5}));
}

TEST(ConstructorTest, RandomInitList) {
    auto e = set<int>{5, 10, 1, 12, 4};
    EXPECT_EQ(e, (set<int>{1, 4, 5, 10, 12}));
}

TEST(ConstructorTest, RepeatedInitList) {
    auto f = set<int>{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    EXPECT_EQ(f, (set<int>{1, 2, 3, 4, 5}));
}

TEST(InsertTest, ToEmptySet) {
    auto a = set<int>();
    a.insert(6);
    EXPECT_EQ(a, (set<int>{6}));
}

TEST(InsertTest, SingleToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert(6);
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6}));
}

TEST(InsertTest, MultipleToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert({8, 9, 10});
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 8, 9, 10}));
}

TEST(InsertTest, MultipleRepeatedToNonEmpty) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 9, 12, 21}));
}

TEST(EraseTest, Empty) {
    auto b = set<int>{};
    auto s = b.find(5);
    EXPECT_EQ(b.erase(const_set_iterator<int>(s)), set_iterator<int>(nullptr));
}

TEST(EraseTest, NonEmptyIncorrect) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    auto s = b.find(10);
    EXPECT_EQ(b.erase(const_set_iterator<int>(s)), set_iterator<int>(nullptr));
}

TEST(EraseTest, NonEmptyCorrect) {
    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.erase(const_set_iterator<int>(b.find(5)));
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4, 9, 12, 21}));
}

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

TEST(SearchTest, Found) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_NE(a.find(4), a.end());
}

TEST(SearchTest, NotFound) {
    auto a = set<int>{1, 2, 3, 4};
    EXPECT_EQ(a.find(5), a.end());
}

#endif//LAB_02_SET_TESTS_HPP
