//
// Created by gregory on 27.02.2021.
//

#ifndef LAB_01_ERRORS_H
#define LAB_01_ERRORS_H

enum err_t
{
    OK,
    FILE_ERR,
    ALLOC_ERR,
    READ_ERR,
    WRITE_ERR,
    LSIZE_ERR,
    PSIZE_ERR,
    MEMORY_ERR,
    UNKNOWN_COMMAND
};

void handle_error(const err_t &code);

#endif //LAB_01_ERRORS_H
