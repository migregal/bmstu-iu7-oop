#include <iostream>
#include <set.h>

#include <gtest/gtest.h>


TEST(EqualTest, Positive) {
    set<int> a;
    EXPECT_EQ(a, set<int>());

    auto b = set<int>{1, 2, 3, 4};
    EXPECT_EQ(b, (set<int>{1, 2, 3, 4}));
}

TEST(EqualTest, Negative) {
    set<int> a;
    EXPECT_NE(a, (set<int>{1}));

    auto b = set<int>{1, 2, 3, 4};
    EXPECT_NE(b, set<int>());
}

TEST(ConstructorTest, Positive) {
    set<int> a;
    EXPECT_EQ(a.empty(), true);

    auto b = a;
    EXPECT_EQ(b.empty(), true);

    auto c = set<int>{1, 2, 3, 4, 5};
    EXPECT_EQ(c, (set<int>{1, 2, 3, 4, 5}));

    auto d = set<int>{5, 4, 3, 2, 1};
    EXPECT_EQ(d, (set<int>{1, 2, 3, 4, 5}));

    auto e = set<int>{5, 10, 1, 12, 4};
    EXPECT_EQ(e, (set<int>{1, 4, 5, 10, 12}));

    auto f = set<int>{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    EXPECT_EQ(f, (set<int>{1, 2, 3, 4, 5}));
}

TEST(InsertTest, Positive) {
    auto a = set<int>{1, 2, 3, 4, 5};
    a.insert(6);
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6}));


    a.insert(7);
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6, 7}));

    a.insert({8, 9, 10});
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));

    a.insert({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21}));
}

TEST(ClearTest, Positive) {
    auto a = set<int>();
    a.clear();
    EXPECT_EQ(a.empty(), true);

    auto b = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    b.clear();
    EXPECT_EQ(b.empty(), true);
}

TEST(OperatorsTest, Positive) {
    auto a = set<int>{1, 2, 3, 4};
    a += 10;
    a += 5;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 10}));

    auto val = 21;
    a += val;
    a += ++val;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 10, 21, 22}));

    auto b = set<int>{11, 12, 13, 14};
    a += b;
    EXPECT_EQ(a, (set<int>{1, 2, 3, 4, 5, 10, 11, 12, 13, 14, 21, 22}));


    auto c = set<int>{1, 2, 3, 4};
    auto d = set<int>{5, 6, 7, 8};
    EXPECT_EQ(c + d, (set<int>{1, 2, 3, 4, 5, 6, 7, 8}));

    EXPECT_EQ(c + 10 + 23, (set<int>{1, 2, 3, 4, 10, 23}));
}

TEST(SearchTest, Positive) {
    auto a = set<int>{1, 2, 3, 4};

    EXPECT_EQ(a.find(5), a.end());
    EXPECT_NE(a.find(4), a.end());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
