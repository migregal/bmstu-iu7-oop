#pragma once

#include <load/abstract_loader.h>
#include <load/model_builder.h>
#include <load/base_loader.h>
#include <utility>

class ModelLoader : public AbstractLoader {
public:
    explicit ModelLoader(std::shared_ptr<BaseLoader> _loader) : builder(new ModelBuilder), loader(std::move(_loader)){};
    ~ModelLoader() = default;

    std::shared_ptr<Model> load_model(std::string &name) override;

private:
    std::shared_ptr<BaseBuilder> builder;
    std::shared_ptr<BaseLoader> loader;
};
