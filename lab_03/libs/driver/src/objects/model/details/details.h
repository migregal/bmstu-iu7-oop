#pragma once

#include <vector>

#include <objects/model/details/edge/edge.h>
#include <objects/model/details/point/point.h>

class ModelDetails {
public:
    ModelDetails() = default;
    ModelDetails(std::vector<Point> &_points, std::vector<Edge> &_edges);
    ModelDetails(Point &center, std::vector<Point> &points, std::vector<Edge> &edges);
    ~ModelDetails() = default;

    void add_point(const Point &pt);
    void add_edge(const Edge &edge);
    [[nodiscard]] const Point &get_center() const;
    [[nodiscard]] const std::vector<Point> &get_points() const;
    [[nodiscard]] const std::vector<Edge> &get_edges() const;

    void reform(const Point &move, const Point &scale, const Point &rotate);

private:
    Point _center;

    std::vector<Point> _points;
    std::vector<Edge> _edges;
};