#include <gui/qt/mainwindow.h>


#include <QFileDialog>

#include <qt/qt_drawer_factory.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setup_scene();
    _facade = std::make_shared<Facade>(Facade());

    connect(ui->load_button, &QPushButton::clicked, this, &MainWindow::on_load_button_clicked);
    connect(ui->delete_model, &QPushButton::clicked, this, &MainWindow::on_delete_model_button_clicked);

    connect(ui->add_camera, &QPushButton::clicked, this, &MainWindow::on_add_camera_clicked);
    connect(ui->delete_camera, &QPushButton::clicked, this, &MainWindow::on_delete_camera_clicked);

    connect(ui->clear_screen, &QPushButton::clicked, this, &MainWindow::clear_scene);

    connect(ui->right_button, &QPushButton::clicked, this, &MainWindow::on_right_button_clicked);
    connect(ui->up_button, &QPushButton::clicked, this, &MainWindow::on_up_button_clicked);
    connect(ui->down_button, &QPushButton::clicked, this, &MainWindow::on_down_button_clicked);
    connect(ui->left_button, &QPushButton::clicked, this, &MainWindow::on_left_button_clicked);

    connect(ui->move_button, &QPushButton::clicked, this, &MainWindow::on_move_button_clicked);
    connect(ui->scale_button, &QPushButton::clicked, this, &MainWindow::on_scale_button_clicked);
    connect(ui->turn_button, &QPushButton::clicked, this, &MainWindow::on_turn_button_clicked);

    connect(ui->camera_choose, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::change_cam);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::check_cam_exist() {
    auto camera_count = std::make_shared<size_t>(0);
    CameraCount camera_command(camera_count);
    _facade->execute(camera_command);

    if (!*camera_count) {
        std::string message = "No camera found.";
        throw CameraError(message);
    }
}

void MainWindow::check_can_delete_cam() {
    auto model_count = std::make_shared<size_t>(0);
    ModelCount model_command(model_count);
    _facade->execute(model_command);

    auto camera_count = std::make_shared<size_t>(0);
    CameraCount camera_command(camera_count);
    _facade->execute(camera_command);

    if (*camera_count <= 1 && *model_count) {
        std::string message = "Can not delete the last camera with the loaded models";
        throw CameraError(message);
    }
}

void MainWindow::check_models_exist() {
    auto count = std::make_shared<size_t>(0);
    ModelCount model_command(count);
    _facade->execute(model_command);

    if (!*count) {
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

    MoveModel move_command(
            ui->dx_box->value(),
            ui->dy_box->value(),
            ui->dz_box->value(),
            ui->model_choose->currentIndex());
    _facade->execute(move_command);
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

    ScaleModel scale_command(
            ui->kx_box->value(),
            ui->ky_box->value(),
            ui->kz_box->value(),
            ui->model_choose->currentIndex());
    _facade->execute(scale_command);
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

    RotateModel rotate_command(
            ui->ox_box->value(),
            ui->oy_box->value(),
            ui->oz_box->value(),
            ui->model_choose->currentIndex());
    _facade->execute(rotate_command);
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
        _facade->execute(load_command);
    } catch (const SourceError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Что-то пошло не так при загрузке файла...");
        return;
    }

    update_scene();
    ui->model_choose->addItem(QFileInfo(t.toUtf8().data()).fileName());
    ui->model_choose->setCurrentIndex(ui->model_choose->count() - 1);
}

void MainWindow::on_delete_model_button_clicked() {
    try {
        check_models_exist();
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
        return;
    }

    RemoveModel remove_command(ui->model_choose->currentIndex());
    _facade->execute(remove_command);

    ui->model_choose->removeItem(ui->model_choose->currentIndex());

    update_scene();
}

void MainWindow::setup_scene() {
    _scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto rcontent = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());

    std::shared_ptr<AbstractDrawerFactory> factory(new QtDrawerFactory(_scene));
    _drawer = factory->create_graphics();
}

void MainWindow::update_scene() {
    DrawScene draw_command(_drawer);
    _facade->execute(draw_command);
}

void MainWindow::clear_scene() {
    try {
        check_models_exist();
    } catch (const ModelError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модели, добавьте хотя бы одну.");
        return;
    }

    for (int i = ui->model_choose->count() - 1; i >= 0; --i) {
        RemoveModel remove_command(i);
        _facade->execute(remove_command);

        ui->model_choose->removeItem(i);
    }

    update_scene();
}

void MainWindow::on_add_camera_clicked() {
    auto rcontent = ui->graphicsView->contentsRect();
    AddCamera camera_command(rcontent.width() / 2.0, rcontent.height() / 2.0, 0.0);
    _facade->execute(camera_command);

    update_scene();

    auto cam = ui->camera_choose;
    if (0 == cam->count())
        cam->addItem(QString::number(1));
    else
        cam->addItem(QString::number(
                cam->itemText(cam->count() - 1).toInt() + 1));

    ui->camera_choose->setCurrentIndex(ui->camera_choose->count() - 1);
}

void MainWindow::on_delete_camera_clicked() {
    try {
        check_cam_exist();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
        return;
    }

    try {
        check_can_delete_cam();
    } catch (const CameraError &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, необходимо удалить оставшиеся модели.");
        return;
    }

    RemoveCamera remove_command(ui->camera_choose->currentIndex());
    _facade->execute(remove_command);

    ui->camera_choose->removeItem(ui->camera_choose->currentIndex());

    try {
        check_cam_exist();
    } catch (const CameraError &error) {
        return;
    }

    update_scene();
}

void MainWindow::change_cam() {
    try {
        check_cam_exist();
    } catch (const CameraError &error) {
        return;
    }

    SetCamera camera_command(ui->camera_choose->currentIndex());
    _facade->execute(camera_command);
    update_scene();
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

    MoveCamera camera_command(ui->camera_choose->currentIndex(), 10, 0);
    _facade->execute(camera_command);
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

    MoveCamera camera_command(ui->camera_choose->currentIndex(), 0, -10);
    _facade->execute(camera_command);
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

    MoveCamera camera_command(ui->camera_choose->currentIndex(), 0, 10);
    _facade->execute(camera_command);
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

    MoveCamera camera_command(ui->camera_choose->currentIndex(), -10, 0);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    _scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    auto rcontent = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());
}
