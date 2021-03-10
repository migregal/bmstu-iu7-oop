//
// Created by gregory on 26.02.2021.
//
#include <QFileDialog>

#include <MainWindow.h>
#include <design.h>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto *scene = new QGraphicsScene(this);
    ui->canvas->setScene(scene);
    ui->canvas->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    connect(ui->action_save, &QAction::triggered, this,
            &MainWindow::on_save_button_clicked);

    connect(ui->action_load, &QAction::triggered, this,
            &MainWindow::on_load_button_clicked);

    connect(ui->movevemt_apply, &QPushButton::clicked, this,
            &MainWindow::on_move_button_clicked);

    connect(ui->rotation_apply, &QPushButton::clicked, this,
            &MainWindow::on_rotation_button_clicked);

    connect(ui->resizing_apply, &QPushButton::clicked, this,
            &MainWindow::on_resize_button_clicked);

    connect(ui->translate_to_center_apply, &QPushButton::clicked, this,
            &MainWindow::on_translate_to_center_button_clicked);
}

MainWindow::~MainWindow() {
    provider_t request{.code = STOP_EXECUTION};
    provider_handler(request);

    delete ui;
}

err_t MainWindow::translate_objects() {
    auto rcontent = ui->canvas->contentsRect();
    ui->canvas->scene()->setSceneRect(0, 0, rcontent.width(),
                                      rcontent.height());

    provider_t request{
            .code = TRANSLATE_DATASET,
            .translation {
                    ui->canvas->scene()->width() / 2,
                    ui->canvas->scene()->height() / 2
            }
    };

    return provider_handler(request);
}

err_t MainWindow::draw_actions() {
    auto rcontent = ui->canvas->contentsRect();
    ui->canvas->scene()->setSceneRect(0, 0, rcontent.width(),
                                      rcontent.height());

    drawer_t drawer{ui->canvas->scene()};

    provider_t request{
            .code = DRAW_DATASET,
            .drawer = drawer
    };

    return provider_handler(request);
}

void MainWindow::on_save_button_clicked() {
    auto t = QFileDialog::getSaveFileName();

    if (t.isNull())
        return;

    provider_t request{
            .code = SAVE_DATASET,
            .file_name = t.toUtf8().data()
    };

    err_t error_code = provider_handler(request);

    if (error_code)
        handle_error(error_code);
}

void MainWindow::on_load_button_clicked() {
    auto t = QFileDialog::getOpenFileName();

    if (t.isNull())
        return;

    provider_t request{
            .code = LOAD_DATASET,
            .file_name = t.toUtf8().data()
    };

    err_t error_code = provider_handler(request);
    if (error_code) {
        handle_error(error_code);
        return;
    }

    if ((error_code = translate_objects())) {
        handle_error(error_code);
        return;
    }

    if ((error_code = draw_actions()))
        handle_error(error_code);
}

void MainWindow::on_move_button_clicked() {
    movement_t coeffs{
            .dx = ui->movement_x->value(),
            .dy = ui->movement_y->value(),
            .dz = ui->movement_z->value()
    };

    provider_t request{
            .code = MOVE_DATASET,
            .move = coeffs
    };

    err_t error_code;
    if ((error_code = provider_handler(request))) {
        handle_error(error_code);
        return;
    }

    if ((error_code = draw_actions()))
        handle_error(error_code);
}

void MainWindow::on_resize_button_clicked() {
    resize_t coeffs{
            .kx = ui->resizing_kx->value(),
            .ky = ui->resizing_ky->value(),
            .kz = ui->resizing_kz->value(),
    };

    provider_t request{
            .code = RESIZE_DATASET,
            .scale = coeffs
    };

    err_t error_code;
    if ((error_code = provider_handler(request))) {
        handle_error(error_code);
        return;
    }

    if ((error_code = draw_actions()))
        handle_error(error_code);
}

void MainWindow::on_rotation_button_clicked() {
    rotation_t coeffs{
            .ox = ui->rotation_x->value(),
            .oy = ui->rotation_y->value(),
            .oz = ui->rotation_z->value()
    };

    provider_t request{
            .code = ROTATE_DATASET,
            .turn = coeffs
    };

    err_t error_code;
    if ((error_code = provider_handler(request))) {
        handle_error(error_code);
        return;
    }

    if ((error_code = draw_actions()))
        handle_error(error_code);
}

void MainWindow::on_translate_to_center_button_clicked() {
    err_t error_code = translate_objects();
    if (error_code) {
        handle_error(error_code);
        return;
    }

    if ((error_code = draw_actions()))
        handle_error(error_code);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    draw_actions();
}
