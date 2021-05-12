#include <controller.h>

#include <memory>

Controller::Controller(QWidget *parent) : QWidget(parent) {
  layout = std::make_unique<QVBoxLayout>();
  setLayout(layout.get());

  for (int i = 0; i < FLOOR_COUNT; i++) {
    std::shared_ptr<Button> btn(new Button);
    btn->set_floor(FLOOR_COUNT - i);
    btn->setText(QString::number(FLOOR_COUNT - i));

    buttons.insert(buttons.begin(), btn);
    layout->addWidget(dynamic_cast<QPushButton *>(btn.get()));

    visited_floors.push_back(true);
    QObject::connect(btn.get(), SIGNAL(floor_pressed(ssize_t)), this,
                     SLOT(new_target(ssize_t)));
  }
}

void Controller::new_target(ssize_t floor) {
  status = BUSY;
  visited_floors[floor - 1] = false;

  target_exist(floor);
  needed_floor = floor;
  emit new_target_signal(floor);
}

void Controller::passed_floor(ssize_t floor, direction direction_) {
  if (status == BUSY) {
    current_floor = floor;
    _direction = direction_;

    if (current_floor == needed_floor) {
      qDebug() << "Лифт остановился на этаже: " << floor;

      emit buttons.at(floor - 1)->unpress_signal();
      visited_floors[floor - 1] = true;

      if (target_exist(floor)) {
        needed_floor = floor;
        emit stopped_signal(false, floor);
      } else {
        status = FREE;
        emit stopped_signal(true);
      }
    }
  }
}

bool Controller::target_exist(ssize_t &new_floor) {
  int direction = _direction != STOP ? _direction : DOWN;

  for (int i = current_floor - 1; i >= 0 && i < FLOOR_COUNT; i += direction) {
    if (!visited_floors[i]) {
      new_floor = i + 1;
      return true;
    }
  }

  for (int i = current_floor - 1; i >= 0 && i < FLOOR_COUNT; i += -direction) {
    if (!visited_floors[i]) {
      new_floor = i + 1;
      return true;
    }
  }

  return false;
}
