//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_H
#define LAB_02_SET_H


#include <memory>

#include <base_collection.hpp>
#include <const_set_iterator.h>
#include <set_iterator.h>
#include <set_node.h>

template<typename T>
class set : public base_collection {
    std::shared_ptr<set_node<T>> head;

protected:
    std::pair<set_iterator<T>, bool> insert(const std::shared_ptr<set_node<T>> &node);

public:
    set() = default;
    set(set<T> &list);
    set(set<T> &&list) noexcept;
    set(std::initializer_list<T> elems);

    ~set() override = default;

    // Modifiers
    std::pair<set_iterator<T>, bool> insert(const T &value);
    std::pair<set_iterator<T>, bool> insert(T &&value);
    void insert(std::initializer_list<T> ilist);

    void clear() override;

    // Capacity
    size_t get_size();

    bool empty() const override;

    //Lookup
    size_t count(const T &key) const;

    set_iterator<T> find(const T &key);

    // Non-member
    bool operator==(const set<T> &list) const;
    bool operator!=(const set<T> &list) const;

    set<T> &operator+=(set<T> &set);
    set<T> &operator+=(const T &data);
    set<T> &operator+=(T &&data);

    set<T> &operator+(set<T> &set);
    set<T> &operator+(T &data);
    set<T> &operator+(const T &data);

    // Iterators
    set_iterator<T> begin();
    const_set_iterator<T> cbegin();

    set_iterator<T> end();
    const_set_iterator<T> cend();
};

#include <set.hpp>

#endif//LAB_02_SET_H
