#pragma once

#include <source/base_source.h>

class FileSource : public BaseSource {
public:
    FileSource() = default;
    ~FileSource() override = default;

    std::shared_ptr<Model> load_model(std::shared_ptr<BaseBuilder> builder) override;
    void fopen(std::string &fname) override;
    void fclose() override;

protected:
    std::ifstream file;
};
