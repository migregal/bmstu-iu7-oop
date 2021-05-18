#include <builder/load/scene/scene_builder.h>

bool Load::SceneBuilder::is_build() const {
    return nullptr != scene_ptr;
}

void Load::SceneBuilder::build() {
    scene_ptr = std::make_shared<Scene>();
}

std::shared_ptr<Object> Load::SceneBuilder::get() {
    return scene_ptr;
}

void Load::SceneBuilder::build_model(const std::shared_ptr<Object> &object) {
    if (!is_build()) {}

    scene_ptr->add_model(object);
}

void Load::SceneBuilder::build_camera(const std::shared_ptr<Camera> &camera) {
    if (!is_build()) {}

    scene_ptr->add_camera(camera);
}
