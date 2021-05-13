#include <managers/reform_manager.h>
#include <managers/scene_manager.h>
#include <objects/camera.h>

#include <commands/camera_command.h>

#define cd const double

AddCamera::AddCamera(cd x, cd y, cd z) : x_pos(x), y_pos(y), z_pos(z) {}

void AddCamera::execute() {
    Point cam_pos(x_pos, y_pos, z_pos);

    std::shared_ptr<Camera> cam(new Camera);
    cam->reform(cam_pos, cam_pos, cam_pos);

    auto _scene_manager = SceneManager::instance();
    _scene_manager->get_scene()->add_camera(cam);
    _scene_manager->set_cam(_scene_manager->get_scene()->get_cams().size() - 1);
}

RemoveCamera::RemoveCamera(const size_t &camera_numb) : camera_numb(camera_numb) {}

void RemoveCamera::execute() {
    SceneManager::instance()->get_scene()->remove_camera(camera_numb);
}

MoveCamera::MoveCamera(const size_t &cam_number, cd &shift_ox, cd &shift_oy) : cam_number(cam_number), shift_ox(shift_ox), shift_oy(shift_oy) {}

void MoveCamera::execute() {
    Point shift(shift_ox, shift_oy, 0);
    auto camera = SceneManager::instance()->get_scene()->get_cams().at(cam_number);
    ReformManager::reform_object(camera, shift, shift, shift);
}

SetCamera::SetCamera(const size_t &cam_number) : cam_number(cam_number) {}

void SetCamera::execute() {
    SceneManager::instance()->set_cam(cam_number);
}

CameraCount::CameraCount(std::shared_ptr<size_t> &count) : _count(count) {}

void CameraCount::execute() {
    (*_count) = SceneManager::instance()->get_scene()->get_cams().size();
}
