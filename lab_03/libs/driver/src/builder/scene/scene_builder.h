#pragma once

#include <builder/base_builder.h>
#include <scene/scene.h>

class SceneBuilder : public BaseBuilder {
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    [[nodiscard]] bool is_build() const override;
    void build() override;
    void build_model(const std::shared_ptr<Object> &object);
    void build_camera(const std::shared_ptr<Camera> &camera);

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Scene> scene_ptr;
};