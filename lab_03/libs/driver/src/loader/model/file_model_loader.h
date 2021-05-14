#pragma once

#include <loader/model/base_model_loader.h>

class FileModelLoader : public BaseModelLoader {
public:
    FileModelLoader();
    explicit FileModelLoader(std::shared_ptr<std::ifstream> &fin);
    ~FileModelLoader() override = default;
    std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) override;
    void open(std::string &fname) override;
    void close() override;

protected:
    std::shared_ptr<std::ifstream> file;
};
