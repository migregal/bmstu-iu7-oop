//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_ITERATOR_H
#define LAB_02_SET_ITERATOR_H

#include <iterator>

#include <set.h>
#include <set_node.h>

template<typename T>
class set_iterator : public const_set_iterator<T> {
    virtual set_node<T> &get_cur();

public:
    set_iterator();
    explicit set_iterator(const std::shared_ptr<set_node<T>> &node);
    set_iterator(const set_iterator<T> &iterator);

    ~set_iterator() = default;

    T *operator->();
    T &operator*();

    set_iterator<T> &operator=(const set_iterator<T> &iterator);
    set_iterator<T> &operator++() override;
    set_iterator<T> &operator--() override;

    bool operator!=(const set_iterator<T> &iterator) const;
    bool operator==(const set_iterator<T> &iterator) const;

    template<typename U>
    friend class set;
};

#include <set_iterator.hpp>

#endif//LAB_02_SET_ITERATOR_H
