#pragma once

class Point {
public:
    Point() = default;
    Point(const double x, const double y, const double z);

    Point(const Point &point) = default;
    Point &operator=(const Point &point) = default;

    Point(const Point &&point) noexcept;
    Point &operator=(Point &&point) noexcept;

    ~Point() = default;

    [[nodiscard]] double get_x() const;
    [[nodiscard]] double get_y() const;
    [[nodiscard]] double get_z() const;

    void set_x(double const &x);
    void set_y(double const &y);
    void set_z(double const &z);

    void move(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void rotate(const double ox, const double oy, const double oz);

    void rotate_x(const double &ox);
    void rotate_y(const double &oy);
    void rotate_z(const double &oz);

private:
    double _x, _y, _z;
};