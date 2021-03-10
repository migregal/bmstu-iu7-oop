//
// Created by gregory on 27.02.2021.
//

#ifndef LAB_01_PRESENTER_H
#define LAB_01_PRESENTER_H

#include <errors.h>
#include <drawer.h>
#include <dataset.h>
#include <transformation.h>

enum data
{
    SAVE_DATASET,
    LOAD_DATASET,
    TRANSLATE_DATASET,
    RESIZE_DATASET,
    ROTATE_DATASET,
    MOVE_DATASET,
    DRAW_DATASET,
    STOP_EXECUTION
};

struct provider
{
    int code;
    union
    {
        fname_t file_name;
        translation_t translation;
        resize_t scale;
        rotation_t turn;
        movement_t move;
        drawer_t drawer;
    };
};

using provider_t = struct provider;

err_t provider_handler(const provider_t &provider);

#endif //LAB_01_PRESENTER_H
