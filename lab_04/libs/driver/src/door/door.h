#pragma once

#include <QObject>

#include <constants.h>

class Doors : public QObject {
  Q_OBJECT
  enum doors_state { OPENNING, OPENED, CLOSING, CLOSED };

public:
  explicit Doors(QObject *parent = nullptr);

signals:
  void closed_doors();
  void opened_doors();

public slots:
  void start_openning();
  void start_closing();

private slots:
  void open();
  void close();

private:
  doors_state current_state;
  QTimer doors_open_timer;
  QTimer doors_close_timer;
  QTimer doors_stay_open_timer;
};
