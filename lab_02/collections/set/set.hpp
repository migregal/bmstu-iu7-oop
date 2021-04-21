//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <chrono>

#include "set.h"
#include <errors.h>


namespace collections {
    template<typename T>
    set<T>::set(const set<T> &list) : set() {

        for (auto iter = list.begin(); list.end() != iter; ++iter) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(list).name(), __FUNCTION__);
            }

            temp_node->set(*iter);
            append(temp_node);
        }
    }

    template<typename T>
    set<T>::set(set<T> &&list) noexcept {
        size = list.size;
        head = list.head;
    }

    template<typename T>
    set<T>::set(std::initializer_list<T> elems) : set() {
        for (auto &el : elems) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
            }

            temp_node->set(el);
            append(temp_node);
        }
    }

    template<typename T>
    set<T>::~set() {
        this->clear();
    }

    // Modifiers
    template<typename T>
    bool set<T>::append(const T &value) {
        std::shared_ptr<set_node<T>> temp_node;

        try {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        temp_node->set(value);

        return append(temp_node);
    }

    template<typename T>
    bool set<T>::append(T &&value) {
        std::shared_ptr<set_node<T>> temp_node;

        try {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        temp_node->set(value);

        return append(temp_node);
    }

    template<typename T>
    bool set<T>::append(const std::shared_ptr<set_node<T>> &node) {
        std::shared_ptr<set_node<T>> temp;

        try {
            temp = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        temp->set(node->get());

        if (!size) {
            head = temp;
            tail = temp;
            size++;

            return true;
        }

        if (find(temp->get()))
            return false;

        temp->set_prev(tail);
        tail->set_next(temp);
        tail = temp;
        size++;

        return true;
    }

    template<typename T>
    void set<T>::append(std::initializer_list<T> ilist) {
        for (auto &el : ilist) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
            }

            temp_node->set(el);
            append(temp_node);
        }
    }

    template<typename T>
    set<T> set<T>::intersect(const set<T> &set) {
        return *this & set;
    }

    template<typename T>
    set<T> set<T>::intersect(const T &data) {
        return *this & data;
    }

    template<typename T>
    set<T> set<T>::combine(const set<T> &set) {
        return *this | set;
    }

    template<typename T>
    set<T> set<T>::combine(const T &data) {
        return *this | data;
    }

    template<typename T>
    set<T> set<T>::difference(const set<T> &set) {
        return *this - set;
    }

    template<typename T>
    set<T> set<T>::difference(const T &data) {
        return *this - data;
    }

    template<typename T>
    set<T> set<T>::symmetric_difference(const set<T> &data) {
        return *this ^ data;
    }

    template<typename T>
    set<T> set<T>::symmetric_difference(const T &data) {
        return *this ^ data;
    }

    template<typename T>
    void set<T>::erase(const T &value) {
        auto t = find(value);

        if (!t)
            return;

        erase(t);
    }

    template<typename T>
    void set<T>::erase(const_set_iterator<T> pos) {
        if (!size)
            return;

        if (!pos) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw iterator_error(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        auto t = std::make_shared<set_node<T>>(pos.get_cur());

        if (head->get() == t->get())
            head = t->get_next();

        auto r = t->get_next();
        t->exclude();

        --size;
    }

    template<typename T>
    void set<T>::clear() {
        while (head) {
            auto t = head;
            head = head->get_next();
            t->set_next(nullptr);

            t = tail;
            tail = tail->get_prev();
            t->set_prev(nullptr);
        }

        size = 0;
    }

    // Capacity
    template<typename T>
    size_t set<T>::get_size() {
        return size;
    }

    // Lookup
    template<typename T>
    const_set_iterator<T> set<T>::find(const T &val) const {
        for (auto el = begin(); el != end(); ++el)
            if (val == *el)
                return const_set_iterator<T>(el);

        return end();
    }

    // Non-member
    template<typename T>
    set<T> &set<T>::operator=(const set<T> &list) {
        if (&list == this)
            return *this;

        this->clear();

        size = 0;
        head = nullptr;
        tail = nullptr;

        for (auto iter = list.begin(); list.end() != iter; ++iter) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(list).name(), __FUNCTION__);
            }

            temp_node->set(*iter);
            append(temp_node);
        }

        return *this;
    }

    template<typename T>
    collections::set<T> &collections::set<T>::operator=(collections::set<T> &&list) noexcept {
        size = list.size;
        head = list.head;
        tail = list.tail;

        return *this;
    }

    template<typename T>
    bool set<T>::operator==(const set<T> &list) const {
        if (size != list.size)
            return false;

        for (auto i : list)
            if (!find(i))
                return false;

        return true;
    }

    template<typename T>
    bool set<T>::operator!=(const set<T> &list) const {
        return !(*this == list);
    }

    template<typename T>
    set<T> set<T>::operator+(const set<T> &ds) {
        set<T> s{*this};
        s += ds;
        return s;
    }

    template<typename T>
    set<T> set<T>::operator+(const T &data) {
        set<T> s{*this};
        s += data;
        return s;
    }

    template<typename T>
    set<T> set<T>::operator&(const set<T> &data) {
        set<T> res;

        auto iter1 = this->begin(), iter2 = data.begin();
        while (iter1 and iter2) {
            if (*iter1 == *iter2) {
                res.append(*iter1);
                ++iter1;
                ++iter2;
            } else if (*iter1 < *iter2) {
                ++iter1;
            } else {
                ++iter2;
            }
        }

        return res;
    }

    template<typename T>
    set<T> set<T>::operator&(const T &data) {
        if (this->find(data))
            return set<T>{data};

        return set<T>();
    }

    template<typename T>
    set<T> set<T>::operator|(const set<T> &set) {
        return *this + set;
    }

    template<typename T>
    set<T> set<T>::operator|(const T &data) {
        return *this + data;
    }

    template<typename T>
    set<T> set<T>::operator-(const set<T> &data) {
        set<T> res;

        auto iter1 = this->begin(), iter2 = data.begin();
        while (iter1 and iter2) {
            if (*iter1 < *iter2) {
                res.append(*iter1);
                ++iter1;
                continue;
            }

            if (*iter2 < *iter1) {
                ++iter2;
                continue;
            }

            ++iter1;
            ++iter2;
        }

        while (iter1) {
            res.append(*iter1);
            ++iter1;
        }

        return res;
    }

    template<typename T>
    set<T> set<T>::operator-(const T &data) {
        set<T> res;
        res = *this;
        res.erase(data);

        return res;
    }

    template<typename T>
    set<T> set<T>::operator^(const set<T> &data) {
        set<T> res;

        auto iter1 = this->begin(), iter2 = data.begin();
        while (iter1 and iter2) {
            if (*iter1 < *iter2) {
                res.append(*iter1);
                ++iter1;
                continue;
            }

            if (*iter2 < *iter1) {
                res.append(*iter2);
                ++iter2;
                continue;
            }

            ++iter1;
            ++iter2;
        }

        while (iter1) {
            res.append(*iter1);
            ++iter1;
        }

        while (iter2) {
            res.append(*iter2);
            ++iter2;
        }

        return res;
    }

    template<typename T>
    set<T> set<T>::operator^(const T &data) {
        set<T> res;
        res = *this;
        res.erase(data);

        return res;
    }

    template<typename T>
    set<T> &set<T>::operator+=(const set<T> &list) {
        for (auto iter = list.begin(); list.end() != iter; ++iter)
            append(*iter);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator+=(const T &data) {
        append(data);
        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator&=(const set<T> &list) {
        set<T> res;

        for (auto i = this->begin(), j = list.begin(); i && j;) {
            if (*i == *j) {
                res.append(*i);
                ++i;
                ++j;
            } else if (*i < *j) {
                ++i;
            } else {
                ++j;
            }
        }

        this->clear();

        for (auto i = res.begin(); i && (res.end() != i); ++i)
            append(*i);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator&=(const T &data) {
        if (!find(data)) {
            clear();
        } else {
            clear();
            append(data);
        }

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator|=(const set<T> &set) {
        *this += set;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator|=(const T &data) {
        *this += data;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator-=(const set<T> &set) {
        for (auto i = set.begin(); set.end() != i; erase(*i), ++i)
            ;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator-=(const T &data) {
        erase(data);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator^=(const set<T> &list) {
        set<T> temp = *this ^ list;

        clear();
        for (auto i = temp.begin(); i != temp.end(); ++i)
            append(*i);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator^=(const T &data) {
        if (!find(data))
            append(data);
        else
            erase(data);

        return *this;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, set<T> &list) {
        for (auto el = list.begin(); el != list.end(); ++el)
            os << *el << " ";

        return os;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const set<T> &list) {
        for (auto el = list.begin(); el != list.end(); ++el)
            os << *el << " ";

        return os;
    }

    // Iterators
    template<typename T>
    const_set_iterator<T> set<T>::begin() const {
        return const_set_iterator<T>(head);
    }

    template<typename T>
    const_set_iterator<T> set<T>::end() const {
        return const_set_iterator<T>(tail ? tail->get_next() : nullptr);
    }
}// namespace collections

#endif//LAB_02_SET_HPP
