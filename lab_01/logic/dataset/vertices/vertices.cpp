//
// Created by gregory on 27.02.2021.
//

#include <vertices.h>

static err_t read_amount(vertices_t &points, FILE *f) {
    if ((fscanf(f, "%zd", &points.size)) != 1)
        return READ_ERR;

    if (points.size < 2)
        return PSIZE_ERR;

    return OK;
}

static err_t read_vertices(vertice_t *const arr, const int size, FILE *f) {
    err_t error_code = OK;

    for (int i = 0; i < size; i++) {
        auto rc = fscanf(f, "%lf %lf %lf", &arr[i].x, &arr[i].y, &arr[i].z);

        if (3 != rc) {
            error_code = READ_ERR;
            i = size;
        }
    }

    return error_code;
}

static err_t allocate_verticies(vertices_t &points) {
    auto *temp_array = (vertice_t *) malloc(points.size * sizeof(vertice_t));

    if (nullptr == temp_array)
        return ALLOC_ERR;

    points.vec = temp_array;

    return OK;
}

err_t save_vertices(vertices_t &vertices, FILE *f) {
    if (0 > fprintf(f, "%zd\n", vertices.size))
        return WRITE_ERR;

    auto rc = 0;
    for (size_t i = 0; i < vertices.size; ++i) {
        rc = fprintf(
                f,
                "%lf %lf %lf\n",
                vertices.vec[i].x,
                vertices.vec[i].y,
                vertices.vec[i].z
        );

        if (0 > rc)
            i = vertices.size;
    }

    if (0 > rc)
        return WRITE_ERR;

    return OK;
}

err_t load_vertices(vertices_t &vertices, FILE *f) {
    err_t error_code = read_amount(vertices, f);

    if (error_code)
        return error_code;

    if ((error_code = allocate_verticies(vertices)))
        return error_code;

    if ((error_code = read_vertices(vertices.vec, vertices.size, f)))
        free_vertices(vertices);

    return error_code;
}

void free_vertices(const vertices_t &points) {
    if (nullptr != points.vec)
        free(points.vec);
}