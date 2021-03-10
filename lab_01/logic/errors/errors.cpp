//
// Created by gregory on 27.02.2021.
//

#include <QMessageBox>

#include <errors.h>

void handle_error(const err_t &code) {

    switch (code) {
        case FILE_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "При открытии файла произошла ошибка.");
            break;
        case ALLOC_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "При выделении памяти произошла ошибка.");
            break;
        case WRITE_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "При записи файла произошла ошибка.");
            break;
        case READ_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "При чтении файла произошла ошибка.");
            break;
        case PSIZE_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Некорретный размер количества точек.");
            break;
        case LSIZE_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Некорректный размер количества линий.");
            break;
        case MEMORY_ERR:
            QMessageBox::critical(nullptr, "Ошибка",
                                  "Ошибка при обращении к данным.");
            break;
        default:
            QMessageBox::critical(nullptr, "Ошибка", "Неизвестная комманда.");
    }
}