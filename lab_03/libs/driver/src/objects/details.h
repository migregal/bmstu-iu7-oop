#pragma once

#include <vector/vector.h>

#include <objects/edge.h>
#include <objects/point.h>

class ModelDetails {
public:
    ModelDetails() = default;
    ModelDetails(Vector<Point> &_points, Vector<Edge> &_edges) : points(_points), edges(_edges){};
    ~ModelDetails() = default;

    void add_point(const Point &pt);
    void add_edge(const Edge &edge);
    [[nodiscard]] const Vector<Point> &get_points() const;
    [[nodiscard]] const Vector<Edge> &get_edges() const;

    void reform(const Point &move, const Point &scale, const Point &rotate);

private:
    Vector<Point> points;
    Vector<Edge> edges;
};