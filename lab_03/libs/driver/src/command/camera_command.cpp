#include <commands/camera_command.h>

#define cd const double

AddCamera::AddCamera(cd x, cd y, cd z) : x_pos(x), y_pos(y), z_pos(z) {}

void AddCamera::execute(std::shared_ptr<AbstractFacade> &facade) {
    Point cam_pos(x_pos, y_pos, z_pos);

    facade->add_camera(cam_pos);
}

RemoveCamera::RemoveCamera(const size_t &camera_numb) : camera_numb(camera_numb) {}

void RemoveCamera::execute(std::shared_ptr<AbstractFacade> &facade) {
    facade->remove_camera(camera_numb);
}

MoveCamera::MoveCamera(const size_t &cam_number, cd &shift_ox, cd &shift_oy) : cam_number(cam_number), shift_ox(shift_ox), shift_oy(shift_oy){}

void MoveCamera::execute(std::shared_ptr<AbstractFacade> &facade) {
    Point shift(shift_ox, shift_oy, 0);
    facade->reform_cam(cam_number, shift);
}

SetCamera::SetCamera(const size_t &cam_number): cam_number(cam_number) {}

void SetCamera::execute(std::shared_ptr<AbstractFacade> &facade) {
    facade->set_camera(cam_number);
}
