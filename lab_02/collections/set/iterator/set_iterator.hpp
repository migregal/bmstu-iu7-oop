//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_ITERATOR_HPP
#define LAB_02_SET_ITERATOR_HPP

template<typename T>
set_node<T> &set_iterator<T>::operator*() {
    return *this->cur.lock();
}

template<typename T>
set_iterator<T> &set_iterator<T>::operator++() {
    return *this;
}

template<typename T>
bool set_iterator<T>::operator!=(const set_iterator<T> &iterator) const {
    return false;
}

template<typename T>
bool set_iterator<T>::operator==(const set_iterator<T> &iterator) const {
    return false;
}

#endif//LAB_02_SET_ITERATOR_HPP
