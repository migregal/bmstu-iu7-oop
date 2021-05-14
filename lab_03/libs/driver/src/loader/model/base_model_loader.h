#pragma once

#include <builder/model/model_builder.h>
#include <loader/base_loader.h>

class BaseModelLoader : public BaseLoader {
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) = 0;
};