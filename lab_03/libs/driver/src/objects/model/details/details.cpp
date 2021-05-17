#include <objects/model/details/details.h>

void ModelDetails::add_point(const Point &pt) {
    _points.push_back(pt);
}

void ModelDetails::add_edge(const Edge &link) {
    _edges.push_back(link);
}

const Point &ModelDetails::get_center() const {
    return _center;
}

const std::vector<Point> &ModelDetails::get_points() const {
    return _points;
}

const std::vector<Edge> &ModelDetails::get_edges() const {
    return _edges;
}

void ModelDetails::reform(const Point &move, const Point &scale, const Point &rotate) {
    _center.move(move.get_x(), move.get_y(), move.get_z());

    for (auto &pt : _points) {
        pt.scale(scale.get_x(), scale.get_y(), scale.get_z());
        pt.rotate(rotate.get_x(), rotate.get_y(), rotate.get_z());
    }
}

ModelDetails::ModelDetails(std::vector<Point> &points, std::vector<Edge> &edges) : _center{}, _points(points), _edges(edges) {}

ModelDetails::ModelDetails(Point &center, std::vector<Point> &points, std::vector<Edge> &edges) : _center(center), _points(points), _edges(edges) {}