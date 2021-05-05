#pragma once

class Camera;
class Model;
class Composite;

class Visitor
{
public:
    Visitor() = default;
    ~Visitor() = default;

    virtual void visit(const Camera &cam) = 0;
    virtual void visit(const Model &model) = 0;
    virtual void visit(const Composite &composite) = 0;
};