//
// Created by gregory on 27.02.2021.
//

#ifndef LAB_01_EDGES_H
#define LAB_01_EDGES_H

#include <cstdlib>
#include <cstdio>

#include <errors.h>

struct edge_t
{
    size_t point_1;
    size_t point_2;
};

struct edges_t
{
    size_t size = 0;
    edge_t *vec = nullptr;
};

err_t save_edges(edges_t &edges, FILE *f);

err_t load_edges(edges_t &edges, FILE *f);

void free_edges(const edges_t &edges);

#endif //LAB_01_EDGES_H
