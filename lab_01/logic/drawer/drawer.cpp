//
// Created by gregory on 28.02.2021.
//

#include <drawer.h>

struct drawer_utils {
    const vertice_t &center;
    const drawer_t &drawer;
};

static void draw_edge(const edge_t &edge,
                      const vertice_t *const vertices,
                      const drawer_utils &utils) {
    vertice_t pt1 = vertices[edge.point_1];
    vertice_t pt2 = vertices[edge.point_2];

    draw_line(
            utils.drawer.canvas,
            {pt1.x + utils.center.x, pt1.y + utils.center.y},
            {pt2.x + utils.center.x, pt2.y + utils.center.y}
    );
}

void display(const displayable_data &data,
             const vertice_t &center,
             const drawer_t &drawer) {
    for (int i = 0; i < data.edges.size; i++)
        draw_edge(data.edges.vec[i], data.vertices.vec, {center, drawer});
}