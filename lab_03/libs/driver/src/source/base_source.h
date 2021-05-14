#pragma once

#include <fstream>
#include <string>

#include "load/base_builder.h"
#include <error.h>
#include <objects/model.h>

class BaseSource {
public:
    BaseSource() = default;
    virtual ~BaseSource() = default;

    virtual std::shared_ptr<Model> load_model(std::shared_ptr<BaseBuilder> builder) = 0;
    virtual void fopen(std::string &fname) = 0;
    virtual void fclose() = 0;
};
