//
// Created by gregory on 27.02.2021.
//

#ifndef LAB_01_TRANSFORMATION_H
#define LAB_01_TRANSFORMATION_H

#include <cstdio>
#include <cmath>

#include <errors.h>
#include <vertices.h>

struct movement_t {
    double dx, dy, dz;
};

struct resize_t {
    double kx, ky, kz;
};

struct rotation_t {
    double ox, oy, oz;
};

struct translation_t {
    double x, y, z;
};

void move_vertice(vertice_t &vertice, const movement_t &coeffs);

void resize_vertice(vertice_t &vertice, const resize_t &coeffs);

void rotate_vertice_x(vertice_t &vertice, const double &angle);

void rotate_vertice_y(vertice_t &vertice, const double &angle);

void rotate_vertice_z(vertice_t &vertice, const double &angle);

#endif //LAB_01_TRANSFORMATION_H
