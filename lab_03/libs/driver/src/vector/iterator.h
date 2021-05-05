#pragma once

#include <iterator>
#include <memory>

namespace Collections {
    template<typename T>
    class Vector;

    template<typename T>
    class Iterator : public std::iterator<std::input_iterator_tag, T> {
    public:
        Iterator(const Iterator<T> &iter);
        Iterator(const Vector<T> &vector);

        T &operator*();
        const T &operator*() const;

        T *operator->();
        const T *operator->() const;

        explicit operator bool() const;

        Iterator<T> &operator+=(size_t number);
        Iterator<T> operator+(size_t number) const;

        Iterator<T> &operator++();
        const Iterator<T> operator++(int);

        bool operator==(const Iterator<T> &iterator) const;
        bool operator!=(const Iterator<T> &iterator) const;

    private:
        std::weak_ptr<T[]> ptr;
        T *get_current() const;
        size_t current_index;
        size_t vector_size;
    };
}// namespace Collections

#include <vector/iterator.hpp>
