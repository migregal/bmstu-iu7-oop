#pragma once

#include <memory>

#include <drawer/abstract_drawer.h>

class AbstractDrawerFactory {
public:
    virtual std::unique_ptr<AbstractDrawer> create_graphics() = 0;
};