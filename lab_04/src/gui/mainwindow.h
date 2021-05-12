#pragma once

#include <memory>

#include <QMainWindow>
#include <QVBoxLayout>

#include <driver/lift.h>

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

private:
  Ui::MainWindow *ui;

  std::unique_ptr<QVBoxLayout> layout;
  Lift _lift;
};
