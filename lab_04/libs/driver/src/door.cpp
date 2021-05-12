#include <door.h>

#include <controller.h>

Door::Door() {
  status = CLOSED;

  QObject::connect(&opening_timer, SIGNAL(timeout()), this, SLOT(opened()));
  QObject::connect(&opened_timer, SIGNAL(timeout()), this, SLOT(closing()));
  QObject::connect(&closing_timer, SIGNAL(timeout()), this, SLOT(closed()));
}

void Door::opening() {
  if (CLOSED != status && CLOSING != status)
    return;

  qDebug() << "Двери открываются.";

  if (CLOSED == status) {
    status = OPENING;
    opening_timer.start(DOORS_TIME);
  } else {
    status = OPENING;
    auto timer = closing_timer.remainingTime();
    closing_timer.stop();
    opening_timer.start(DOORS_TIME - timer);
  }
}

void Door::opened() {
  if (OPENING != status)
    return;

  status = OPEN;
  qDebug() << "Двери открыты!";
  opened_timer.start(DOORS_TIME);
}

void Door::closing() {
  if (OPEN != status)
    return;

  status = CLOSING;
  qDebug() << "Двери закрываются.";
  closing_timer.start(DOORS_TIME);
}

void Door::closed() {
  if (CLOSING != status)
    return;

  status = CLOSED;
  qDebug() << "Двери закрыты.";
  emit closed_signal();
}
