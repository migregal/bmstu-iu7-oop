//
// Created by gregory on 27.02.2021.
//

#include <transformation.h>

inline double to_radians(const double &angle) {
    return angle * (M_PI / 180);
}

void move_vertice(vertice_t &vertice, const movement_t &coeffs) {
    vertice.x += coeffs.dx;
    vertice.y += coeffs.dy;
    vertice.z += coeffs.dz;
}

void resize_vertice(vertice_t &vertice, const resize_t &coeffs) {
    vertice.x *= coeffs.kx;
    vertice.y *= coeffs.ky;
    vertice.z *= coeffs.kz;
}

void rotate_vertice_x(vertice_t &vertice, const double &angle) {
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double temp_y = vertice.y;

    vertice.y = vertice.y * r_cos + vertice.z * r_sin;
    vertice.z = -temp_y * r_sin + vertice.z * r_cos;
}

void rotate_vertice_y(vertice_t &vertice, const double &angle) {
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double temp_x = vertice.x;

    vertice.x = vertice.x * r_cos + vertice.z * r_sin;
    vertice.z = -temp_x * r_sin + vertice.z * r_cos;
}

void rotate_vertice_z(vertice_t &vertice, const double &angle) {
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double temp_x = vertice.x;

    vertice.x = vertice.x * r_cos + vertice.y * r_sin;
    vertice.y = -temp_x * r_sin + vertice.y * r_cos;
}
