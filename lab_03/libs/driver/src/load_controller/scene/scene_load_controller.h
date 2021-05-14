#pragma once

#include <builder/scene/scene_builder.h>
#include <load_controller/abstract_load_controller.h>
#include <loader/base_loader.h>
#include <loader/scene/base_scene_loader.h>
#include <utility>

class SceneLoadController : public AbstractLoadController {
public:
    explicit SceneLoadController(std::shared_ptr<BaseSceneLoader> _loader) : builder(new SceneBuilder), loader(std::move(_loader)){};
    ~SceneLoadController() = default;

    std::shared_ptr<Object> load(std::string &name) override;

private:
    std::shared_ptr<SceneBuilder> builder;
    std::shared_ptr<BaseSceneLoader> loader;
};
