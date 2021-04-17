//
// Created by gregory on 12.04.2021.
//

#ifndef LAB_02_CONST_SET_ITERATOR_HPP
#define LAB_02_CONST_SET_ITERATOR_HPP

#include "const_set_iterator.h"

namespace collections {
    template<typename T>
    const_set_iterator<T>::const_set_iterator() {
        this->cur.lock() = nullptr;
    }

    template<typename T>
    const_set_iterator<T>::const_set_iterator(const std::shared_ptr<set_node<T>> &node) {
        this->cur = node;
    }

    template<typename T>
    const_set_iterator<T>::const_set_iterator(const const_set_iterator<T> &iterator) {
        this->cur = iterator.cur.lock();
    }

    template<typename T>
    void const_set_iterator<T>::set_cur(set_node<T> &node) {
        this->set_cur(node);
    }

    template<typename T>
    set_node<T> &const_set_iterator<T>::get_cur() {
        return *this->cur.lock();
    }

    template<typename T>
    set_node<T> &const_set_iterator<T>::get_cur() const {
        return *this->cur.lock();
    }

    template<typename T>
    void const_set_iterator<T>::next() {
        this->cur = get_cur().get_next();
    }

    template<typename T>
    void const_set_iterator<T>::prev() {
        this->cur = get_cur().get_prev();
    }

    template<typename T>
    const T *const_set_iterator<T>::operator->() const {
        return get_cur().get();
    }

    template<typename T>
    const T &const_set_iterator<T>::operator*() const {
        return get_cur().value();
    }

    template<typename T>
    const_set_iterator<T>::operator bool() const {
        return nullptr != this->cur.lock();
    }

    template<typename T>
    const_set_iterator<T> &const_set_iterator<T>::operator=(const const_set_iterator<T> &iterator) {
        this->cur = iterator.cur.lock();
        return *this;
    }

    template<typename T>
    const_set_iterator<T> &const_set_iterator<T>::operator++() {
        this->next();
        return *this;
    }

    template<typename T>
    const collections::const_set_iterator<T> collections::const_set_iterator<T>::operator++(int) {
        auto t = *this;
        this->next();

        return t;
    }

    template<typename T>
    const_set_iterator<T> &const_set_iterator<T>::operator--() {
        this->prev();
        return *this;
    }

    template<typename T>
    const const_set_iterator<T> collections::const_set_iterator<T>::operator--(int) {
        auto t = *this;
        this->prev();

        return t;
    }

    template<typename T>
    bool const_set_iterator<T>::operator!=(const const_set_iterator<T> &iterator) const {
        return this->cur.lock() != iterator.cur.lock();
    }

    template<typename T>
    bool const_set_iterator<T>::operator==(const const_set_iterator<T> &iterator) const {
        return this->cur.lock() == iterator.cur.lock();
    }
}// namespace collections

#endif//LAB_02_CONST_SET_ITERATOR_HPP
