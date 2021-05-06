#pragma once

#include <QGraphicsScene>

#include <driver/drawer.h>

class QtDrawer : public BaseDrawer {
public:
    QtDrawer() = default;
    explicit QtDrawer(QGraphicsScene *_scene);
    QtDrawer(const QtDrawer &_drawer);

    void draw_line(const Point &point1, const Point &point2) override;
    void clear_scene() override;

private:
    QGraphicsScene *scene;
};