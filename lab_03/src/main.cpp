#include <QApplication>

#include <QScreen>
#include <QStyle>

#include <driver/configuration/configuration_creator.h>

#include <gui/qt/mainwindow.h>

int main(int argc, char *argv[]) {
    auto _conf = ConfigurationCreator().get_configuration();

    switch (_conf->get_frame()) {
        case AbstractConfiguration::QT:
        default:
            QApplication a(argc, argv);

            MainWindow window;
            window.setGeometry(QStyle::alignedRect(
                    Qt::LeftToRight, Qt::AlignCenter, window.size(),
                    QGuiApplication::primaryScreen()->availableGeometry()));
            window.show();

            return QApplication::exec();
    }
}