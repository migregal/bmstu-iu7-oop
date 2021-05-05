#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator.h"

using namespace Collections;

template<typename T>
Iterator<T>::Iterator(const Iterator<T> &iter)
    : ptr(iter.ptr),
      current_index(iter.current_index),
      vector_size(iter.vector_size) {
}

template<typename T>
Iterator<T>::Iterator(const Vector<T> &vector) {
    this->current_index = 0;
    this->vector_size = vector.get_size();
    this->ptr = vector.value;
}

template<typename T>
T &Iterator<T>::operator*() {
    return *get_current();
}

template<typename T>
const T &Iterator<T>::operator*() const {
    return get_current();
}

template<typename T>
T *Iterator<T>::operator->() {
    return get_current();
}

template<typename T>
const T *Iterator<T>::operator->() const {
    return get_current();
}

template<typename T>
Iterator<T>::operator bool() const {
    return !(current_index >= vector_size || !vector_size);
}

template<typename T>
Iterator<T> &Iterator<T>::operator+=(size_t number) {
    current_index += number;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(size_t number) const {
    Iterator<T> iterator(*this);
    iterator += number;
    return iterator;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    this->current_index++;

    return *this;
}

template<typename T>
const Iterator<T> Iterator<T>::operator++(int) {
    ++(*this);

    return *this;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &iterator) const {
    return this->current_index == iterator.current_index;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &iterator) const {
    return this->current_index != iterator.current_index;
}

template<typename T>
T *Iterator<T>::get_current() const {
    return this->ptr.lock().get() + current_index;
}

#endif
