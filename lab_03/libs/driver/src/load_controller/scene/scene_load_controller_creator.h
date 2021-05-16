#pragma once

#include <load_controller/scene/scene_load_controller.h>

class SceneLoadControllerCreator {
public:
    std::shared_ptr<SceneLoadController> create_controller();
    std::shared_ptr<SceneLoadController> create_controller(const std::shared_ptr<BaseSceneLoader>& loader);

private:
    void create_instance();

    std::shared_ptr<SceneLoadController> _controller;
};
