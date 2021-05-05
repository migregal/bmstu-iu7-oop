#pragma once

#include <memory>

#include <vector/iterator.h>
#include <objects/point.h>

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };
    virtual bool remove(const Iterator<std::shared_ptr<Object>> &) { return false; };

    virtual Iterator<std::shared_ptr<Object>> begin(){};
    virtual Iterator<std::shared_ptr<Object>> end(){};

    [[nodiscard]] virtual bool is_composite() const { return false; };
    virtual void accept(std::shared_ptr<visitor> visitor) = 0;
    virtual void reform(const point &move, const point &scale, const point &turn) = 0;
};

class VisibleObject : public object {
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    virtual bool is_visible() { return true; }
};

class InvisibleObject : public object {
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    virtual bool is_visible() { return false; }
};