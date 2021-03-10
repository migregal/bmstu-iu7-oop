//
// Created by gregory on 28.02.2021.
//

#ifndef LAB_01_DRAWER_H
#define LAB_01_DRAWER_H

#include <QGraphicsScene>

#include <drawer_mediator.h>
#include <edges.h>
#include <vertices.h>

struct drawer_t {
    drawer_mediator_t canvas;
};

struct displayable_data {
    const edges_t &edges;
    const vertices_t &vertices;
};

void display(
        const displayable_data &data,
        const vertice_t &center,
        const drawer_t &drawer);

#endif //LAB_01_DRAWER_H
