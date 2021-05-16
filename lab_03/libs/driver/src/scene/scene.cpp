#include <scene/scene.h>

#include <iterator>

void Scene::add_model(const std::shared_ptr<Object> &model) {
    models->add(model);
}

void Scene::remove_model(const std::size_t index) {
    auto it = models->begin();
    std::advance(it, index);
    models->remove(it);
}

void Scene::add_camera(const std::shared_ptr<Camera> &camera) {
    cams.push_back(camera);
}

void Scene::remove_camera(const std::size_t index) {
    auto it = cams.begin();
    std::advance(it, index);
    cams.erase(it);
}

std::vector<std::shared_ptr<Object>> Scene::get_models() {
    return models->get_objects();
}

std::shared_ptr<Composite> Scene::get_composite() {
    return models;
}

std::vector<std::shared_ptr<Camera>> Scene::get_cams() {
    return cams;
}
