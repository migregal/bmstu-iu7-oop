//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <chrono>
#include "set.h"


template<typename T>
set<T>::set(set<T> &list) {
    set();

    for (auto el : list) {
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

template<typename T>
set<T>::set(set<T> &&list) noexcept {
    this->size = list.size;
    this->head = list.head;
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
std::pair<set_iterator<T>, bool> set<T>::insert(const T &value) {
    std::shared_ptr<set_node<T>> temp_node;

    try {
        temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
    } catch (std::bad_alloc &error) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw std::bad_alloc();
    }

    temp_node->set(value);

    return this->insert(temp_node);
}

template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(T &&value) {
    std::shared_ptr<set_node<T>> temp_node;

    try {
        temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
    } catch (std::bad_alloc &error) {
        auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw std::bad_alloc();
    }

    temp_node->set(value);

    return this->insert(temp_node);
}

template<typename T>
std::pair<set_iterator<T>, bool> set<T>::insert(const std::shared_ptr<set_node<T>> &node) {
    std::shared_ptr<set_node<T>> temp;

    try {
        temp = std::shared_ptr<set_node<T>>(new set_node<T>);
    } catch (std::bad_alloc &error) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw std::bad_alloc();
    }

    temp->set(node->get());

    if (!this->size) {
        temp.get()->set_next(nullptr);
        this->head = temp;
        this->size++;

        return {set_iterator<T>(temp), true};
    }

    set_iterator<T> iter = this->begin();

    if (*iter > temp.get()->get()) {
        temp.get()->set_next(iter.get_cur());
        this->head = temp;
        this->size++;

        return {set_iterator<T>(temp), true};
    }

    set_iterator<T> prev = iter;
    while (iter != this->end() && *iter < temp.get()->get()) {
        prev = iter;
        ++iter;
    }

    if (iter != this->end() && *iter == temp.get()->get())
        return {{}, false};

    temp.get()->set_next(prev.get_cur().get_next());
    prev.get_cur().set_next(temp);
    this->size++;

    return {set_iterator<T>(temp), true};
}

template<typename T>
void set<T>::insert(std::initializer_list<T> ilist) {
    for (auto &el : ilist) {
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

template<typename T>
void set<T>::clear() {
    while (this->size > 0 && this->size--)
        this->head = this->head->get_next();
}

// Capacity
template<typename T>
size_t set<T>::get_size() {
    return size;
}

template<typename T>
bool set<T>::empty() const {
    return 0 == size;
}

// Lookup
template<typename T>
size_t set<T>::count(const T &key) const {
    return size;
}

template<typename T>
set_iterator<T> set<T>::find(const T &val) {
    for (auto el = begin(); el != end(); ++el)
        if (val == *el)
            return set_iterator<T>(el);

    return this->end();
}

template<typename T>
const_set_iterator<T> set<T>::find(const T &val) const {
    for (auto el = cbegin(); el != cend(); ++el)
        if (val == *el)
            return const_set_iterator<T>(el);

    return this->cend();
}

// Non-member
template<typename T>
bool set<T>::operator==(const set<T> &list) const {
    if (this->size != list.size)
        return false;

    auto fst = this->cbegin();
    auto snd = list.cbegin();

    for (; fst != this->cend() && snd != list.cend(); ++fst, ++snd)
        if (*fst != *snd)
            return false;

    return true;
}

template<typename T>
bool set<T>::operator!=(const set<T> &list) const {
    return !(*this == list);
}

template<typename T>
set<T> &set<T>::operator+=(set<T> &set) {
    for (auto &el : set)
        this->insert(el);

    return *this;
}

template<typename T>
set<T> &set<T>::operator+=(const T &data) {
    this->insert(data);
    return *this;
}

template<typename T>
set<T> &set<T>::operator+=(T &&data) {
    this->insert(data);
    return *this;
}

template<typename T>
set<T> &set<T>::operator+(set<T> &ds) {
    auto s = new set<T>();
    *s += *this;
    *s += ds;
    return *s;
}

template<typename T>
set<T> &set<T>::operator+(T &data) {
    auto s = this;
    s += data;
    return s;
}

template<typename T>
set<T> &set<T>::operator+(const T &data) {
    auto s = this;
    *s += data;
    return *s;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, set<T> &list) {
    for (const auto &el : list)
        os << el << " ";

    return os;
}

// Iterators
template<typename T>
set_iterator<T> set<T>::begin() {
    return set_iterator<T>(this->head);
}

template<typename T>
set_iterator<T> set<T>::end() {
    return set_iterator<T>(nullptr);
}

template<typename T>
const_set_iterator<T> set<T>::cbegin() const {
    return const_set_iterator<T>(this->head);
}

template<typename T>
const_set_iterator<T> set<T>::cend() const {
    return const_set_iterator<T>(nullptr);
}

#endif//LAB_02_SET_HPP
