#include <facade.h>
#include <load/file_loader.h>
#include <load/model_loader.h>

#include <memory>

void Facade::load_model(std::string fname) {
    std::shared_ptr<Model> model = _load_manager->load_model(fname);
    _scene_manager.get_scene()->add_model(model);
}

void Facade::add_model(const std::shared_ptr<Object> &model) {
    _scene_manager.get_scene()->add_model(model);
}

void Facade::remove_model(const size_t &index) {
    _scene_manager.get_scene()->remove_model(index);
}

void Facade::add_camera(const Point &cam_pos) {
    std::shared_ptr<Camera> cam(new Camera);
    cam->reform(cam_pos, cam_pos, cam_pos);

    _scene_manager.get_scene()->add_camera(cam);
    _scene_manager.set_cam(_scene_manager.get_scene()->get_cams().size() - 1);
}

void Facade::remove_camera(const size_t &index) {
    _scene_manager.get_scene()->remove_camera(index);
}

void Facade::reform_model(const size_t &model_numb, const Point &move, const Point &scale, const Point &turn) {
    std::shared_ptr<Object> model = _scene_manager.get_scene()->get_models().at(model_numb - 1);
    ReformManager::reform_object(model, move, scale, turn);
}

void Facade::set_camera(const size_t &camera_numb) {
    _scene_manager.set_cam(camera_numb);
}

void Facade::draw_scene(const std::shared_ptr<BaseDrawer> &_drawer) {
    _drawer->clear_scene();
    _draw_manager->set_drawer(_drawer);
    _draw_manager->set_cam(_scene_manager.get_cam());
    _scene_manager.get_scene()->get_composite()->accept(_draw_manager);
}

void Facade::reform_cam(const size_t &cam_numb, const Point &shift) {
    auto camera = _scene_manager.get_scene()->get_cams().at(cam_numb - 1);
    ReformManager::reform_object(camera, shift, shift, shift);
}

size_t Facade::cams_count() {
    return _scene_manager.get_scene()->get_cams().size();
}

size_t Facade::models_count() {
    return _scene_manager.get_scene()->get_cams().size();
}

Facade::Facade() {
    _draw_manager = std::make_shared<DrawManager>();
    std::shared_ptr<BaseLoader> floader(new FileLoader);
    _load_manager = std::shared_ptr<AbstractLoader>(new ModelLoader(floader));
}
