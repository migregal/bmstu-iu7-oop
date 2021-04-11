//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_H
#define LAB_02_SET_H


#include <memory>

#include <base_collection.hpp>
#include <set_iterator.h>
#include <set_node.h>

template<typename T>
class set : public base_collection {
    size_t length = 0;
    std::shared_ptr<set_node<T>> head;
    std::shared_ptr<set_node<T>> tail;

protected:
    std::pair<set_iterator<T>, bool> insert(const std::shared_ptr<set_node<T>> &node);

public:
    set() = default;
    set(set<T> &list);
    set(set<T> &&list) noexcept;
    set(std::initializer_list<T> elems);

    ~set() override = default;

    // Modifiers
    std::pair<set_iterator<T>, bool> insert(const T &data);
    std::pair<set_iterator<T>, bool> insert(T &&value);
    void insert(std::initializer_list<T> ilist);

    void clear() override;

    // Capacity
    size_t size();

    bool empty() const override;

    //Lookup
    size_t count(const T &key) const;

    set_iterator<T> find(const T &key);

    // Non-member
    bool operator==(const set<T> &list) const;
    bool operator!=(const set<T> &list) const;

    set<T> &operator+=(const set<T> &set);
    set<T> &operator+=(const T &data);

    set<T> &operator+(const set<T> &set);
    set<T> &operator+(const T &data);

    // Iterators
    set_iterator<T> begin();

    set_iterator<T> end();
};

#include <set.hpp>

#endif//LAB_02_SET_H
