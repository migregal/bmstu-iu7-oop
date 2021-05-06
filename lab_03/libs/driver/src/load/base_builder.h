#pragma once

#include <objects/model.h>

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    [[nodiscard]] virtual bool is_build() const = 0;
    virtual void build() = 0;
    virtual void build_point(const double &x, const double &y, const double &z) = 0;
    virtual void build_edge(const size_t &pt1, const size_t &pt2) = 0;

    virtual std::shared_ptr<Model> get() = 0;
};
