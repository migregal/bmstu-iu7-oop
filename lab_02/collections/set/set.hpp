//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <chrono>

#include <errors.h>

namespace collections {
    template<typename T>
    set<T>::set(set<T> &list) : set() {

        for (auto el : list) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(list).name(), __FUNCTION__);
            }

            temp_node->set(el);
            insert(temp_node);
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
            insert(temp_node);
        }
    }

    template<typename T>
    set<T>::~set() {
        this->clear();
    }

    // Modifiers
    template<typename T>
    std::pair<set_iterator<T>, bool> set<T>::insert(const T &value) {
        std::shared_ptr<set_node<T>> temp_node;

        try {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        temp_node->set(value);

        return insert(temp_node);
    }

    template<typename T>
    std::pair<set_iterator<T>, bool> set<T>::insert(T &&value) {
        std::shared_ptr<set_node<T>> temp_node;

        try {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } catch (std::bad_alloc &error) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        temp_node->set(value);

        return insert(temp_node);
    }

    template<typename T>
    std::pair<set_iterator<T>, bool> set<T>::insert(const std::shared_ptr<set_node<T>> &node) {
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

            return {set_iterator<T>(temp), true};
        }

        if (temp.get()->get() == head.get()->get())
            return {set_iterator<T>(head), true};

        if (temp.get()->get() < head.get()->get()) {
            head.get()->set_prev(temp);
            temp.get()->set_next(head);
            head = temp;
            size++;

            return {set_iterator<T>(temp), true};
        }

        if (temp.get()->get() == tail.get()->get())
            return {set_iterator<T>(tail), true};

        if (temp.get()->get() > tail.get()->get()) {
            temp.get()->set_prev(tail);
            tail.get()->set_next(temp);
            tail = temp;
            size++;

            return {set_iterator<T>(temp), true};
        }

        set_iterator<T> iter = ++(begin());
        while (*iter < temp.get()->get())
            ++iter;

        if (*iter == temp.get()->get())
            return {iter, false};

        auto t = iter;

        --t;
        temp.get()->set_prev(t.get_cur());
        temp.get()->set_next(iter.get_cur());
        t.get_cur().set_next(*temp.get());
        iter.get_cur().set_prev(*temp.get());
        size++;

        return {set_iterator<T>(temp), false};
    }

    template<typename T>
    void set<T>::insert(std::initializer_list<T> ilist) {
        for (auto &el : ilist) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
            }

            temp_node->set(el);
            insert(temp_node);
        }
    }

    template<typename T>
    set_iterator<T> set<T>::erase(const_set_iterator<T> pos) {
        if (!size) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw size_error(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        if (cend() == pos) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw iterator_error(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        auto t = pos.cur.lock();

        t->get_prev()->set_next(t->get_next());
        t->get_next()->set_prev(t->get_prev());

        auto r = t->get_next();
        t->set_null();

        --size;
        return set_iterator<T>(r);
    }

    template<typename T>
    set_iterator<T> set<T>::erase(const_set_iterator<T> first, const_set_iterator<T> last) {
        if (!size) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw size_error(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        if (cend() == first || cend() == last) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw iterator_error(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        const_set_iterator<T> i;
        for (i = first; i && i != last; i = erase(i)) {}

        return set_iterator<T>(i.cur.lock());
    }

    template<typename T>
    void set<T>::clear() {
        while (head) {
            auto t = head;
            head = head->get_next();
            t.get()->set_next(nullptr);
        }

        while (tail) {
            auto t = tail;
            tail = tail->get_prev();
            t.get()->set_prev(nullptr);
        }

        size = 0;
    }

    // Capacity
    template<typename T>
    size_t set<T>::get_size() {
        return size;
    }

    template<typename T>
    bool set<T>::empty() const {
        return 0 == size;
    }

    // Lookup
    template<typename T>
    size_t set<T>::count(const T &key) const {
        return size;
    }

    template<typename T>
    set_iterator<T> set<T>::find(const T &val) {
        for (auto el = begin(); el != end(); ++el)
            if (val == *el)
                return set_iterator<T>(el);

        return end();
    }

    template<typename T>
    const_set_iterator<T> set<T>::find(const T &val) const {
        for (auto el = cbegin(); el != cend(); ++el)
            if (val == *el)
                return const_set_iterator<T>(el);

        return cend();
    }

    // Non-member
    template<typename T>
    bool set<T>::operator==(const set<T> &list) const {
        if (size != list.size)
            return false;

        auto fst = cbegin();
        auto snd = list.cbegin();

        for (; fst != cend() && snd != list.cend(); ++fst, ++snd)
            if (*fst != *snd)
                return false;

        return true;
    }

    template<typename T>
    bool set<T>::operator!=(const set<T> &list) const {
        return !(*this == list);
    }

    template<typename T>
    set<T> &set<T>::operator+=(set<T> &set) {
        for (auto &el : set)
            insert(el);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator+=(const T &data) {
        insert(data);
        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator+=(T &&data) {
        insert(data);
        return *this;
    }

    template<typename T>
    set<T> set<T>::operator+(set<T> &ds) {
        set<T> s{*this};
        s += ds;
        return s;
    }

    template<typename T>
    set<T> set<T>::operator+(T &data) {
        set<T> s{*this};
        s += data;
        return s;
    }

    template<typename T>
    set<T> set<T>::operator+(const T &data) {
        set<T> s{*this};
        s += data;
        return s;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, set<T> &list) {
        for (const auto &el : list)
            os << el << " ";

        return os;
    }

    // Iterators
    template<typename T>
    set_iterator<T> set<T>::begin() {
        return set_iterator<T>(head);
    }

    template<typename T>
    set_iterator<T> set<T>::end() {
        return set_iterator<T>(tail ? tail.get()->get_next() : nullptr);
    }

    template<typename T>
    const_set_iterator<T> set<T>::cbegin() const {
        return const_set_iterator<T>(head);
    }

    template<typename T>
    const_set_iterator<T> set<T>::cend() const {
        return const_set_iterator<T>(tail ? tail.get()->get_next() : nullptr);
    }
}// namespace collections

#endif//LAB_02_SET_HPP
