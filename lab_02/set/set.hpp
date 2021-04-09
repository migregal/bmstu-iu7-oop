//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <memory>

#include <set_node.hpp>

template<typename T>
class set {
private:
    size_t size;
    std::shared_ptr<set_node<T>> head;
    std::shared_ptr<set_node<T>> tail;
};


#endif//LAB_02_SET_HPP
