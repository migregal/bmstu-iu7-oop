#pragma once

#include <loader/base_model_loader.h>

class FileModelLoader : public BaseModelLoader {
public:
    FileModelLoader() = default;
    ~FileModelLoader() override = default;
    std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) override;
    void open(std::string &fname) override;
    void close() override;

protected:
    std::ifstream file;
};
