#pragma once

#include <memory>

#include <visitor.h>

#include <objects/model/details/point/point.h>

#include <vector>

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

// Alternative
//
//template<typename T>
//using Vector = typename std::vector<T>;
//
//template<typename T>
//using Iterator = typename T::iterator;

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };
    virtual bool remove(const Iterator &) { return false; };

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    virtual bool is_visible() { return false; }
    [[nodiscard]] virtual bool is_composite() const { return false; };
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    virtual void reform(const Point &move, const Point &scale, const Point &turn) = 0;
};

class VisibleObject : public Object {
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool is_visible() override { return true; }
};

class InvisibleObject : public Object {
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool is_visible() override { return false; }
};