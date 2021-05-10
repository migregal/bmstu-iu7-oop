#pragma once

#include <QMainWindow>
#include <QMessageBox>

#include <driver/base_command.h>
#include <driver/camera_command.h>
#include <driver/drawer.h>
#include <driver/error.h>
#include <driver/facade/base_facade.h>
#include <driver/facade/base_facade_creator.h>
#include <driver/model_command.h>
#include <driver/scene_command.h>

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

    void check_models_exist();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

    void on_load_button_clicked();

    void on_add_camera_clicked();

    void on_right_button_clicked();

    void on_up_button_clicked();

    void on_down_button_clicked();

    void on_left_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    std::shared_ptr<AbstractFacade> _facade;
    std::shared_ptr<BaseDrawer> _drawer;
};
