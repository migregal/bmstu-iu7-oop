#pragma once

#include <memory>
#include <utility>

#include <builder/base_builder.h>

class Model;
class BaseLoader;

class AbstractLoadController {
public:
    AbstractLoadController() = default;
    ~AbstractLoadController() = default;

    virtual std::shared_ptr<Object> load(std::string &name) = 0;
    virtual void set_loader(std::shared_ptr<BaseLoader> _loader);

protected:
    std::shared_ptr<BaseLoader> loader;
};
