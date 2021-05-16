#include <builder/model/model_builder.h>
#include <error.h>
#include <error/error.h>
#include <loader/model/file_model_loader.h>

FileModelLoader::FileModelLoader() : file(std::make_shared<std::ifstream>()) {}

FileModelLoader::FileModelLoader(std::shared_ptr<std::ifstream> &fin) {
    file = fin;
}

std::shared_ptr<Object> FileModelLoader::load(std::shared_ptr<ModelBuilder> builder) {
    builder->build();

    std::size_t points_count;
    *file >> points_count;

    for (std::size_t i = 0; i < points_count; i++) {
        double x, y, z;
        *file >> x >> y >> z;
        builder->build_point(x, y, z);
    }

    std::size_t links_count;
    *file >> links_count;

    for (std::size_t i = 0; i < links_count; i++) {
        std::size_t pt1, pt2;
        *file >> pt1 >> pt2;
        builder->build_edge(pt1, pt2);
    }

    return builder->get();
}

void FileModelLoader::open(std::string &fname) {
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

void FileModelLoader::close() {
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
