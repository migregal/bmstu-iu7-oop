//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <memory>

#include <base_collection.hpp>
#include <set_node.hpp>

template<typename T>
class set : public base_collection {
    size_t size = 0;
    std::shared_ptr<set_node<T>> head;
    std::shared_ptr<set_node<T>> tail;

public:
    bool is_empty() const override;

    void clear() override;

    ~set() override = default;
};


#endif//LAB_02_SET_HPP
