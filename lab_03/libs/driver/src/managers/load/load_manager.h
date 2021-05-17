#pragma once

#include <memory>

#include <load_controller//abstract_load_controller.h>
#include <loader/base_loader.h>
#include <managers/base_manager.h>
#include <objects/model/model.h>

class LoadManager : public BaseManager {
public:
    LoadManager();
    LoadManager(const LoadManager&) = delete;
    LoadManager& operator=(const LoadManager&) = delete;
    ~LoadManager() = default;

    virtual std::shared_ptr<Object> load(std::string &name);
    virtual void set_loader(std::shared_ptr<AbstractLoadController> _loader);

private:
    std::shared_ptr<AbstractLoadController> loader;
};
