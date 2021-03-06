//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_NODE_H
#define LAB_02_SET_NODE_H


#include <memory>

namespace collections {
    template<typename T>
    class set_node {
        T data;
        std::shared_ptr<set_node<T>> next;
        std::shared_ptr<set_node<T>> prev;

    public:
        set_node() = default;
        explicit set_node(const T &data);
        explicit set_node(std::shared_ptr<set_node<T>> &node);

        void set(const T &value);

        void insert_before(std::shared_ptr<set_node<T>> node);
        void exclude();

        void set_next(const set_node<T> &node);
        void set_next(const std::shared_ptr<set_node<T>> &node);

        void set_prev(const set_node<T> &node);
        void set_prev(const std::shared_ptr<set_node<T>> &node);

        void set_null();

        const T &get() const;
        T &value();

        std::shared_ptr<set_node<T>> get_next() const;
        std::shared_ptr<set_node<T>> get_prev() const;

        bool operator==(const std::shared_ptr<set_node<T>> &node) const;
        bool operator!=(const std::shared_ptr<set_node<T>> &node) const;
        bool operator<(const std::shared_ptr<set_node<T>> &node) const;

        ~set_node() = default;
    };
}// namespace collections
#include <set_node.hpp>

#endif//LAB_02_SET_NODE_H
