#include "mainwindow.h"
#include "../factory.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          _facade(nullptr) {
    ui->setupUi(this);
    setup_scene();
    _facade = std::shared_ptr<Facade>(Facade::instance());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::check_cam_exist() {
    if (!_facade->cams_count()) {
        std::string message = "No camera found.";
        throw CameraError(message);
    }
}

void MainWindow::check_models_exist() {
    if (!_facade->models_count()) {
        std::string message = "No models found.";
        throw ModelError(message);
    }
}

void MainWindow::on_move_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    MoveModel move_command(10, 10, 10, 1);
    move_command.execute(_facade);
    update_scene();
}

void MainWindow::on_scale_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    ScaleModel scale_command(2, 2, 2, 1);
    scale_command.execute(_facade);
    update_scene();
}

void MainWindow::on_turn_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    RotateModel turn_command(3, 3, 3, 1);
    turn_command.execute(_facade);
    update_scene();
}

void MainWindow::on_load_button_clicked() {
    try {
        check_cam_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
        return;
    }

    auto t = QFileDialog::getOpenFileName();

    if (t.isNull())
        return;

    LoadModel load_command(t.toUtf8().data());

    try {
        load_command.execute(_facade);
    } catch (const FileError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Что-то не так пошло при загрузке файла...");
        return;
    }

    update_scene();
}

void MainWindow::setup_scene() {
    _scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    _scene->setSceneRect(0, 0, win_x, win_y);

    std::shared_ptr<AbstractFactory> factory(new QtFactory);
    std::shared_ptr<BaseDrawer> drawer(new QtDrawer(_scene));
    _drawer = drawer;
}

void MainWindow::update_scene() {
    DrawScene draw_command(_drawer);
    draw_command.execute(_facade);
}

void MainWindow::clear_scene() {
}

void MainWindow::on_add_camera_clicked() {
    AddCamera camera_command(win_x / 2, win_y / 2, 0);
    camera_command.execute(_facade);
}

void MainWindow::on_right_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    MoveCamera camera_command(1, 10, 0);
    camera_command.execute(_facade);
    update_scene();
}

void MainWindow::on_up_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    MoveCamera camera_command(1, 0, 10);
    camera_command.execute(_facade);
    update_scene();
}

void MainWindow::on_down_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    MoveCamera camera_command(1, 0, -10);
    camera_command.execute(_facade);
    update_scene();
}

void MainWindow::on_left_button_clicked() {
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    MoveCamera camera_command(1, -10, 0);
    camera_command.execute(_facade);
    update_scene();
}
