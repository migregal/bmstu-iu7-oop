//
// Created by gregory on 12.04.2021.
//

#ifndef LAB_02_CONST_SET_ITERATOR_H
#define LAB_02_CONST_SET_ITERATOR_H

#include <iterator>

#include <set_node.h>

template<typename T>
class const_set_iterator : std::iterator<std::input_iterator_tag, T> {
protected:
    std::weak_ptr<set_node<T>> cur;

public:
    const_set_iterator();
    explicit const_set_iterator(const std::shared_ptr<set_node<T>> &node);
    const_set_iterator(const const_set_iterator<T> &iterator);

    ~const_set_iterator() = default;

    virtual void next();

    const T *operator->() const;
    const T &operator*() const;

    explicit operator bool() const;

    const_set_iterator<T> &operator=(const const_set_iterator<T> &iterator);
    const_set_iterator<T> &operator++();

    bool operator!=(const const_set_iterator<T> &iterator) const;
    bool operator==(const const_set_iterator<T> &iterator) const;
};

#include <const_set_iterator.hpp>

#endif//LAB_02_CONST_SET_ITERATOR_H
