//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_H
#define LAB_02_SET_H


#include <memory>

#include <base_collection.hpp>
#include <const_set_iterator.h>
#include <set_node.h>

namespace collections {
    template<typename T>
    class set : public base_collection {
    public:
        set() = default;
        set(const set<T> &list) noexcept(false);
        set(set<T> &&list) noexcept;
        set(std::initializer_list<T> elems);

        ~set() override;

        // Modifiers
        bool append(const T &value) noexcept(false);
        bool append(T &&value) noexcept(false);
        void append(std::initializer_list<T> ilist) noexcept(false);

        set<T> operator+(const set<T> &set);
        set<T> operator+(const T &data);
        set<T> &operator+=(const set<T> &set);
        set<T> &operator+=(const T &data);


        set<T> intersect(const set<T> &set);
        set<T> intersect(const T &data);

        set<T> operator&(const set<T> &set);
        set<T> operator&(const T &data);
        set<T> &operator&=(const set<T> &set);
        set<T> &operator&=(const T &data);


        set<T> combine(const set<T> &set);
        set<T> combine(const T &data);

        set<T> operator|(const set<T> &set);
        set<T> operator|(const T &data);
        set<T> &operator|=(const set<T> &set);
        set<T> &operator|=(const T &data);


        set<T> difference(const set<T> &set);
        set<T> difference(const T &data);

        set<T> operator-(const set<T> &set);
        set<T> operator-(const T &data);
        set<T> &operator-=(const set<T> &set);
        set<T> &operator-=(const T &data);


        set<T> symmetric_difference(const set<T> &set);
        set<T> symmetric_difference(const T &data);

        set<T> operator^(const set<T> &set);
        set<T> operator^(const T &data);
        set<T> &operator^=(const set<T> &set);
        set<T> &operator^=(const T &data);


        size_t erase(const T &value);
        const_set_iterator<T> erase(const_set_iterator<T> pos);

        void clear() override;

        // Capacity
        size_t get_size();

        //Lookup
        const_set_iterator<T> find(const T &val) const;

        // Non-member
        set<T> &operator=(const set<T> &list);
        set<T> &operator=(set<T> &&list) noexcept;

        bool operator==(const set<T> &list) const;
        bool operator!=(const set<T> &list) const;

        // Iterators
        const_set_iterator<T> begin() const;
        const_set_iterator<T> end() const;

    protected:
        bool append(const std::shared_ptr<set_node<T>> &node) noexcept(false);

    private:
        std::shared_ptr<set_node<T>> head;
        std::shared_ptr<set_node<T>> tail;
    };
}// namespace collections

#include <set.hpp>

#endif//LAB_02_SET_H
