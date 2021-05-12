#include "button.h"
#include <QDebug>

Button::Button(QWidget *parrent) : QPushButton(parrent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressed()));
    QObject::connect(this, SIGNAL(unpress_signal()), this, SLOT(unpressed()));

    this->status = not_active;
    this->button_floor = 1;
}

void Button::set_floor(const ssize_t &floor)
{
    this->button_floor = floor;
}

void Button::pressed()
{
    if (status == not_active)
    {
        this->setStyleSheet("background-color:red;");
        this->update();

        this->status = active;
        this->setDisabled(true);
        emit floor_pressed(this->button_floor);
    }
}

void Button::unpressed()
{
    if (status == active)
    {
        this->setStyleSheet("background-color:green;");
        this->update();

        this->status = not_active;
        this->setDisabled(false);
    }
}
