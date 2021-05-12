#pragma once

#include <QObject>
#include <QPushButton>

class Button : public QPushButton {
  Q_OBJECT;

  enum status { active, not_active };

public:
  explicit Button(QWidget *parent = nullptr);
  ~Button() override = default;

  void set_floor(const ssize_t &floor);

public slots:
  void pressed();
  void unpressed();

signals:
  void floor_pressed(ssize_t floor);
  void unpress_signal();

private:
  status status;
  ssize_t button_floor;
};
