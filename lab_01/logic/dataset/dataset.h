//
// Created by gregory on 27.02.2021.
//

#ifndef LAB_01_DATASET_H
#define LAB_01_DATASET_H

#include <errors.h>
#include <drawer.h>
#include <vertices.h>
#include <edges.h>
#include <transformation.h>

using fname_t = const char *;

struct dataset_t
{
    vertice_t center;
    vertices_t vertices;
    edges_t edges;
};


dataset_t &init();

inline bool is_empty(const dataset_t &dataset);

err_t save_dataset(dataset_t &dataset, fname_t name);

err_t load_dataset(dataset_t &dataset, fname_t name);

err_t draw_dataset(const dataset_t &dataset,  const drawer_t &drawer);

err_t translate_dataset(dataset_t &dataset, const translation_t &coeffs);

err_t move_dataset(dataset_t &dataset, const movement_t &coeffs);

err_t resize_dataset(dataset_t &dataset, const resize_t &coeffs);

err_t rotate_dataset(dataset_t &dataset, const rotation_t &coeffs);

void free_dataset(const dataset_t &dataset);

#endif //LAB_01_DATASET_H
