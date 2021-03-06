//
// Created by gregory on 12.04.2021.
//

#ifndef LAB_02_CONST_SET_ITERATOR_H
#define LAB_02_CONST_SET_ITERATOR_H

#include <iterator>

#include <set.h>
#include <set_node.h>

namespace collections {
    template<typename T>
    class const_set_iterator : std::iterator<std::input_iterator_tag, T> {
    public:
        const_set_iterator();
        explicit const_set_iterator(const std::shared_ptr<set_node<T>> &node);
        const_set_iterator(const const_set_iterator<T> &iterator);

        ~const_set_iterator() = default;

        virtual void next();
        virtual void prev();

        const T *operator->() const;
        const T &operator*() const;

        explicit operator bool() const;

        const_set_iterator<T> &operator=(const const_set_iterator<T> &iterator);

        virtual const_set_iterator<T> &operator++();
        virtual const const_set_iterator<T> operator++(int);
        virtual const_set_iterator<T> &operator--();
        virtual const const_set_iterator<T> operator--(int);

        bool operator!=(const const_set_iterator<T> &iterator) const;
        bool operator==(const const_set_iterator<T> &iterator) const;

        template<typename U>
        friend class set;

    protected:
        virtual void set_cur(set_node<T> & node);
        virtual set_node<T> &get_cur();
        virtual set_node<T> &get_cur() const;

    private:
        std::weak_ptr<set_node<T>> cur;
    };
}// namespace collections

#include <const_set_iterator.hpp>

#endif//LAB_02_CONST_SET_ITERATOR_H
