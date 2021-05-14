#pragma once

#include <loader/camera/base_camera_loader.h>

class FileCameraLoader : public BaseCameraLoader {
public:
    FileCameraLoader();
    explicit FileCameraLoader(std::shared_ptr<std::ifstream> &fin);
    ~FileCameraLoader() override = default;
    std::shared_ptr<Object> load(const std::shared_ptr<CameraBuilder> &builder) override;

    void open(std::string &fname) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> file;
};