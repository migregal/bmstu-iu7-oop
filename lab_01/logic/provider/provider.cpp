//
// Created by gregory on 27.02.2021.
//

#include <provider.h>

err_t provider_handler(const provider_t &request)
{
    static dataset_t figure = init();
    err_t error_code = OK;

    switch (request.code)
    {
        case SAVE_DATASET:
            error_code = save_dataset(figure, request.file_name);
            break;
        case LOAD_DATASET:
            error_code = load_dataset(figure, request.file_name);
            break;
        case TRANSLATE_DATASET:
            error_code = translate_dataset(figure, request.translation);
            break;
        case RESIZE_DATASET:
            error_code = resize_dataset(figure, request.scale);
            break;
        case ROTATE_DATASET:
            error_code = rotate_dataset(figure, request.turn);
            break;
        case MOVE_DATASET:
            error_code = move_dataset(figure, request.move);
            break;
        case DRAW_DATASET:
            error_code = draw_dataset(figure, request.drawer);
            break;
        case STOP_EXECUTION:
            free_dataset(figure);
            break;
        default:
            error_code = UNKNOWN_COMMAND;
    }

    return error_code;
}