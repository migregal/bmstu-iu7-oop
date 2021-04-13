//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_ITERATOR_HPP
#define LAB_02_SET_ITERATOR_HPP


template<typename T>
set_iterator<T>::set_iterator() {
    this->cur.lock() = nullptr;
}

template<typename T>
set_iterator<T>::set_iterator(const std::shared_ptr<set_node<T>> &node) {
    this->cur = node;
}

template<typename T>
set_iterator<T>::set_iterator(const set_iterator<T> &iterator) {
    this->cur = iterator.cur.lock();
}

template<typename T>
T *set_iterator<T>::operator->() {
    return &(this->cur.lock()->value());
}

template<typename T>
T &set_iterator<T>::operator*() {
    return this->cur.lock()->value();
}

template<typename T>
set_iterator<T> &set_iterator<T>::operator=(const set_iterator<T> &iterator) {
    this->cur = iterator.cur.lock();
    return *this;
}

template<typename T>
set_iterator<T> &set_iterator<T>::operator++() {
    this->next();
    return *this;
}

template<typename T>
set_iterator<T> &set_iterator<T>::operator--() {
    this->prev();
    return *this;
}

template<typename T>
bool set_iterator<T>::operator!=(const set_iterator<T> &iterator) const {
    return this->cur.lock() != iterator.cur.lock();
}

template<typename T>
bool set_iterator<T>::operator==(const set_iterator<T> &iterator) const {
    return this->cur.lock() == iterator.cur.lock();
}

#endif//LAB_02_SET_ITERATOR_HPP
