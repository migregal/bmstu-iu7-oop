#pragma once

#include <QObject>
#include <QPushButton>

class Button : public QPushButton {
  Q_OBJECT;

  enum status { active, not_active };

public:
  explicit Button(QWidget *parent = nullptr);
  ~Button() override = default;

  void set_floor(const int &floor);

public slots:
  void pressed();
  void unpressed();

signals:
  void floor_pressed(int floor);
  void unpress_signal();

private:
  status status;
  int button_floor;
};
