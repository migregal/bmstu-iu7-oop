#include <builder/scene/scene_builder.h>

bool SceneBuilder::is_build() const {
    return nullptr != scene_ptr;
}

void SceneBuilder::build() {
    scene_ptr = std::make_shared<Scene>();
}

std::shared_ptr<Object> SceneBuilder::get() {
    return scene_ptr;
}

void SceneBuilder::build_model(const std::shared_ptr<Object> &object) {
    if (!is_build()) {}

    scene_ptr->add_model(object);
}

void SceneBuilder::build_camera(const std::shared_ptr<Camera> &camera) {
    if (!is_build()) {}

    scene_ptr->add_camera(camera);
}
