#pragma once

#include <memory>
#include <vector/iterator.h>

class BaseVector {
public:
    [[nodiscard]] virtual size_t get_size() const = 0;
    [[nodiscard]] virtual bool   is_empty() const = 0;
    virtual ~BaseVector() = default;

protected:
    std::size_t size{};
};

template <typename T>
class Vector : public BaseVector {
public:
    friend class iterator<T>;

    Vector();
    Vector(const T *array, size_t size);
    Vector(T elem, size_t size);

    ~Vector() override = default;

    [[nodiscard]] size_t get_size() const override;
    [[nodiscard]] bool   is_empty() const override;

    T at(size_t index) const;

    Vector<T> &push_back(const T &elem);
    Vector<T> &operator += (const T &elem);

    void remove(Iterator<T>);
    void remove(size_t index);

    iterator<T> begin();
    const iterator<T> begin() const;

    iterator<T> end();
    const iterator<T> end() const;

protected:
    void allocate_new(size_t size);

private:
    std::shared_ptr<T[]> value;
    size_t memory_allocated;

};

#include "vector.hpp"
