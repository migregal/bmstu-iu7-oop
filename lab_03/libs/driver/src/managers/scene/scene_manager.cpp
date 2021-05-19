#include <managers/scene/scene_manager.h>

#include <memory>
#include <utility>

SceneManager::SceneManager() {
    _scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::get_scene() const {
    return _scene;
}

std::shared_ptr<Camera> SceneManager::get_cam() const {
    return current_cam;
}

void SceneManager::set_scene(std::shared_ptr<Scene> scene_) {
    _scene = std::move(scene_);
}

void SceneManager::set_cam(const std::size_t &number) {
    auto _camera = _scene->get_cams().at(number);
    current_cam = _camera;
}
