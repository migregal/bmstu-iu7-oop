#pragma once

class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object>&) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<Object>>&) { return false; };

    virtual iterator<std::shared_ptr<Object>> begin() {};
    virtual iterator<std::shared_ptr<Object>> end()   {};

//    virtual bool is_composite() const { return false; };
//    virtual void accept(std::shared_ptr<visitor> visitor) = 0;
//    virtual void reform(const point &move, const point &scale, const point &turn) = 0;
};
