#include <gui/mainwindow.h>

#include <memory>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(200, 500);
  layout = std::make_unique<QVBoxLayout>();
  ui->centralwidget->setLayout(layout.get());
  layout->addWidget(_lift.widget());
}

MainWindow::~MainWindow() { delete ui; }
