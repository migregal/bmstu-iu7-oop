#include <scene/scene.h>

void Scene::add_model(const std::shared_ptr<Object> &model) {
    models->add(model);
}

void Scene::remove_model(const size_t index) {
    //models->remove(index);
}

void Scene::add_camera(const std::shared_ptr<Camera> &camera) {
    cams.push_back(camera);
}

void Scene::remove_camera(const size_t index) {
    cams.remove(index);
}

Vector<std::shared_ptr<Object>> Scene::get_models() {
    return models->get_objects();
}

std::shared_ptr<Composite> Scene::get_composite() {
    return models;
}

Vector<std::shared_ptr<Camera>> Scene::get_cams() {
    return cams;
}
