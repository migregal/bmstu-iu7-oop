#pragma once

#include <builder/model/model_builder.h>
#include <load_controller/abstract_load_controller.h>
#include <loader/base_loader.h>
#include <loader/model/base_model_loader.h>
#include <utility>

class ModelLoadController : public AbstractLoadController {
public:
    explicit ModelLoadController(std::shared_ptr<BaseModelLoader> _loader) : builder(new ModelBuilder), loader(std::move(_loader)){};
    ~ModelLoadController() = default;

    std::shared_ptr<Object> load(std::string &name) override;

private:
    std::shared_ptr<ModelBuilder> builder;
    std::shared_ptr<BaseModelLoader> loader;
};
