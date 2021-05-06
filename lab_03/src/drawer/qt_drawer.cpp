#include "qt_drawer.h"

QtDrawer::QtDrawer(QGraphicsScene *_scene)  : scene(_scene){}

QtDrawer::QtDrawer(const QtDrawer &_drawer) : scene(_drawer.scene) {}

void QtDrawer::clear_scene() {
    scene->clear();
}

void QtDrawer::draw_line(const Point &point1, const Point &point2) {
    scene->addLine(point1.get_x(), point1.get_y(), point2.get_x(), point2.get_y());
}
