//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <memory>

#include <base_collection.hpp>
#include <set_iterator.hpp>
#include <set_node.hpp>

template<typename T>
class set : public base_collection {
    size_t length = 0;
    std::shared_ptr<set_node<T>> head;
    std::shared_ptr<set_node<T>> tail;

public:
    set() = default;
    set(set<T> &list);
    set(set<T> &&list) noexcept;
    set(std::initializer_list<T> elems);

    ~set() override = default;


    std::pair<set_iterator<T>, bool> insert(const T &data);
    std::pair<set_iterator<T>, bool> insert(T &&value);
    void insert(std::initializer_list<T> ilist);

    size_t size();

    bool empty() const override;

    void clear() override;
};


#endif//LAB_02_SET_HPP
