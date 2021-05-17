#pragma once

#include <builder/base_builder.h>
#include <objects/camera/camera.h>

class CameraBuilder : public BaseBuilder {
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    [[nodiscard]] bool is_build() const override;
    void build() override;
    void build_position(double x, double y, double z);

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Camera> camera_ptr;
};