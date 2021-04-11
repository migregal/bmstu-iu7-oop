#include <iostream>
#include <set.h>

void print_set(set<int> &set) {
    std::cout << set << std::endl;
}

void test_constructors() {
    std::cout << "Constructors test: " << std::endl;

    std::cout << "Constructor 1 test: " << std::endl;
    set<int> a;
    print_set(a);

    std::cout << "Constructor 2 test: " << std::endl;
    auto b = set<int>(a);
    print_set(b);

    std::cout << "Constructor 3 test: " << std::endl;
    auto c = set<int>{1, 2, 3, 4, 5};
    print_set(c);

    std::cout << "Constructor 4 test: " << std::endl;
    auto d = set<int>{5, 4, 3, 2, 1};
    print_set(d);

    std::cout << "Constructor 5 test: " << std::endl;
    auto e = set<int>{5, 10, 1, 12, 4};
    print_set(e);

    std::cout << "Constructor 6 test: " << std::endl;
    auto f = set<int>{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    print_set(f);
}

void test_insert() {
    std::cout << "Insert tests: " << std::endl;
    auto a = set<int>{1, 2, 3, 4, 5};
    print_set(a);

    std::cout << "Insert 1 test: " << std::endl;
    a.insert(6);
    print_set(a);

    std::cout << "Insert 2 test: " << std::endl;
    a.insert(7);
    print_set(a);

    std::cout << "Insert 3 test: " << std::endl;
    a.insert({8, 9, 10});
    print_set(a);

    std::cout << "Insert 4 test: " << std::endl;
    a.insert({3, 3, 3, 4, 4, 4, 4, 1, 2, 3, 9, 12, 21});
    print_set(a);
}

void clear_test() {
    std::cout << "Clear tests: " << std::endl;
    auto a = set<int>{1, 2, 3, 4, 5, 9, 12, 21};
    print_set(a);

    std::cout << "Clear 1 test: " << std::endl;
    a.clear();
    print_set(a);
}

void operators_test() {
    std::cout << "Operators tests: " << std::endl;
    auto a = set<int>{1, 2, 3, 4};
    print_set(a);

    std::cout << "Operators 1 tests: " << std::endl;
    a += 10;
    a += 5;

    print_set(a);

    auto val = 21;

    std::cout << "Operators 2 tests: " << std::endl;
    a += val;
    a += ++val;

    print_set(a);

    std::cout << "Operators 3 tests: " << std::endl;
    auto b = set<int>{11, 12, 13, 14};
    a += b;

    print_set(a);
}

int main() {
    test_constructors();

    std::cout << std::endl;

    test_insert();

    std::cout << std::endl;

    clear_test();

    operators_test();

    return 0;
}
