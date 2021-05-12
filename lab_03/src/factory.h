#pragma once

#include <memory>

#include <driver/abstract_fabric.h>
#include <drawer/qt_drawer.h>


class QtFactory : public AbstractFactory {
public:
    explicit QtFactory(QGraphicsScene *scene) : _scene(scene) {}

    std::unique_ptr<BaseDrawer> create_graphics() override {
        return std::unique_ptr<BaseDrawer>(new QtDrawer(_scene));
    }
private:
    QGraphicsScene *_scene;
};
