//
// Created by gregory on 10.04.2021.
//

#include "set_node.hpp"

template<typename T>
set_node<T>::set_node(const T &data) {
    set_node<T>();

    this->data = data;
}

template<typename T>
set_node<T>::set_node(std::shared_ptr<set_node<T>> &node) {
    set_node<T>(node.data);

    this->next = node.next;
}

template<typename T>
bool set_node<T>::operator==(const std::shared_ptr<set_node<T>> &node) const {
    return this == node;
}

template<typename T>
bool set_node<T>::operator!=(const std::shared_ptr<set_node<T>> &node) const {
    return this != node;
}
