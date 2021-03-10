//
// Created by gregory on 26.02.2021.
//

#ifndef LAB_01_MAINWINDOW_H
#define LAB_01_MAINWINDOW_H


#include <QMainWindow>

#include <provider.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    static void on_save_button_clicked();

    void on_load_button_clicked();

    void on_move_button_clicked();

    void on_resize_button_clicked();

    void on_rotation_button_clicked();

    void on_translate_to_center_button_clicked();

    err_t translate_objects();

    err_t draw_actions();

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //LAB_01_MAINWINDOW_H
