#pragma once

#include <objects/model/details/point/point.h>

class AbstractDrawer {
public:
    AbstractDrawer() = default;
    virtual ~AbstractDrawer() = default;
    virtual void draw_line(const Point &p1, const Point &p2) = 0;
    virtual void clear_scene() = 0;
};