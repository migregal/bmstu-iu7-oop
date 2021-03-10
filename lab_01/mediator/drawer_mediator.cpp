//
// Created by gregory on 04.03.2021.
//
#include <drawer_mediator.h>

void clear(const drawer_mediator_t &t) {
    t.scene->clear();
}

void draw_line(const drawer_mediator_t &t, vertice_t p1, vertice_t p2){
    t.scene->addLine(p1.x, p1.y, p2.x, p2.y);
}