#include <objects/camera/camera.h>

#include <commands/camera_command.h>
#include <managers/reform/reform_manager_creator.h>
#include <managers/scene/scene_manager_creator.h>

#define cd const double

AddCamera::AddCamera(cd x, cd y, cd z) : x_pos(x), y_pos(y), z_pos(z) {}

void AddCamera::execute() {
    Point cam_pos(x_pos, y_pos, z_pos);

    std::shared_ptr<Camera> cam(new Camera);
    cam->reform(cam_pos, cam_pos, cam_pos);

    auto _scene_manager = SceneManagerCreator().create_manager();
    _scene_manager->get_scene()->add_camera(cam);
    _scene_manager->set_cam(_scene_manager->get_scene()->get_cams().size() - 1);
}

RemoveCamera::RemoveCamera(const std::size_t &camera_numb) : camera_numb(camera_numb) {}

void RemoveCamera::execute() {
    SceneManagerCreator().create_manager()->get_scene()->remove_camera(camera_numb);
}

MoveCamera::MoveCamera(const std::size_t &cam_number, cd &shift_ox, cd &shift_oy) : cam_number(cam_number), shift_ox(shift_ox), shift_oy(shift_oy) {}

void MoveCamera::execute() {
    Point shift(shift_ox, shift_oy, 0);
    auto camera = SceneManagerCreator().create_manager()->get_scene()->get_cams().at(cam_number);
    ReformManagerCreator().create_manager()->reform_object(camera, shift, shift, shift);
}

SetCamera::SetCamera(const std::size_t &cam_number) : cam_number(cam_number) {}

void SetCamera::execute() {
    SceneManagerCreator().create_manager()->set_cam(cam_number);
}

CameraCount::CameraCount(std::shared_ptr<size_t> &count) : _count(count) {}

void CameraCount::execute() {
    (*_count) = SceneManagerCreator().create_manager()->get_scene()->get_cams().size();
}
