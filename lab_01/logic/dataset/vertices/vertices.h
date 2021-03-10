//
// Created by gregory on 27.02.2021.
//

#ifndef LAB_01_VERTICES_H
#define LAB_01_VERTICES_H

#include <cstdio>
#include <cstdlib>

#include <errors.h>

struct vertice_t
{
    double x, y, z;
};

struct vertices_t
{
    size_t size = 0;
    vertice_t *vec = nullptr;
};

err_t save_vertices(vertices_t &vertices, FILE *f);

err_t load_vertices(vertices_t &vertices, FILE *f);

void free_vertices(const vertices_t &vertices);

#endif //LAB_01_VERTICES_H
