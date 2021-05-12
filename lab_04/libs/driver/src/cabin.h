#pragma once

#include <QObject>

#include <Door.h>
#include <controller.h>

class Cabin : public QObject {
  Q_OBJECT;

  enum cabin_status { GET, FREE, MOVING };

public:
  explicit Cabin(QObject *parent = nullptr);
  ~Cabin() override = default;

public slots:
  void cabin_moving();
  void cabin_take_target(ssize_t floor);
  void cabin_stopped(bool is_last, ssize_t new_floor = 1);

signals:
  void open_doors_signal();
  void floor_passed(ssize_t floor, direction dir);

private:
  Door _door;
  ssize_t current_floor;
  ssize_t need_floor;

  direction _direction;
  cabin_status status;

  QTimer move_timer;

signals:
  void moving_signal();
  void stopped_signal(bool = true, ssize_t = 1);
};
