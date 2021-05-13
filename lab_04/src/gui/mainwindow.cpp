#include <QDebug>
#include <gui/mainwindow.h>
#include <gui/design.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qDebug() << "Stopped at 1 floor, doors are closed.\n"
              "Waiting state...";

  for (int i = 0; i < ui->cabin_buttons.size(); ++i) {
    connect(ui->cabin_buttons[i], &QPushButton::pressed, this,
            [=, this]() {on_button_cabin_clicked(i + 1); });
  }

  for (int i = 0; i < ui->cabin_buttons.size(); ++i) {
    connect(ui->floor_buttons[i], &QPushButton::pressed, this,
            [=, this]() {on_button_floor_clicked(i + 1); });
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_button_cabin_clicked(int num) {
  qDebug() << "Cabin pressed button " << num;
  lift.click(num);
}

void MainWindow::on_button_floor_clicked(int num) {
  qDebug() << "Floor " << num << " call.";
  lift.click(num);
}
