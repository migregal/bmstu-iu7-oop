#pragma once

#include <vector/iterator.h>

using namespace Collections;

template<typename T>
Vector<T>::Vector() {
    size = 0;
    allocate_new(100);
}

template<typename T>
Vector<T>::Vector(const T *array, size_t _size) {
    allocate_new(_size * 2);

    for (int i = 0; i < _size; i++)
        push_back(*(array + i));
}

template<typename T>
Vector<T>::Vector(T elem, size_t _size) {
    allocate_new(_size * 2);

    for (int i = 0; i < _size; i++) {
        push_back(elem);
    }
}

template<typename T>
size_t Vector<T>::get_size() const {
    return size;
}

template<typename T>
bool Vector<T>::is_empty() const {
    return 0 == size;
}

template<typename T>
T Vector<T>::at(size_t index) const {
    if (index >= size) {
        //todo
    }

    return value[index];
}

template<typename T>
Vector<T> &Vector<T>::push_back(const T &elem) {
    if (size >= memory_allocated) {
        allocate_new(size * 2);
    }

    value[size++] = elem;
}

template<typename T>
Vector<T> &Vector<T>::operator+=(const T &elem) {
    push_back(elem);
}

template<typename T>
void Vector<T>::remove(Iterator<T> _iterator) {
    //todo
}

template<typename T>
void Vector<T>::remove(size_t index) {
    //iterator<T> iterator(index);
    //remove(iterator);
}

template<typename T>
Iterator<T> Vector<T>::begin() {
    Iterator<T> iterator(*this);
    return iterator;
}

template<typename T>
Iterator<T> Vector<T>::end() {
    Iterator<T> iterator(*this);
    return iterator + size;
}

template<typename T>
const Iterator<T> Vector<T>::begin() const {
    const Iterator<T> iterator(*this);
    return iterator;
}

template<typename T>
const Iterator<T> Vector<T>::end() const {
    const Iterator<T> iterator(*this);
    return iterator + size;
}

template<typename T>
void Vector<T>::allocate_new(size_t new_size) {

    try {
        value.reset(new T[new_size]);
    } catch (std::bad_alloc &exception) {
        //todo
    }

    memory_allocated = new_size;
}
