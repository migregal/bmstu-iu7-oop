#include <cabin.h>

#include <QDebug>

Cabin::Cabin(QObject *parent) {
  status = FREE;
  cur_floor = 1;
  need_floor = 1;
  _direction = STOP;

  QObject::connect(&move_timer, SIGNAL(timeout()), this, SLOT(cabin_moving()));

  QObject::connect(this, SIGNAL(moving_signal()), this, SLOT(cabin_moving()));
  QObject::connect(this, SIGNAL(stopped_signal(bool, int)), this,
                   SLOT(cabin_stopped(bool, int)));
  QObject::connect(this, SIGNAL(open_doors_signal()), &_door, SLOT(opening()));
  QObject::connect(&_door, SIGNAL(closed_signal()), this, SLOT(cabin_moving()));
}

void Cabin::cabin_moving() {
  if (status != MOVING && status != GET)
    return;

  status = MOVING;
  move_timer.start(MOVING_TIME);

  qDebug() << "Лифт едет. Этаж: " << cur_floor;
  emit floor_passed(cur_floor, _direction);

  if (cur_floor != need_floor) {
    _direction = cur_floor > need_floor ? DOWN : UP;
    cur_floor = cur_floor > need_floor ? cur_floor - 1 : cur_floor + 1;
  }
}

void Cabin::cabin_stopped(bool is_last, int new_floor) {
  if (is_last) {
    status = FREE;
  } else {
    status = GET;
    need_floor = new_floor;
  }

  move_timer.stop();
  emit open_doors_signal();
}

void Cabin::cabin_take_target(int floor) {
  status = GET;
  need_floor = floor;

  if (cur_floor == need_floor) {
    emit floor_passed(cur_floor, _direction);
  } else {
    _direction = need_floor > cur_floor ? UP : DOWN;
    emit moving_signal();
  }
}
