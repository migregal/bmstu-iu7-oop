#pragma once

#include <memory>

#include <managers/reform/reform_manager.h>

class ReformManagerCreator {
public:
    std::shared_ptr<ReformManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<ReformManager> _manager;
};
