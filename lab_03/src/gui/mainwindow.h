#pragma once

#include <QMainWindow>
#include <QMessageBox>

#include <driver/commands/base_command.h>
#include <driver/commands/camera_command.h>
#include <driver/commands/model_command.h>
#include <driver/commands/scene_command.h>
#include <driver/drawer.h>
#include <driver/error.h>
#include <driver/facade/facade.h>

#include "design.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    void setup_scene();

    void update_scene();

    void clear_scene();

    void check_cam_exist();

    void check_can_delete_cam();

    void check_models_exist();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void change_cam();

    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

    void on_load_button_clicked();

    void on_delete_model_button_clicked();

    void on_add_camera_clicked();

    void on_delete_camera_clicked();

    void on_right_button_clicked();

    void on_up_button_clicked();

    void on_down_button_clicked();

    void on_left_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<BaseDrawer> _drawer;
};
