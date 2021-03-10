//
// Created by gregory on 27.02.2021.
//

#include <edges.h>

static err_t read_amount(edges_t &edges, FILE *f) {
    if (1 != (fscanf(f, "%zd", &edges.size)))
        return READ_ERR;

    if (1 > edges.size)
        return LSIZE_ERR;


    return OK;
}

static err_t read_edges(edge_t *const arr, const int &size, FILE *f) {
    err_t error_code = OK;

    for (int i = 0; i < size; i++) {
        auto rc = fscanf(f, "%zd %zd", &arr[i].point_1, &arr[i].point_2);

        if (2 != rc) {
            error_code = READ_ERR;
            i = size;
        }
    }

    return error_code;
}

static err_t allocate_edges(edges_t &edges) {
    auto *temp_array = (edge_t *) malloc(edges.size * sizeof(edge_t));

    if (!temp_array)
        return ALLOC_ERR;

    edges.vec = temp_array;

    return OK;
}

err_t save_edges(edges_t &edges, FILE *f) {
    if (0 > fprintf(f, "%zd\n", edges.size))
        return WRITE_ERR;


    for (size_t i = 0; i < edges.size; ++i) {
        auto rc = fprintf(
                f,
                "%zd %zd\n",
                edges.vec[i].point_1,
                edges.vec[i].point_2
        );

        if (0 > rc)
            return WRITE_ERR;
    }

    return OK;
}

err_t load_edges(edges_t &edges, FILE *f) {
    err_t error_code = read_amount(edges, f);

    if (error_code)
        return error_code;

    if ((error_code = allocate_edges(edges)))
        return error_code;


    if ((error_code = read_edges(edges.vec, edges.size, f)))
        free_edges(edges);

    return error_code;
}

void free_edges(const edges_t &edges) {
    if (edges.vec)
        free(edges.vec);
}
