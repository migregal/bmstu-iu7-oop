#include <objects/model/details/point/point.h>

#include <cmath>

inline double to_radians(const double &angle) {
    return angle * (M_PI / 180);
}

Point::Point(const double x, const double y, const double z) : _x(x), _y(y), _z(z) {
}

Point::Point(const Point &&p) noexcept : _x(p._x), _y(p._y), _z(p._z) {
    p.~Point();
}

Point &Point::operator=(Point &&p) noexcept {
    set_x(p._x);
    set_y(p._y);
    set_z(p._z);
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
    set_x(_x + dx);
    set_y(_y + dy);
    set_z(_z + dz);
}

void Point::scale(const double kx, const double ky, const double kz) {
    set_x(_x * kx);
    set_y(_y * ky);
    set_z(_z * kz);
}

void Point::rotate(const double ox, const double oy, const double oz) {
    rotate_x(ox);
    rotate_y(oy);
    rotate_z(oz);
}

void Point::rotate_x(const double &ox) {
    const double r_cos = cos(to_radians(ox));
    const double r_sin = sin(to_radians(ox));
    const double temp_y = _y;

    set_y(_y * r_cos + _z * r_sin);
    set_z(-temp_y * r_sin + _z * r_cos);
}

void Point::rotate_y(const double &oy) {
    const double r_cos = cos(to_radians(oy));
    const double r_sin = sin(to_radians(oy));
    const double temp_x = _x;

    set_x(_x * r_cos + _z * r_sin);
    set_z(-temp_x * r_sin + _z * r_cos);
}

void Point::rotate_z(const double &oz) {
    const double r_cos = cos(to_radians(oz));
    const double r_sin = sin(to_radians(oz));
    const double temp_x = _x;

    set_x(_x * r_cos + _y * r_sin);
    set_y(-temp_x * r_sin + _y * r_cos);
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
