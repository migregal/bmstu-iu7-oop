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

        if (temp->get() == head->get())
            return false;

        if (temp->get() < head->get()) {
            head->set_prev(temp);
            temp->set_next(head);
            head = temp;
            size++;

            return true;
        }

        if (temp->get() == tail->get())
            return false;

        if (temp->get() > tail->get()) {
            temp->set_prev(tail);
            tail->set_next(temp);
            tail = temp;
            size++;

            return true;
        }

        const_set_iterator<T> iter = ++(cbegin());
        while (*iter < temp->get())
            ++iter;

        if (*iter == temp->get())
            return false;

        auto t = iter;

        --t;
        temp->set_prev(t.get_cur());
        temp->set_next(iter.get_cur());
        t.get_cur().set_next(*temp);
        iter.get_cur().set_prev(*temp);
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
    set<T> set<T>::intersect(set<T> &set) {
        return *this & set;
    }

    template<typename T>
    set<T> set<T>::intersect(T &data) {
        return *this & data;
    }

    template<typename T>
    set<T> set<T>::intersect(const T &data) {
        return *this & data;
    }

    template<typename T>
    set<T> set<T>::combine(set<T> &set) {
        return *this | set;
    }

    template<typename T>
    set<T> set<T>::combine(T &data) {
        return *this | data;
    }

    template<typename T>
    set<T> set<T>::combine(const T &data) {
        return *this | data;
    }

    template<typename T>
    set<T> set<T>::difference(set<T> &set) {
        return *this - set;
    }

    template<typename T>
    set<T> set<T>::difference(T &data) {
        return *this - data;
    }
    template<typename T>
    set<T> set<T>::difference(const T &data) {
        return *this - data;
    }

    template<typename T>
    set<T> set<T>::symmetric_difference(set<T> &data) {
        return *this ^ data;
    }

    template<typename T>
    set<T> set<T>::symmetric_difference(T &data) {
        return *this ^ data;
    }

    template<typename T>
    set<T> set<T>::symmetric_difference(const T &data) {
        return *this ^ data;
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
    const_set_iterator<T> set<T>::erase(const_set_iterator<T> pos) {
        if (!size)
            return cend();

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
        return const_set_iterator<T>(r);
    }

    template<typename T>
    const_set_iterator<T> set<T>::erase(const_set_iterator<T> first, const_set_iterator<T> last) {
        if (cend() == first || cend() == last) {
            auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw iterator_error(ctime(&t), __FILE__, typeid(set).name(), __FUNCTION__);
        }

        const_set_iterator<T> i;
        for (i = first; i && i != last; i = erase(i)) {}

        return i;
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
        for (auto el = cbegin(); el != cend(); ++el)
            if (val == *el)
                return const_set_iterator<T>(el);

        return cend();
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

        return *this;
    }

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
    set<T> set<T>::operator&(set<T> &data) {
        set<T> res;

        auto iter1 = this->cbegin(), iter2 = data.cbegin();
        while (iter1 and iter2) {
            if (*iter1 == *iter2) {
                res.insert(*iter1);
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
    set<T> set<T>::operator&(T &data) {
        if (this->find(data))
            return set<T>{data};

        return set<T>();
    }

    template<typename T>
    set<T> set<T>::operator&(const T &data) {
        if (this->find(data))
            return set<T>{data};

        return set<T>();
    }

    template<typename T>
    set<T> set<T>::operator|(set<T> &set) {
        return *this + set;
    }

    template<typename T>
    set<T> set<T>::operator|(T &data) {
        return *this + data;
    }

    template<typename T>
    set<T> set<T>::operator|(const T &data) {
        return *this + data;
    }

    template<typename T>
    set<T> set<T>::operator-(set<T> &data) {
        set<T> res;

        auto iter1 = this->cbegin(), iter2 = data.cbegin();
        while (iter1 and iter2) {
            if (*iter1 < *iter2) {
                res.insert(*iter1);
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
            res.insert(*iter1);
            ++iter1;
        }

        return res;
    }

    template<typename T>
    set<T> set<T>::operator-(T &data) {
        set<T> res;
        res = *this;
        res.erase(data);

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
    set<T> set<T>::operator^(set<T> &data) {
        set<T> res;

        auto iter1 = this->cbegin(), iter2 = data.cbegin();
        while (iter1 and iter2) {
            if (*iter1 < *iter2) {
                res.insert(*iter1);
                ++iter1;
                continue;
            }

            if (*iter2 < *iter1) {
                res.insert(*iter2);
                ++iter2;
                continue;
            }

            ++iter1;
            ++iter2;
        }

        while (iter1) {
            res.insert(*iter1);
            ++iter1;
        }

        while (iter2) {
            res.insert(*iter2);
            ++iter2;
        }

        return res;
    }

    template<typename T>
    set<T> set<T>::operator^(T &data) {
        set<T> res;
        res = *this;
        res.erase(data);

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
    set<T> &set<T>::operator&=(set<T> &list) {
        set<T> res;

        for (auto i = this->cbegin(), j = list.cbegin(); i && j;) {
            if (*i == *j) {
                res.insert(*i);
                ++i;
                ++j;
            } else if (*i < *j) {
                ++i;
            } else {
                ++j;
            }
        }

        this->clear();

        for (auto i = res.cbegin(); i && (res.cend() != i); ++i)
            insert(*i);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator&=(T &data) {
        if (!find(data)) {
            clear();
        } else {
            clear();
            insert(data);
        }

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator&=(const T &data) {
        if (!find(data)) {
            clear();
        } else {
            clear();
            insert(data);
        }

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator|=(set<T> &set) {
        *this += set;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator|=(T &data) {
        *this += data;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator|=(const T &data) {
        *this += data;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator-=(set<T> &set) {
        for (auto i = set.cbegin(); set.cend() != i; erase(*i), ++i)
            ;

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator-=(const T &data) {
        erase(data);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator-=(T &&data) {
        erase(data);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator^=(set<T> &list) {
        set<T> temp = *this ^ list;

        clear();
        for (auto i = temp.cbegin(); i != temp.cend(); ++i)
            insert(*i);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator^=(const T &data) {
        if (!find(data))
            insert(data);
        else
            erase(data);

        return *this;
    }

    template<typename T>
    set<T> &set<T>::operator^=(T &&data) {
        if (!find(data))
            insert(data);
        else
            erase(data);

        return *this;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, set<T> &list) {
        for (auto el = list.cbegin(); el != list.cend(); ++el)
            os << *el << " ";

        return os;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const set<T> &list) {
        for (auto el = list.cbegin(); el != list.cend(); ++el)
            os << *el << " ";

        return os;
    }

    // Iterators
    template<typename T>
    const_set_iterator<T> set<T>::cbegin() const {
        return const_set_iterator<T>(head);
    }

    template<typename T>
    const_set_iterator<T> set<T>::cend() const {
        return const_set_iterator<T>(tail ? tail->get_next() : nullptr);
    }
}// namespace collections

#endif//LAB_02_SET_HPP
