#pragma once

#include <QObject>

#include <cabin.h>
#include <controller.h>

class Lift : public QObject {
  Q_OBJECT;

public:
  explicit Lift(QObject *parent = nullptr);
  ~Lift() override = default;

  QWidget *widget();

private:
  Controller _controller;
  Cabin _cabin;
};
