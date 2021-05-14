#pragma once

#include <QObject>

#include <constants.h>
#include <control_panel/control_panel.h>
#include <door/door.h>

class Cabin : public QObject {
  Q_OBJECT
  enum cabin_state { MOVE, WAIT, STOP };

public:
  explicit Cabin(QObject *parent = nullptr);

signals:
  void cabin_called();
  void cabin_crossing_floor(int floor, direction d);
  void cabin_reached_target(int floor);
  void cabin_stopped(int floor);

public slots:
  void cabin_move();
  void cabin_stopping();
  void cabin_call(int floor, direction dir);

private:
  int current_floor;
  int target;
  bool new_target;
  cabin_state current_state;
  direction current_direction;
  Doors doors;
  QTimer crossing_floor_timer;
};
