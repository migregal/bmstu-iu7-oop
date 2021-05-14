#pragma once

#include <loader/base_loader.h>

class BaseModelLoader : public BaseLoader {
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) = 0;
};