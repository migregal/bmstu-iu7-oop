#include <button.h>

#include <QDebug>

Button::Button(QWidget *parrent) : QPushButton(parrent) {
  QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressed()));
  QObject::connect(this, SIGNAL(unpress_signal()), this, SLOT(unpressed()));

  status = not_active;
  button_floor = 1;
}

void Button::set_floor(const ssize_t &floor) { button_floor = floor; }

void Button::pressed() {
  if (status == not_active) {
    setStyleSheet("background-color:red;");
    update();

    status = active;
    setDisabled(true);
    emit floor_pressed(button_floor);
  }
}

void Button::unpressed() {
  if (status == active) {
    setStyleSheet("background-color:green;");
    update();

    status = not_active;
    setDisabled(false);
  }
}
