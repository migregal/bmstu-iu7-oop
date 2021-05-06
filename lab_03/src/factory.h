#pragma once

#include <drawer/qt_drawer.h>
#include <memory>

class AbstractFactory {
public:
    virtual std::unique_ptr<BaseDrawer> create_graphics() = 0;
};

class QtFactory : public AbstractFactory {
public:
    std::unique_ptr<BaseDrawer> create_graphics() override {
        return std::unique_ptr<BaseDrawer>(new QtDrawer);
    }
};
