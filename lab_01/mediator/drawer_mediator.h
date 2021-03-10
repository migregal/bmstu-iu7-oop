//
// Created by gregory on 03.03.2021.
//

#ifndef LAB_01_DRAWER_MEDIATOR_H
#define LAB_01_DRAWER_MEDIATOR_H

#include <QGraphicsScene>
#include <vertices.h>

struct drawer_mediator_t {
    QGraphicsScene *scene;
};

void clear(const drawer_mediator_t &t);

void draw_line(const drawer_mediator_t &t, vertice_t p1, vertice_t p2);

#endif //LAB_01_DRAWER_MEDIATOR_H
