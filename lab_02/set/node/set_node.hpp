//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_NODE_HPP
#define LAB_02_SET_NODE_HPP

#include <memory>

template<typename T>
class set_node {
private:
    T data;
    std::shared_ptr<set_node<T>> next;

public:
    ~set_node() = default;
};


#endif//LAB_02_SET_NODE_HPP
