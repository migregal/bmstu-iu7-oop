#pragma once

#include <qt5/QtCore/QVariant>
#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QComboBox>
#include <qt5/QtWidgets/QDoubleSpinBox>
#include <qt5/QtWidgets/QFrame>
#include <qt5/QtWidgets/QGraphicsView>
#include <qt5/QtWidgets/QGridLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtWidgets/QPushButton>
#include <qt5/QtWidgets/QStatusBar>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QPushButton *left_button;
    QPushButton *add_camera;
    QPushButton *load_button;
    QPushButton *down_button;
    QPushButton *right_button;
    QGraphicsView *graphicsView;
    QPushButton *up_button;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QFrame *move_label;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *dy_box;
    QDoubleSpinBox *dz_box;
    QDoubleSpinBox *dx_box;
    QPushButton *move_button;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *ky_box;
    QDoubleSpinBox *kx_box;
    QLabel *label_6;
    QDoubleSpinBox *kz_box;
    QPushButton *scale_button;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QDoubleSpinBox *oy_box;
    QDoubleSpinBox *ox_box;
    QDoubleSpinBox *oz_box;
    QLabel *label_10;
    QPushButton *turn_button;
    QLabel *label_11;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QComboBox *model_choose;
    QPushButton *delete_model;
    QPushButton *clear_screen;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QComboBox *camera_choose;
    QPushButton *delete_camera;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1087, 737);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        left_button = new QPushButton(centralwidget);
        left_button->setObjectName(QString::fromUtf8("left_button"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        left_button->setFont(font);

        gridLayout_3->addWidget(left_button, 2, 0, 1, 1);

        add_camera = new QPushButton(centralwidget);
        add_camera->setObjectName(QString::fromUtf8("add_camera"));
        add_camera->setFont(font);

        gridLayout_3->addWidget(add_camera, 2, 4, 1, 1);

        load_button = new QPushButton(centralwidget);
        load_button->setObjectName(QString::fromUtf8("load_button"));
        load_button->setFont(font);

        gridLayout_3->addWidget(load_button, 2, 2, 1, 2);

        down_button = new QPushButton(centralwidget);
        down_button->setObjectName(QString::fromUtf8("down_button"));
        down_button->setFont(font);

        gridLayout_3->addWidget(down_button, 2, 5, 1, 1);

        right_button = new QPushButton(centralwidget);
        right_button->setObjectName(QString::fromUtf8("right_button"));
        right_button->setFont(font);

        gridLayout_3->addWidget(right_button, 2, 6, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFont(font);

        gridLayout_3->addWidget(graphicsView, 0, 0, 1, 7);

        up_button = new QPushButton(centralwidget);
        up_button->setObjectName(QString::fromUtf8("up_button"));
        up_button->setFont(font);

        gridLayout_3->addWidget(up_button, 2, 1, 1, 1);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFont(font);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        move_label = new QFrame(frame_4);
        move_label->setObjectName(QString::fromUtf8("move_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(move_label->sizePolicy().hasHeightForWidth());
        move_label->setSizePolicy(sizePolicy1);
        move_label->setFont(font);
        move_label->setFrameShape(QFrame::StyledPanel);
        move_label->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(move_label);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(move_label);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(move_label);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(move_label);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        dy_box = new QDoubleSpinBox(move_label);
        dy_box->setObjectName(QString::fromUtf8("dy_box"));
        dy_box->setFont(font);
        dy_box->setMinimum(-10000000000000000000000.000000000000000);
        dy_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_5->addWidget(dy_box, 1, 1, 1, 1);

        dz_box = new QDoubleSpinBox(move_label);
        dz_box->setObjectName(QString::fromUtf8("dz_box"));
        dz_box->setFont(font);
        dz_box->setMinimum(-99999999999999991611392.000000000000000);
        dz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(dz_box, 2, 1, 1, 1);

        dx_box = new QDoubleSpinBox(move_label);
        dx_box->setObjectName(QString::fromUtf8("dx_box"));
        dx_box->setFont(font);
        dx_box->setMinimum(-10000000000000000.000000000000000);
        dx_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_5->addWidget(dx_box, 0, 1, 1, 1);

        move_button = new QPushButton(move_label);
        move_button->setObjectName(QString::fromUtf8("move_button"));
        move_button->setFont(font);

        gridLayout_5->addWidget(move_button, 3, 0, 1, 2);


        verticalLayout->addWidget(move_label);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFont(font);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        ky_box = new QDoubleSpinBox(frame_2);
        ky_box->setObjectName(QString::fromUtf8("ky_box"));
        ky_box->setFont(font);
        ky_box->setMinimum(0.000000000000000);
        ky_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_6->addWidget(ky_box, 1, 1, 1, 1);

        kx_box = new QDoubleSpinBox(frame_2);
        kx_box->setObjectName(QString::fromUtf8("kx_box"));
        kx_box->setFont(font);
        kx_box->setMinimum(0.000000000000000);
        kx_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_6->addWidget(kx_box, 0, 1, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        kz_box = new QDoubleSpinBox(frame_2);
        kz_box->setObjectName(QString::fromUtf8("kz_box"));
        kz_box->setFont(font);
        kz_box->setMinimum(0.000000000000000);
        kz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_6->addWidget(kz_box, 2, 1, 1, 1);

        scale_button = new QPushButton(frame_2);
        scale_button->setObjectName(QString::fromUtf8("scale_button"));
        scale_button->setFont(font);

        gridLayout_6->addWidget(scale_button, 3, 0, 1, 2);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFont(font);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout_7->addWidget(label_12, 1, 0, 1, 1);

        oy_box = new QDoubleSpinBox(frame_3);
        oy_box->setObjectName(QString::fromUtf8("oy_box"));
        oy_box->setFont(font);
        oy_box->setMinimum(-10000000000000000000000.000000000000000);
        oy_box->setMaximum(10000000000000000000000.000000000000000);

        gridLayout_7->addWidget(oy_box, 1, 1, 1, 1);

        ox_box = new QDoubleSpinBox(frame_3);
        ox_box->setObjectName(QString::fromUtf8("ox_box"));
        ox_box->setFont(font);
        ox_box->setMinimum(-10000000000000000.000000000000000);
        ox_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(ox_box, 0, 1, 1, 1);

        oz_box = new QDoubleSpinBox(frame_3);
        oz_box->setObjectName(QString::fromUtf8("oz_box"));
        oz_box->setFont(font);
        oz_box->setMinimum(-99999999999999991611392.000000000000000);
        oz_box->setMaximum(10000000000000000.000000000000000);

        gridLayout_7->addWidget(oz_box, 2, 1, 1, 1);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout_7->addWidget(label_10, 2, 0, 1, 1);

        turn_button = new QPushButton(frame_3);
        turn_button->setObjectName(QString::fromUtf8("turn_button"));
        turn_button->setFont(font);

        gridLayout_7->addWidget(turn_button, 3, 0, 1, 2);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);


        verticalLayout->addWidget(frame_3);

        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        model_choose = new QComboBox(frame);
        model_choose->setObjectName(QString::fromUtf8("model_choose"));
        model_choose->setFont(font);

        verticalLayout_2->addWidget(model_choose);

        delete_model = new QPushButton(frame);
        delete_model->setObjectName(QString::fromUtf8("delete_model"));
        delete_model->setFont(font);

        verticalLayout_2->addWidget(delete_model);

        clear_screen = new QPushButton(frame);
        clear_screen->setObjectName(QString::fromUtf8("clear_screen"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clear_screen->sizePolicy().hasHeightForWidth());
        clear_screen->setSizePolicy(sizePolicy2);
        clear_screen->setFont(font);

        verticalLayout_2->addWidget(clear_screen);


        verticalLayout->addWidget(frame);

        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFont(font);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_3->addWidget(label_8);

        camera_choose = new QComboBox(frame_5);
        camera_choose->setObjectName(QString::fromUtf8("camera_choose"));
        camera_choose->setFont(font);

        verticalLayout_3->addWidget(camera_choose);

        delete_camera = new QPushButton(frame_5);
        delete_camera->setObjectName(QString::fromUtf8("delete_camera"));
        delete_camera->setFont(font);

        verticalLayout_3->addWidget(delete_camera);


        verticalLayout->addWidget(frame_5);


        gridLayout_3->addWidget(frame_4, 0, 7, 1, 1, Qt::AlignTop);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(graphicsView, dx_box);
        QWidget::setTabOrder(dx_box, dy_box);
        QWidget::setTabOrder(dy_box, dz_box);
        QWidget::setTabOrder(dz_box, move_button);
        QWidget::setTabOrder(move_button, kx_box);
        QWidget::setTabOrder(kx_box, ky_box);
        QWidget::setTabOrder(ky_box, kz_box);
        QWidget::setTabOrder(kz_box, scale_button);
        QWidget::setTabOrder(scale_button, ox_box);
        QWidget::setTabOrder(ox_box, oy_box);
        QWidget::setTabOrder(oy_box, oz_box);
        QWidget::setTabOrder(oz_box, turn_button);
        QWidget::setTabOrder(turn_button, model_choose);
        QWidget::setTabOrder(model_choose, delete_model);
        QWidget::setTabOrder(delete_model, camera_choose);
        QWidget::setTabOrder(camera_choose, delete_camera);
        QWidget::setTabOrder(delete_camera, left_button);
        QWidget::setTabOrder(left_button, up_button);
        QWidget::setTabOrder(up_button, load_button);
        QWidget::setTabOrder(load_button, add_camera);
        QWidget::setTabOrder(add_camera, down_button);
        QWidget::setTabOrder(down_button, right_button);

        retranslateUi(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lab 03", nullptr));
        left_button->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        add_camera->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        down_button->setText(QCoreApplication::translate("MainWindow", "\342\254\207", nullptr));
        right_button->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        up_button->setText(QCoreApplication::translate("MainWindow", "\342\254\206", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", " dz", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " dy", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " dx", nullptr));
        move_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " ky", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " kx", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " kz", nullptr));
        scale_button->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "oy", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "oz", nullptr));
        turn_button->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ox", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        delete_model->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        clear_screen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\215\320\272\321\200\320\260\320\275", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", nullptr));
        delete_camera->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE
