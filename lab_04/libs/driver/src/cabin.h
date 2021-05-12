#pragma once

#include <QObject>

#include <controller.h>
#include <door.h>

class Cabin : public QObject {
  Q_OBJECT;

  enum cabin_status { GET, FREE, MOVING };

public:
  explicit Cabin(QObject *parent = nullptr);
  ~Cabin() override = default;

public slots:
  void cabin_moving();
  void cabin_take_target(int floor);
  void cabin_stopped(bool is_last, int new_floor = 1);

signals:
  void open_doors_signal();
  void floor_passed(int floor, direction dir);

private:
  Door _door;
  int cur_floor;
  int need_floor;

  direction _direction;
  cabin_status status;

  QTimer move_timer;

signals:
  void moving_signal();
  void stopped_signal(bool = true, int = 1);
};
