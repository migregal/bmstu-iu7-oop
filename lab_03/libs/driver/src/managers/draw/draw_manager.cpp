#include <managers/draw/draw_manager.h>

#include <utility>

void DrawManager::set_drawer(std::shared_ptr<AbstractDrawer> drawer) {
    _drawer = std::move(drawer);
}

void DrawManager::set_cam(std::shared_ptr<Camera> new_cam) {
    cam = std::move(new_cam);
}

void DrawManager::visit(const Model &_model) {
    auto points = _model.get_details()->get_points();

    auto center = _model.get_details()->get_center();
    for (auto edge : _model.get_details()->get_edges())
        _drawer->draw_line(
                proect_point(points.at(edge.get_fst()).relative_to(center)),
                proect_point(points.at(edge.get_snd())).relative_to(center));
}

Point DrawManager::proect_point(const Point &_point) {
    Point new_point(_point);
    Point cam_pos(cam->get_pos());
    new_point.set_x(new_point.get_x() + cam_pos.get_x());
    new_point.set_y(new_point.get_y() + cam_pos.get_y());

    return new_point;
}

void DrawManager::visit(const Camera &camera){};
void DrawManager::visit(const Composite &composite){}
