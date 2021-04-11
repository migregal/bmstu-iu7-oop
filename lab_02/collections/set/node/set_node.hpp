//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_NODE_HPP
#define LAB_02_SET_NODE_HPP

#include <memory>

template<typename T>
class set_node {
    T data;
    std::shared_ptr<set_node<T>> next;

public:
    set_node() = default;
    explicit set_node(const T &data);
    explicit set_node(std::shared_ptr<set_node<T>> &node);

    bool operator==(const std::shared_ptr<set_node<T>> &node) const;
    bool operator!=(const std::shared_ptr<set_node<T>> &node) const;

    void set(const T &value);
    const T &get() const;

    ~set_node() = default;
};


#endif//LAB_02_SET_NODE_HPP
