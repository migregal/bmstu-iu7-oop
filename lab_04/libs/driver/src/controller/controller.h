#pragma once

#include <memory>
#include <vector>

#include <QDebug>
#include <QVBoxLayout>
#include <QWidget>

#include <button/button.h>

#define FLOOR_COUNT 9
#define DOORS_TIME 500
#define MOVING_TIME 3000

enum direction { DOWN = -1, STOP = 0, UP = 1 };

class Controller : public QWidget {
  Q_OBJECT;

  enum status { FREE, BUSY };

public:
  explicit Controller(QWidget *parent = nullptr);
  ~Controller() override = default;

public slots:
  void new_target(int floor);
  void passed_floor(int floor, direction direction_);

signals:
  void new_target_signal(int floor);
  void stopped_signal(bool, int = 1);

private:
  status status;
  direction _direction;
  int current_floor;
  int needed_floor;

  std::vector<std::shared_ptr<Button>> buttons;
  std::vector<bool> visited_floors;
  std::unique_ptr<QVBoxLayout> layout;

  bool target_exist(int &new_floor);
};
