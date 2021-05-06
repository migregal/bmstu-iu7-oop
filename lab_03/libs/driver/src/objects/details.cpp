#include <objects/details.h>

void ModelDetails::add_point(const Point &pt) {
    points.push_back(pt);
}

void ModelDetails::add_edge(const Edge &link) {
    edges.push_back(link);
}

const Vector<Point> &ModelDetails::get_points() const {
    return points;
}

const Vector<Edge> &ModelDetails::get_edges() const {
    return edges;
}

void ModelDetails::reform(const Point &_move, const Point &_scale, const Point &_turn) {
    for (auto &pt : points) {
        pt.move(_move.get_x(), _move.get_y(), _move.get_z());
        pt.scale(_scale.get_x(), _scale.get_y(), _scale.get_z());
        pt.rotate(_turn.get_x(), _turn.get_y(), _turn.get_z());
    }
}