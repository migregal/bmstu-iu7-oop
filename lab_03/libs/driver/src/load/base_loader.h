#pragma once

#include <fstream>
#include <string>

#include "base_builder.h"
#include <error.h>
#include <objects/model.h>

class BaseLoader {
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual std::shared_ptr<Model> load_model(std::shared_ptr<BaseBuilder> builder) = 0;
    virtual void fopen(std::string &fname) = 0;
    virtual void fclose() = 0;
};
