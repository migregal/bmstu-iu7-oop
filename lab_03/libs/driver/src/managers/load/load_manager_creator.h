#pragma once

#include <memory>

#include <managers/load/load_manager.h>

class LoadManagerCreator {
public:
    std::shared_ptr<LoadManager> create_manager();
    std::shared_ptr<LoadManager> create_manager(const std::shared_ptr<AbstractLoadController>& loader);

private:
    void create_instance();

    std::shared_ptr<LoadManager> _manager;
};
