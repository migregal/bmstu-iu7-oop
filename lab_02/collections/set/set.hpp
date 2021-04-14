//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_SET_HPP
#define LAB_02_SET_HPP


#include <chrono>

#include <errors.h>

namespace collections {
    template<typename T>
    set<T>::set(const set<T> &list) : set() {

        for (auto iter = list.cbegin(); list.cend() != iter; ++iter) {
            std::shared_ptr<set_node<T>> temp_node = nullptr;

            try {
                temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
            } catch (std::bad_alloc &error) {
                auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                throw bad_alloc_err(ctime(&t), __FILE__, typeid(list).name(), __FUNCTION__);
            }

            temp_node->set(*iter);
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
    bool set<T>::insert(const T &value) {
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
    bool set<T>::insert(T &&value) {
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
    bool set<T>::insert(const std::shared_ptr<set_node<T>> &node) {
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

        if (temp.get()->get() == head.get()->get())
            return false;

        if (temp.get()->get() < head.get()->get()) {
            head.get()->set_prev(temp);
            temp.get()->set_next(head);
            head = temp;
            size++;

            return true;
        }

        if (temp.get()->get() == tail.get()->get())
            return false;

        if (temp.get()->get() > tail.get()->get()) {
            temp.get()->set_prev(tail);
            tail.get()->set_next(temp);
            tail = temp;
            size++;

            return true;
        }

        const_set_iterator<T> iter = ++(cbegin());
        while (*iter < temp.get()->get())
            ++iter;

        if (*iter == temp.get()->get())
            return false;

        auto t = iter;

        --t;
        temp.get()->set_prev(t.get_cur());
        temp.get()->set_next(iter.get_cur());
        t.get_cur().set_next(*temp.get());
        iter.get_cur().set_prev(*temp.get());
        size++;

        return true;
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
    size_t set<T>::erase(const T &value) {
        auto t = find(value);

        if (!t)
            return 0;

        erase(t);
        return 1;
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

        auto t = std::make_shared<set_node<T>>(pos.get_cur());

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

        return set_iterator<T>(std::make_shared<set_node<T>>(i.get_cur()));
    }

    template<typename T>
    void set<T>::clear() {
        while (head) {
            auto t = head;
            head = head->get_next();
            t.get()->set_next(nullptr);

            t = tail;
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

    // Lookup
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
    set<T> &set<T>::operator+=(set<T> &list) {
        for (auto iter = list.cbegin(); list.cend() != iter; ++iter)
            insert(*iter);

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
    const_set_iterator<T> set<T>::cbegin() const {
        return const_set_iterator<T>(head);
    }

    template<typename T>
    const_set_iterator<T> set<T>::cend() const {
        return const_set_iterator<T>(tail ? tail.get()->get_next() : nullptr);
    }
}// namespace collections

#endif//LAB_02_SET_HPP
