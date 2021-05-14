#include <door/door.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), current_state(CLOSED) {
  doors_stay_open_timer.setInterval(WAITING_TIME);
  doors_stay_open_timer.setSingleShot(true);

  doors_open_timer.setSingleShot(true);
  doors_close_timer.setSingleShot(true);

  QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(open()));
  QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(close()));
  QObject::connect(this, SIGNAL(opened_doors()), &doors_stay_open_timer,
                   SLOT(start()));
  QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), this,
                   SLOT(start_closing()));
}

void Doors::start_openning() {
  if (CLOSED != current_state && CLOSING != current_state)
    return;

  if (current_state == CLOSED) {
    current_state = OPENNING;
    qDebug() << "Doors are opening...";
    doors_open_timer.start(DOORS_TIME);
  } else {
    current_state = OPENNING;
    qDebug() << "Doors are opening...";
    int t = doors_close_timer.remainingTime();
    doors_close_timer.stop();
    doors_open_timer.start(DOORS_TIME - t);
  }
}

void Doors::start_closing() {
  if (OPENED != current_state && CLOSED != current_state)
    return;

  if (current_state == CLOSED) {
    emit closed_doors();
  } else {
    current_state = CLOSING;
    qDebug() << "Doors are closing...";
    doors_close_timer.start(DOORS_TIME);
  }
}

void Doors::open() {
  if (current_state != OPENNING)
    return;

  current_state = OPENED;
  qDebug() << "The doors are opened!\nWaiting for passengers...";
  emit opened_doors();
}

void Doors::close() {
  if (current_state != CLOSING)
    return;

  current_state = CLOSED;
  qDebug() << "The doors are closed.";
  emit closed_doors();
}
