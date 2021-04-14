//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_H
#define LAB_02_SET_H


#include <memory>

#include <base_collection.hpp>
#include <const_set_iterator.h>
#include <set_iterator.h>
#include <set_node.h>

namespace collections {
    template<typename T>
    class set : public base_collection {
        std::shared_ptr<set_node<T>> head;
        std::shared_ptr<set_node<T>> tail;

    protected:
        bool insert(const std::shared_ptr<set_node<T>> &node) noexcept(false);

    public:
        set() = default;
        set(const set<T> &list) noexcept(false);
        set(set<T> &&list) noexcept;
        set(std::initializer_list<T> elems);

        ~set() override;

        // Modifiers
        bool insert(const T &value) noexcept(false);
        bool insert(T &&value) noexcept(false);
        void insert(std::initializer_list<T> ilist) noexcept(false);

        size_t erase(const T &value);
        set_iterator<T> erase(const_set_iterator<T> pos);
        set_iterator<T> erase(const_set_iterator<T> first, const_set_iterator<T> last);

        void clear() override;

        // Capacity
        size_t get_size();

        bool empty() const override;

        //Lookup
        const_set_iterator<T> find(const T &val) const;

        // Non-member
        bool operator==(const set<T> &list) const;
        bool operator!=(const set<T> &list) const;

        set<T> &operator+=(set<T> &set);
        set<T> &operator+=(const T &data);
        set<T> &operator+=(T &&data);

        set<T> operator+(set<T> &set);
        set<T> operator+(T &data);
        set<T> operator+(const T &data);

        // Iterators
        const_set_iterator<T> cbegin() const;

        const_set_iterator<T> cend() const;
    };
}// namespace collections

#include <set.hpp>

#endif//LAB_02_SET_H
