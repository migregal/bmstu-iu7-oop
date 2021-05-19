#pragma once

#include <memory>

#include <managers/draw/draw_manager.h>

class DrawManagerCreator {
public:
    std::shared_ptr<DrawManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<DrawManager> _manager;
};
