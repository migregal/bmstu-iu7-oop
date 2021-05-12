#pragma once

#include <QGraphicsScene>

#include <driver/base_drawer.h>

class QtDrawer : public BaseDrawer {
public:
    QtDrawer() = delete;
    explicit QtDrawer(QGraphicsScene *_scene);
    QtDrawer(const QtDrawer &_drawer);

    void draw_line(const Point &point1, const Point &point2) override;
    void clear_scene() override;

private:
    QGraphicsScene *scene;
};