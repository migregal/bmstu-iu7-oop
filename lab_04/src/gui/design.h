#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
  QWidget *centralWidget;
  QGridLayout *gridLayout;
  QGroupBox *groupBox_1;
  QGridLayout *gridLayout_3;
  std::vector<QPushButton *> cabin_buttons;
  std::vector<QPushButton *> floor_buttons;
  QGroupBox *groupBox_2;
  QGridLayout *gridLayout_2;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(576, 175);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox_1 = new QGroupBox(centralWidget);
    groupBox_1->setObjectName(QString::fromUtf8("groupBox_2"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(groupBox_1->sizePolicy().hasHeightForWidth());
    groupBox_1->setSizePolicy(sizePolicy);
    QFont font;
    font.setPointSize(10);
    groupBox_1->setFont(font);
    gridLayout_3 = new QGridLayout(groupBox_1);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

    for (int i = 0, row = (NUM_FLOORS + 2) / 3; i < NUM_FLOORS; ++i) {
      auto button = new QPushButton(groupBox_1);
      gridLayout_3->addWidget(button, row, i % 3, 1, 1);
      cabin_buttons.push_back(button);

      if (!((i + 1) % 3))
        --row;
    }

    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);

    gridLayout->addWidget(groupBox_1, 0, 0, 1, 1);

    groupBox_2 = new QGroupBox(centralWidget);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_3"));
    sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());

    groupBox_2->setSizePolicy(sizePolicy1);
    groupBox_2->setFont(font);
    gridLayout_2 = new QGridLayout(groupBox_2);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

    for (int i = 0, row = (NUM_FLOORS + 2) / 3; i < NUM_FLOORS; ++i) {
      auto button = new QPushButton(groupBox_2);
      gridLayout_2->addWidget(button, row, i % 3, 1, 1);
      floor_buttons.push_back(button);

      if (!((i + 1) % 3))
        --row;
    }

    gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

    MainWindow->setCentralWidget(centralWidget);

    retranslateUi(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    groupBox_1->setTitle(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\275\320\276\320\277\320\272\320\270 \320\262 "
        "\320\273\320\270\321\204\321\202\320\265",
        nullptr));

    for (int i = 0; i < cabin_buttons.size(); ++i) {
      cabin_buttons[i]->setText(QCoreApplication::translate(
          "MainWindow", QString::number(i + 1).toUtf8().data(), nullptr));
    }

    for (int i = 0; i < cabin_buttons.size(); ++i) {
      floor_buttons[i]->setText(QCoreApplication::translate(
          "MainWindow", QString::number(i + 1).toUtf8().data(), nullptr));
    }

    groupBox_2->setTitle(QCoreApplication::translate(
        "MainWindow",
        "\320\232\320\275\320\276\320\277\320\272\320\270 \320\275\320\260 "
        "\321\215\321\202\320\260\320\266\320\260\321\205",
        nullptr));
  } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE
