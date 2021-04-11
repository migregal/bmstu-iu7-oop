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
void set_iterator<T>::next() {
    this->cur = this->cur.lock()->get_next();
}

template<typename T>
set_node<T> &set_iterator<T>::get_cur() {
    return *this->cur.lock();
}

template<typename T>
T *set_iterator<T>::operator->() {
    return this->cur.lock().get();
}

template<typename T>
T &set_iterator<T>::operator*() {
    return this->cur.lock()->value();
}

template<typename T>
set_iterator<T> &set_iterator<T>::operator++() {
    this->next();
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

template<typename T>
set_iterator<T>::operator bool() const {
    return nullptr == this->cur.lock();
}

#endif//LAB_02_SET_ITERATOR_HPP
