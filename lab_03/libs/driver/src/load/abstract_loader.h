#pragma once

#include <memory>
#include <utility>

#include "base_builder.h"

class Model;
class BaseSource;

class AbstractLoader {
public:
    AbstractLoader() = default;
    ~AbstractLoader() = default;

    virtual std::shared_ptr<Model> load_model(std::string &name) = 0;
    virtual void set_loader(std::shared_ptr<BaseSource> _loader);

protected:
    std::shared_ptr<BaseSource> loader;
};
