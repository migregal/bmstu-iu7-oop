#pragma once

#include <memory>

#include <visitor.h>

#include <objects/point.h>

#include <vector>

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };
    virtual bool remove(const Iterator &) { return false; };

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };

    [[nodiscard]] virtual bool is_composite() const { return false; };
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    virtual void reform(const Point &move, const Point &scale, const Point &turn) = 0;
};

class VisibleObject : public Object {
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    virtual bool is_visible() { return true; }
};

class InvisibleObject : public Object {
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    virtual bool is_visible() { return false; }
};