#include <load/model_loader.h>

std::shared_ptr<Model> ModelLoader::load_model(std::string &fname) {
    loader->fopen(fname);
    std::shared_ptr<Model> model(loader->load_model(this->builder));
    loader->fclose();

    return model;
}