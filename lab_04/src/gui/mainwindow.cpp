#include <gui/mainwindow.h>

#include <memory>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setFixedSize(200, 500);
  this->layout = std::make_unique<QVBoxLayout>();
  this->ui->centralwidget->setLayout(this->layout.get());
  this->layout->addWidget(this->_lift.widget());
}

MainWindow::~MainWindow() { delete ui; }
