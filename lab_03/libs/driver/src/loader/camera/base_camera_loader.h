#pragma once

#include <builder/camera/camera_builder.h>
#include <loader/base_loader.h>

class BaseCameraLoader : public BaseLoader {
public:
    virtual std::shared_ptr<Object> load(const std::shared_ptr<CameraBuilder>& builder) = 0;
};