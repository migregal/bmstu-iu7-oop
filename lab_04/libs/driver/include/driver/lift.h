#pragma once

#include <QObject>
#include <QTextEdit>

#include <cabin/cabin.h>
#include <constants.h>
#include <control_panel/control_panel.h>

class Lift : public QObject {
  Q_OBJECT

public:
  Lift();
  void click(int floor);

private:
  ControlPanel control_panel;
  Cabin cabin;
};
