#pragma once

#include <memory>

#include <managers/scene/scene_manager.h>

class SceneManagerCreator {
public:
    std::shared_ptr<SceneManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<SceneManager> _manager;
};
