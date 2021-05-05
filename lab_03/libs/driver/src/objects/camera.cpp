#include <objects/camera.h>

void Camera::move_x(const double &shift) {
    this->current_pos.set_x(this->current_pos.get_x() + shift);
}

void Camera::move_y(const double &shift) {
    this->current_pos.set_y(this->current_pos.get_y() + shift);
}

void Camera::move_z(const double &shift) {
    this->current_pos.set_z(this->current_pos.get_z() + shift);
}

void Camera::reform(const Point &new_pos, const Point &scale, const Point &turn) {
    this->move_x(new_pos.get_x());
    this->move_y(new_pos.get_y());
}

void Camera::accept(std::shared_ptr<Visitor> _visitor) {
    _visitor->visit(*this);
}