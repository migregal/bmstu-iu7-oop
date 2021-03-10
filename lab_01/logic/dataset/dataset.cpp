//
// Created by gregory on 27.02.2021.
//

#include <dataset.h>

dataset_t &init() {
    static dataset_t t{};
    return t;
}

inline bool is_empty(const dataset_t &dataset) {
    return !dataset.vertices.vec || !dataset.edges.vec;
}

err_t save_dataset(dataset_t &dataset, fname_t name) {
    if (is_empty(dataset))
        return MEMORY_ERR;

    FILE *fout;
    if (!(fout = fopen(name, "w")))
        return FILE_ERR;

    err_t error_code = save_vertices(dataset.vertices, fout);
    if (error_code) {
        fclose(fout);
        return error_code;
    }

    error_code = save_edges(dataset.edges, fout);

    fclose(fout);

    return error_code;
}

err_t preload_dataset(dataset_t &dataset, FILE *fin) {
    err_t error_code = load_vertices(dataset.vertices, fin);
    if (error_code)
        return error_code;

    if ((error_code = load_edges(dataset.edges, fin)))
        free_vertices(dataset.vertices);

    dataset.center = {0, 0};

    return error_code;
}

err_t load_dataset(dataset_t &dataset, fname_t name) {
    FILE *f;
    if (!(f = fopen(name, "r")))
        return FILE_ERR;

    dataset_t temp_dataset = init();

    err_t error_code = preload_dataset(temp_dataset, f);

    fclose(f);

    if (!error_code) {
        free_dataset(dataset);
        dataset = temp_dataset;
    }

    return error_code;
}

err_t draw_dataset(const dataset_t &dataset, const drawer_t &drawer) {
    if (is_empty(dataset))
        return MEMORY_ERR;

    clear(drawer.canvas);
    display({dataset.edges, dataset.vertices}, dataset.center, drawer);

    return OK;
}

err_t translate_dataset(dataset_t &dataset, const translation_t &coeffs) {
    if (is_empty(dataset))
        return MEMORY_ERR;

    dataset.center = {coeffs.x, coeffs.y, coeffs.z};

    return OK;
}

err_t move_dataset(dataset_t &dataset, const movement_t &coeffs) {
    if (is_empty(dataset))
        return MEMORY_ERR;

    move_vertice(dataset.center, coeffs);

    return OK;
}

err_t resize_dataset(dataset_t &dataset, const resize_t &coeffs) {
    if (is_empty(dataset))
        return MEMORY_ERR;

    for (int i = 0; i < dataset.vertices.size; i++)
        resize_vertice(dataset.vertices.vec[i], coeffs);

    return OK;
}

err_t rotate_dataset(dataset_t &dataset, const rotation_t &coeffs) {
    if (is_empty(dataset))
        return MEMORY_ERR;

    for (int i = 0; i < dataset.vertices.size; i++) {
        rotate_vertice_x(dataset.vertices.vec[i], coeffs.ox);
        rotate_vertice_y(dataset.vertices.vec[i], coeffs.oy);
        rotate_vertice_z(dataset.vertices.vec[i], coeffs.oz);
    }

    return OK;
}

void free_dataset(const dataset_t &dataset) {
    free_vertices(dataset.vertices);
    free_edges(dataset.edges);
}
