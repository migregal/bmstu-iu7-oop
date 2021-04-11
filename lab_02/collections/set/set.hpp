//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP

#include <chrono>

template<typename T>
set<T>::set(set<T> &list) {
    set();

    for (auto node : list) {
        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw std::bad_alloc();
        }

        temp_node->set(node.get());
        this->insert(temp_node);
    }
}

template<typename T>
set<T>::set(set<T> &&list) noexcept {
    this->length = list.length;
    this->head = list.head;
    this->tail = list.tail;
}

template<typename T>
set<T>::set(std::initializer_list<T> elems) {
    set();

    for (auto &el : elems) {

        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw std::bad_alloc();
        }

        temp_node->set(el);
        this->insert(temp_node);
    }
}

// Modifiers
template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(const T &data) {
    std::shared_ptr<set_node<T>> temp_node = nullptr;

    try {
        temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
    } catch (std::bad_alloc &error) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw std::bad_alloc();
    }

    temp_node->set(data);

    set_iterator<T> iterator;
    for (iterator = this->begin(); temp_node < iterator->get(); iterator++);

    if (iterator.get() == temp_node)
        return std::pair<set_iterator<T>, bool>({}, false);

    temp_node->set_next(iterator->get_next());
    iterator->value()->set_next(temp_node);
    this->size++;

    return std::pair<set_iterator<T>, bool>({temp_node}, true);
}

template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(T &&value) {
    return std::pair<set_iterator<T>, bool>();
}

template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(const std::shared_ptr<set_node<T>> &node) {
    return std::pair<set_iterator<T>, bool>();
}

template<typename T>
void set<T>::insert(std::initializer_list<T> ilist) {
}

template<typename T>
void set<T>::clear() {
}

// Capacity
template<typename T>
size_t set<T>::size() {
    return length;
}

template<typename T>
bool set<T>::empty() const {
    return 0 != length;
}

// Lookup
template<typename T>
size_t set<T>::count(const T &key) const {
    return length;
}

template<typename T>
set_iterator<T> set<T>::find(const T &key) {
    return set_iterator<T>();
}

// Non-member
template<typename T>
bool set<T>::operator==(const set<T> &list) const {
    return false;
}

template<typename T>
bool set<T>::operator!=(const set<T> &list) const {
    return false;
}

// Iterators
template<typename T>
set_iterator<T> set<T>::begin() {
    return set_iterator<T>();
}

template<typename T>
set_iterator<T> set<T>::end() {
    return set_iterator<T>();
}

template<typename T>
set<T> &set<T>::operator+=(const set<T> &set) {
    return this;
}

template<typename T>
set<T> &set<T>::operator+=(const T &data) {
    return this;
}

template<typename T>
set<T> &set<T>::operator+(const set<T> &set) {
    return this;
}

template<typename T>
set<T> &set<T>::operator+(const T &data) {
    return this;
}

#endif//LAB_02_SET_HPP
