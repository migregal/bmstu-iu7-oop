#include <builder/camera/camera_builder.h>

bool CameraBuilder::is_build() const {
    return nullptr != camera_ptr;
}
void CameraBuilder::build() {
    camera_ptr = std::make_shared<Camera>();
}

void CameraBuilder::build_position(double x, double y, double z) {

}

std::shared_ptr<Object> CameraBuilder::get() {
    return camera_ptr;
}
