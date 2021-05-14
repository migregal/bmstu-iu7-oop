#include <lift.h>

Lift::Lift() {
  QObject::connect(&control_panel, SIGNAL(set_target(int, direction)), &cabin,
                   SLOT(cabin_call(int, direction)));
  QObject::connect(&cabin, SIGNAL(cabin_crossing_floor(int, direction)),
                   &control_panel, SLOT(passed_floor(int)));
  QObject::connect(&cabin, SIGNAL(cabin_stopped(int)), &control_panel,
                   SLOT(achieved_floor(int)));
}

void Lift::click(int floor) { control_panel.set_new_target(floor); }
