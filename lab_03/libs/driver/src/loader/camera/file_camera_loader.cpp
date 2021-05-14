#include <loader/camera/file_camera_loader.h>

#include <builder/scene/scene_builder.h>
#include <error.h>
#include <error/error.h>


FileCameraLoader::FileCameraLoader() : file(std::make_shared<std::ifstream>()) {}

FileCameraLoader::FileCameraLoader(std::shared_ptr<std::ifstream> &fin) {
    file = fin;
}

std::shared_ptr<Object> FileCameraLoader::load(const std::shared_ptr<CameraBuilder> &builder) {
    builder->build();

    double x, y, z;
    *file >> x >> y >> z;

    builder->build_position(x, y, z);

    return builder->get();
}

void FileCameraLoader::open(std::string &fname) {
    if (!file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }
    file->open(fname);

    if (!file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }
}

void FileCameraLoader::close() {
    if (!file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }

    try {
        file->close();
    } catch (std::ifstream::failure &error) {
        error.what();
    }
}