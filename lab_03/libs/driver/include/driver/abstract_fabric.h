#pragma once

#include <memory>

#include <driver/base_drawer.h>

class AbstractFactory {
public:
    virtual std::unique_ptr<BaseDrawer> create_graphics() = 0;
};