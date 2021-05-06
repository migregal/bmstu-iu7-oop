#pragma once

#include <load/base_loader.h>

class FileLoader : public BaseLoader {
public:
    FileLoader() = default;
    ~FileLoader() override = default;

    std::shared_ptr<Model> load_model(std::shared_ptr<BaseBuilder> builder) override;
    void fopen(std::string &fname) override;
    void fclose() override;

protected:
    std::ifstream file;
};
