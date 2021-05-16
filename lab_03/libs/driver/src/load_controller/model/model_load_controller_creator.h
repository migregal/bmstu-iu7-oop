#pragma once

#include <memory>

#include "model_load_controller.h"

class ModelLoadControllerCreator {
public:
    std::shared_ptr<ModelLoadController> create_controller();
    std::shared_ptr<ModelLoadController> create_controller(const std::shared_ptr<BaseModelLoader>& loader);

private:
    void create_instance();

    std::shared_ptr<ModelLoadController> _controller;
};
