//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_ITERATOR_H
#define LAB_02_SET_ITERATOR_H

#include <iterator>

#include <set_node.h>

template<typename T>
class set_iterator : public std::iterator<std::input_iterator_tag, T> {
    std::weak_ptr<set_node<T>> cur;

public:
    set_iterator();
    explicit set_iterator(const std::shared_ptr<set_node<T>> &node);
    set_iterator(const set_iterator<T> &iterator);
    ~set_iterator() = default;

    virtual void next();

    set_node<T> *operator->();
    set_node<T> &operator*();
    set_iterator<T> &operator++();

    bool operator!=(const set_iterator<T> &iterator) const;
    bool operator==(const set_iterator<T> &iterator) const;
    explicit operator bool() const;
};

#include <set_iterator.hpp>

#endif//LAB_02_SET_ITERATOR_H
