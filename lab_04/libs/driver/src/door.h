#pragma once

#include <QDebug>
#include <QObject>
#include <QTimer>

class Door : public QObject {
  Q_OBJECT;

  enum status { OPEN, OPENING, CLOSING, CLOSED };

public:
  Door();
  ~Door() override = default;

public slots:
  void opened();
  void closed();

private slots:
  void opening();
  void closing();

signals:
  void closed_signal();

private:
  status status;

  QTimer opening_timer;
  QTimer closing_timer;
  QTimer opened_timer;
};
