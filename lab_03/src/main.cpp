#include <QApplication>

#include <QScreen>
#include <QStyle>
#include <gui/mainwindow.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.setGeometry(QStyle::alignedRect(
            Qt::LeftToRight, Qt::AlignCenter, window.size(),
            QGuiApplication::primaryScreen()->availableGeometry()));
    window.show();

    return QApplication::exec();
}