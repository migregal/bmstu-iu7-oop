#include <load/file_loader.h>

std::shared_ptr<Model> FileLoader::load_model(std::shared_ptr<BaseBuilder> builder) {
    builder->build();

    size_t points_count;
    file >> points_count;

    for (size_t i = 0; i < points_count; i++) {
        double x, y, z;
        file >> x >> y >> z;
        builder->build_point(x, y, z);
    }

    size_t links_count;
    file >> links_count;

    for (size_t i = 0; i < links_count; i++) {
        size_t pt1, pt2;
        this->file >> pt1 >> pt2;
        builder->build_link(pt1, pt2);
    }

    return builder->get();
}

void FileLoader::fopen(std::string &fname) {
    file.open(fname);

    if (!this->file) {
        std::string message = "Error while open file.";
        throw FileError(message);
    }
}

void FileLoader::fclose() {
    try {
        file.close();
    } catch (std::ifstream::failure &error) {
        error.what();
    }
}