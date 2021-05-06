#include <objects/point.h>

#include <cmath>

Point::Point(const double x, const double y, const double z) : _x(x), _y(y), _z(z) {
}

Point::Point(const Point &&p) noexcept : _x(p._x), _y(p._y), _z(p._z) {
    p.~Point();
}

Point &Point::operator=(Point &&p) noexcept {
    _x = p._x;
    _y = p._y;
    _z = p._z;
    p.~Point();

    return *this;
}

double Point::get_x() const {
    return _x;
}

double Point::get_y() const {
    return _y;
}

double Point::get_z() const {
    return _z;
}

void Point::set_x(double const &x) {
    _x = x;
}

void Point::set_y(double const &y) {
    _y = y;
}

void Point::set_z(double const &z) {
    _z = z;
}

Point Point::operator+(const Point &p) {
    Point point{*this};

    point.set_x(point._x + p._x);
    point.set_y(point._y + p._y);
    point.set_z(point._z + p._z);

    return point;
}

Point Point::operator-(const Point &p) {
    Point point{*this};

    point.set_x(point._x - p._x);
    point.set_y(point._y - p._y);
    point.set_z(point._z - p._z);

    return point;
}

Point Point::relative_to(const Point &c) {
    return *this + c;
}

void Point::move(const double dx, const double dy, const double dz) {
    _x += dx;
    _y += dy;
    _z += dz;
}

void Point::scale(const double kx, const double ky, const double kz) {
    _x *= kx;
    _y *= ky;
    _z *= kz;
}

void Point::rotate(const double ox, const double oy, const double oz) {
    rotate_x(ox);
    rotate_y(oy);
    rotate_z(oz);
}

void Point::rotate_x(const double &ox) {
    const double temp_y = _y;
    _y = _y + cos(ox * M_PI / 180) + _z * sin(ox * M_PI / 180);
    _z = -temp_y * sin(ox * M_PI / 180) + _z * cos(ox * M_PI / 180);
}

void Point::rotate_y(const double &oy) {
    const double temp_x = _x;
    _x = _x * cos(oy * M_PI / 180) + _z * sin(oy * M_PI / 180);
    _z = -temp_x * sin(oy * M_PI / 180) + _z * cos(oy * M_PI / 180);
}

void Point::rotate_z(const double &oz) {
    const double temp_x = _x;
    _x = _x * cos(oz * M_PI / 180) + _y * sin(oz * M_PI / 180);
    _y = -temp_x * sin(oz * M_PI / 180) + _y * cos(oz * M_PI / 180);
}

bool Point::operator==(const Point &point) const noexcept {
    return (point._x == _x) && (point._y == _y) && (point._z == _z);
}

bool Point::equals(const Point &point) const noexcept {
    return *this == point;
}

bool Point::operator!=(const Point &point) const noexcept {
    return !(*this == point);
}
