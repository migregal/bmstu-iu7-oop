/********************************************************************************
** Form generated from reading UI file 'design.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGN_H
#define DESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_save;
    QAction *action_load;
    QWidget *root;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *canvas;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *movement_frame;
    QGridLayout *gridLayout;
    QLabel *movement_label;
    QLabel *movement_y_l;
    QLabel *movement_x_l;
    QPushButton *movevemt_apply;
    QDoubleSpinBox *movement_y;
    QDoubleSpinBox *movement_x;
    QLabel *movement_z_l;
    QDoubleSpinBox *movement_z;
    QFrame *rotation_frame;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *rotation_z;
    QPushButton *rotation_apply;
    QLabel *rotation_y_l;
    QLabel *rotation_x_l;
    QDoubleSpinBox *rotation_x;
    QLabel *rotation_label;
    QDoubleSpinBox *rotation_y;
    QLabel *rotation_z_l;
    QFrame *resizing_frame;
    QGridLayout *gridLayout_3;
    QLabel *resizing_kz_l;
    QLabel *resizing_ky_l;
    QDoubleSpinBox *resizing_ky;
    QLabel *resizing_kx_l;
    QDoubleSpinBox *resizing_kx;
    QDoubleSpinBox *resizing_kz;
    QPushButton *resizing_apply;
    QLabel *resizing_label;
    QPushButton *translate_to_center_apply;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(826, 640);
        MainWindow->setMinimumSize(QSize(826, 0));
        MainWindow->setMaximumSize(QSize(826, 16777215));
        MainWindow->setDockNestingEnabled(true);
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_load = new QAction(MainWindow);
        action_load->setObjectName(QString::fromUtf8("action_load"));
        root = new QWidget(MainWindow);
        root->setObjectName(QString::fromUtf8("root"));
        horizontalLayout = new QHBoxLayout(root);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        canvas = new QGraphicsView(root);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        canvas->setFont(font);

        horizontalLayout->addWidget(canvas);

        frame = new QFrame(root);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFont(font);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        movement_frame = new QFrame(frame);
        movement_frame->setObjectName(QString::fromUtf8("movement_frame"));
        movement_frame->setFont(font);
        movement_frame->setFrameShape(QFrame::StyledPanel);
        movement_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(movement_frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        movement_label = new QLabel(movement_frame);
        movement_label->setObjectName(QString::fromUtf8("movement_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(movement_label->sizePolicy().hasHeightForWidth());
        movement_label->setSizePolicy(sizePolicy2);
        movement_label->setFont(font);

        gridLayout->addWidget(movement_label, 0, 0, 1, 2);

        movement_y_l = new QLabel(movement_frame);
        movement_y_l->setObjectName(QString::fromUtf8("movement_y_l"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(movement_y_l->sizePolicy().hasHeightForWidth());
        movement_y_l->setSizePolicy(sizePolicy3);
        movement_y_l->setFont(font);

        gridLayout->addWidget(movement_y_l, 3, 0, 1, 1);

        movement_x_l = new QLabel(movement_frame);
        movement_x_l->setObjectName(QString::fromUtf8("movement_x_l"));
        sizePolicy3.setHeightForWidth(movement_x_l->sizePolicy().hasHeightForWidth());
        movement_x_l->setSizePolicy(sizePolicy3);
        movement_x_l->setFont(font);

        gridLayout->addWidget(movement_x_l, 1, 0, 1, 1);

        movevemt_apply = new QPushButton(movement_frame);
        movevemt_apply->setObjectName(QString::fromUtf8("movevemt_apply"));
        movevemt_apply->setFont(font);

        gridLayout->addWidget(movevemt_apply, 5, 0, 1, 2);

        movement_y = new QDoubleSpinBox(movement_frame);
        movement_y->setObjectName(QString::fromUtf8("movement_y"));
        movement_y->setFont(font);
        movement_y->setMinimum(-10000.000000000000000);
        movement_y->setMaximum(10000.000000000000000);

        gridLayout->addWidget(movement_y, 3, 1, 1, 1);

        movement_x = new QDoubleSpinBox(movement_frame);
        movement_x->setObjectName(QString::fromUtf8("movement_x"));
        movement_x->setFont(font);
        movement_x->setMinimum(-10000.000000000000000);
        movement_x->setMaximum(10000.000000000000000);

        gridLayout->addWidget(movement_x, 1, 1, 1, 1);

        movement_z_l = new QLabel(movement_frame);
        movement_z_l->setObjectName(QString::fromUtf8("movement_z_l"));
        movement_z_l->setFont(font);

        gridLayout->addWidget(movement_z_l, 4, 0, 1, 1);

        movement_z = new QDoubleSpinBox(movement_frame);
        movement_z->setObjectName(QString::fromUtf8("movement_z"));
        movement_z->setFont(font);
        movement_z->setMinimum(-10000.000000000000000);
        movement_z->setMaximum(10000.000000000000000);

        gridLayout->addWidget(movement_z, 4, 1, 1, 1);


        verticalLayout->addWidget(movement_frame);

        rotation_frame = new QFrame(frame);
        rotation_frame->setObjectName(QString::fromUtf8("rotation_frame"));
        rotation_frame->setFont(font);
        rotation_frame->setFrameShape(QFrame::StyledPanel);
        rotation_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(rotation_frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rotation_z = new QDoubleSpinBox(rotation_frame);
        rotation_z->setObjectName(QString::fromUtf8("rotation_z"));
        rotation_z->setFont(font);

        gridLayout_2->addWidget(rotation_z, 3, 1, 1, 1);

        rotation_apply = new QPushButton(rotation_frame);
        rotation_apply->setObjectName(QString::fromUtf8("rotation_apply"));
        rotation_apply->setFont(font);

        gridLayout_2->addWidget(rotation_apply, 4, 0, 1, 2);

        rotation_y_l = new QLabel(rotation_frame);
        rotation_y_l->setObjectName(QString::fromUtf8("rotation_y_l"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(rotation_y_l->sizePolicy().hasHeightForWidth());
        rotation_y_l->setSizePolicy(sizePolicy4);
        rotation_y_l->setFont(font);

        gridLayout_2->addWidget(rotation_y_l, 2, 0, 1, 1);

        rotation_x_l = new QLabel(rotation_frame);
        rotation_x_l->setObjectName(QString::fromUtf8("rotation_x_l"));
        sizePolicy4.setHeightForWidth(rotation_x_l->sizePolicy().hasHeightForWidth());
        rotation_x_l->setSizePolicy(sizePolicy4);
        rotation_x_l->setFont(font);

        gridLayout_2->addWidget(rotation_x_l, 1, 0, 1, 1);

        rotation_x = new QDoubleSpinBox(rotation_frame);
        rotation_x->setObjectName(QString::fromUtf8("rotation_x"));
        rotation_x->setFont(font);
        rotation_x->setMinimum(-10000.000000000000000);
        rotation_x->setMaximum(10000.000000000000000);

        gridLayout_2->addWidget(rotation_x, 1, 1, 1, 1);

        rotation_label = new QLabel(rotation_frame);
        rotation_label->setObjectName(QString::fromUtf8("rotation_label"));
        sizePolicy2.setHeightForWidth(rotation_label->sizePolicy().hasHeightForWidth());
        rotation_label->setSizePolicy(sizePolicy2);
        rotation_label->setFont(font);

        gridLayout_2->addWidget(rotation_label, 0, 0, 1, 2);

        rotation_y = new QDoubleSpinBox(rotation_frame);
        rotation_y->setObjectName(QString::fromUtf8("rotation_y"));
        rotation_y->setFont(font);
        rotation_y->setMinimum(-10000.000000000000000);
        rotation_y->setMaximum(10000.000000000000000);

        gridLayout_2->addWidget(rotation_y, 2, 1, 1, 1);

        rotation_z_l = new QLabel(rotation_frame);
        rotation_z_l->setObjectName(QString::fromUtf8("rotation_z_l"));
        rotation_z_l->setFont(font);

        gridLayout_2->addWidget(rotation_z_l, 3, 0, 1, 1);


        verticalLayout->addWidget(rotation_frame);

        resizing_frame = new QFrame(frame);
        resizing_frame->setObjectName(QString::fromUtf8("resizing_frame"));
        resizing_frame->setFont(font);
        resizing_frame->setFrameShape(QFrame::StyledPanel);
        resizing_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(resizing_frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        resizing_kz_l = new QLabel(resizing_frame);
        resizing_kz_l->setObjectName(QString::fromUtf8("resizing_kz_l"));
        sizePolicy1.setHeightForWidth(resizing_kz_l->sizePolicy().hasHeightForWidth());
        resizing_kz_l->setSizePolicy(sizePolicy1);
        resizing_kz_l->setFont(font);

        gridLayout_3->addWidget(resizing_kz_l, 3, 0, 1, 1);

        resizing_ky_l = new QLabel(resizing_frame);
        resizing_ky_l->setObjectName(QString::fromUtf8("resizing_ky_l"));
        sizePolicy1.setHeightForWidth(resizing_ky_l->sizePolicy().hasHeightForWidth());
        resizing_ky_l->setSizePolicy(sizePolicy1);
        resizing_ky_l->setFont(font);

        gridLayout_3->addWidget(resizing_ky_l, 2, 0, 1, 1);

        resizing_ky = new QDoubleSpinBox(resizing_frame);
        resizing_ky->setObjectName(QString::fromUtf8("resizing_ky"));
        resizing_ky->setFont(font);
        resizing_ky->setMinimum(-10000.000000000000000);
        resizing_ky->setMaximum(10000.000000000000000);

        gridLayout_3->addWidget(resizing_ky, 2, 1, 1, 1);

        resizing_kx_l = new QLabel(resizing_frame);
        resizing_kx_l->setObjectName(QString::fromUtf8("resizing_kx_l"));
        sizePolicy1.setHeightForWidth(resizing_kx_l->sizePolicy().hasHeightForWidth());
        resizing_kx_l->setSizePolicy(sizePolicy1);
        resizing_kx_l->setFont(font);

        gridLayout_3->addWidget(resizing_kx_l, 1, 0, 1, 1);

        resizing_kx = new QDoubleSpinBox(resizing_frame);
        resizing_kx->setObjectName(QString::fromUtf8("resizing_kx"));
        resizing_kx->setFont(font);
        resizing_kx->setMinimum(-10000.000000000000000);
        resizing_kx->setMaximum(10000.000000000000000);

        gridLayout_3->addWidget(resizing_kx, 1, 1, 1, 1);

        resizing_kz = new QDoubleSpinBox(resizing_frame);
        resizing_kz->setObjectName(QString::fromUtf8("resizing_kz"));
        resizing_kz->setFont(font);
        resizing_kz->setMinimum(-10000.000000000000000);
        resizing_kz->setMaximum(10000.000000000000000);

        gridLayout_3->addWidget(resizing_kz, 3, 1, 1, 1);

        resizing_apply = new QPushButton(resizing_frame);
        resizing_apply->setObjectName(QString::fromUtf8("resizing_apply"));
        resizing_apply->setFont(font);

        gridLayout_3->addWidget(resizing_apply, 4, 0, 1, 2);

        resizing_label = new QLabel(resizing_frame);
        resizing_label->setObjectName(QString::fromUtf8("resizing_label"));
        sizePolicy2.setHeightForWidth(resizing_label->sizePolicy().hasHeightForWidth());
        resizing_label->setSizePolicy(sizePolicy2);
        resizing_label->setFont(font);

        gridLayout_3->addWidget(resizing_label, 0, 0, 1, 2);


        verticalLayout->addWidget(resizing_frame);

        translate_to_center_apply = new QPushButton(frame);
        translate_to_center_apply->setObjectName(QString::fromUtf8("translate_to_senter_apply"));

        verticalLayout->addWidget(translate_to_center_apply);


        horizontalLayout->addWidget(frame, 0, Qt::AlignHCenter|Qt::AlignTop);

        MainWindow->setCentralWidget(root);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 826, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(action_save);
        menuFile->addAction(action_load);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 1", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        action_save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_load->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        action_load->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        movement_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\211\320\265\320\274\320\265\320\275\320\270\320\265", nullptr));
        movement_y_l->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        movement_x_l->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        movevemt_apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        movement_z_l->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        rotation_apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        rotation_y_l->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        rotation_x_l->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        rotation_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        rotation_z_l->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        resizing_kz_l->setText(QCoreApplication::translate("MainWindow", "Kz", nullptr));
        resizing_ky_l->setText(QCoreApplication::translate("MainWindow", "Ky", nullptr));
        resizing_kx_l->setText(QCoreApplication::translate("MainWindow", "Kx", nullptr));
        resizing_apply->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        resizing_label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        translate_to_center_apply->setText(QCoreApplication::translate("MainWindow", "\320\222 \321\206\320\265\320\275\321\202\321\200", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGN_H
