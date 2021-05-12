#include <lift.h>

#include <QPalette>

Lift::Lift(QObject *parent) : QObject(parent) {
  _controller.setStyleSheet("background-color:green;");

  QObject::connect(&_cabin, SIGNAL(floor_passed(int, direction)),
                   &_controller, SLOT(passed_floor(int, direction)));
  QObject::connect(&_controller, SIGNAL(new_target_signal(int)), &_cabin,
                   SLOT(cabin_take_target(int)));
  QObject::connect(&_controller, SIGNAL(stopped_signal(bool, int)), &_cabin,
                   SLOT(cabin_stopped(bool, int)));
}

QWidget *Lift::widget() { return &_controller; }
