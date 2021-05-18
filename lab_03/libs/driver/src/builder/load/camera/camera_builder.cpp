#include <builder/load/camera/camera_builder.h>

bool Load::CameraBuilder::is_build() const {
    return nullptr != camera_ptr;
}
void Load::CameraBuilder::build() {
    camera_ptr = std::make_shared<Camera>();
}

void Load::CameraBuilder::build_position(double x, double y, double z) {

}

std::shared_ptr<Object> Load::CameraBuilder::get() {
    return camera_ptr;
}
