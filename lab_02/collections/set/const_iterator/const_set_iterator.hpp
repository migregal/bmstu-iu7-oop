//
// Created by gregory on 12.04.2021.
//

#ifndef LAB_02_CONST_SET_ITERATOR_HPP
#define LAB_02_CONST_SET_ITERATOR_HPP

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
void const_set_iterator<T>::next() {
    this->cur = this->cur.lock()->get_next();
}

template<typename T>
void const_set_iterator<T>::prev() {
    this->cur = this->cur.lock()->get_prev();
}

template<typename T>
const T *const_set_iterator<T>::operator->() const {
    return this->cur.lock().get();
}

template<typename T>
const T &const_set_iterator<T>::operator*() const {
    return this->cur.lock()->value();
}

template<typename T>
const_set_iterator<T>::operator bool() const {
    return nullptr == this->cur.lock();
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
const_set_iterator<T> &const_set_iterator<T>::operator--() {
    this->prev();
    return *this;
}

template<typename T>
bool const_set_iterator<T>::operator!=(const const_set_iterator<T> &iterator) const {
    return this->cur.lock() != iterator.cur.lock();
}

template<typename T>
bool const_set_iterator<T>::operator==(const const_set_iterator<T> &iterator) const {
    return this->cur.lock() == iterator.cur.lock();
}

#endif//LAB_02_CONST_SET_ITERATOR_HPP
