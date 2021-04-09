//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_ITERATOR_HPP
#define LAB_02_SET_ITERATOR_HPP

#include <iterator>

#include <set_node.hpp>

template<typename T>
class set_iterator : public std::iterator<std::input_iterator_tag, T> {
    std::weak_ptr<set_node<T>> cur;

public:
    ~set_iterator() = default;
};


#endif//LAB_02_SET_ITERATOR_HPP
