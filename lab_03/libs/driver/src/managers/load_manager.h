#pragma once

#include <memory>

#include <load/abstract_loader.h>
#include <load/base_loader.h>
#include <managers/base_manager.h>
#include <objects/model.h>

class LoadManager : public BaseManager {
public:
    ~LoadManager() = default;

    static std::shared_ptr<LoadManager> instance();

    virtual std::shared_ptr<Model> load_model(std::string &name);
    virtual void set_loader(std::shared_ptr<AbstractLoader> _loader);

private:
    LoadManager();

    std::shared_ptr<AbstractLoader> loader;
};
