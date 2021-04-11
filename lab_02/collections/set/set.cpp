//
// Created by gregory on 10.04.2021.
//

#include "set.hpp"


template<typename T>
set<T>::set(set<T> &list) {
    set();

    // add copy here
}

template<typename T>
set<T>::set(set<T> &&list) noexcept {
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}

template<typename T>
set<T>::set(std::initializer_list<T> elems) {
}

template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(const T &data) {
    return std::pair<set_iterator<T>, bool>();
}

template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(T &&value) {
    return std::pair<set_iterator<T>, bool>();
}

template<typename T>
void set<T>::insert(std::initializer_list<T> ilist) {
}


template<typename T>
bool set<T>::is_empty() const {
    return false;
}

template<typename T>
void set<T>::clear() {
}
