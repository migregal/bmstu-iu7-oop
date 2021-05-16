#include <loader/scene/file_scene_loader.h>

#include <builder/scene/scene_builder.h>
#include <error.h>
#include <error/error.h>
#include <loader/camera/file_camera_loader.h>
#include <loader/model/file_model_loader.h>

FileSceneLoader::FileSceneLoader() : file(std::make_shared<std::ifstream>()) {}

std::shared_ptr<Object> FileSceneLoader::load(const std::shared_ptr<SceneBuilder> &builder) {
    builder->build();

    load_models(builder);

    load_cameras(builder);

    return builder->get();
}

void FileSceneLoader::open(std::string &fname) {
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

void FileSceneLoader::close() {
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

void FileSceneLoader::load_models(std::shared_ptr<SceneBuilder> builder) {
    std::size_t models_count;
    *file >> models_count;

    auto m_builder = std::make_shared<ModelBuilder>();
    for (size_t i = 0; i < models_count; ++i)
        builder->build_model(FileModelLoader(file).load(m_builder));
}

void FileSceneLoader::load_cameras(std::shared_ptr<SceneBuilder> builder) {
    std::size_t cameras_count;
    *file >> cameras_count;

    auto c_builder = std::make_shared<CameraBuilder>();
    for (size_t i = 0; i < cameras_count; ++i) {
        auto camera = std::dynamic_pointer_cast<Camera>(FileCameraLoader(file).load(c_builder));
        builder->build_camera(camera);
    }
}
