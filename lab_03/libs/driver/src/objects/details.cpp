#include <objects/details.h>

void ModelDetails::add_point(const Point &pt) {
    _points.push_back(pt);
}

void ModelDetails::add_edge(const Edge &link) {
    _edges.push_back(link);
}

const Point &ModelDetails::get_center() const {
    return _center;
}

const Vector<Point> &ModelDetails::get_points() const {
    return _points;
}

const Vector<Edge> &ModelDetails::get_edges() const {
    return _edges;
}

void ModelDetails::reform(const Point &move, const Point &scale, const Point &rotate) {
    if (move != Point(0, 0, 0)) {
        _center.move(move.get_x(), move.get_y(), move.get_z());
    }

    const auto def_scale = Point(1, 1, 1),
               def_rotate = Point(0, 0, 0);

    for (auto &pt : _points) {
        if (def_scale != scale)
            pt.scale(scale.get_x(), scale.get_y(), scale.get_z());

        if (def_rotate != rotate)
            pt.rotate(rotate.get_x(), rotate.get_y(), rotate.get_z());
    }
}

ModelDetails::ModelDetails(Vector<Point> &points, Vector<Edge> &edges) : _center{}, _points(points), _edges(edges) {}

ModelDetails::ModelDetails(Point &center, Vector<Point> &points, Vector<Edge> &edges) : _center(center), _points(points), _edges(edges) {}