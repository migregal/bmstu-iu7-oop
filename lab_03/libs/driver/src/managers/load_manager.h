#pragma once

#include <memory>

#include <load_controller//abstract_load_controller.h>
#include <managers/base_manager.h>
#include <objects/model.h>
#include <loader/base_loader.h>

class LoadManager : public BaseManager {
public:
    LoadManager(const LoadManager&) = default;
    LoadManager& operator=(const LoadManager&) = delete;
    ~LoadManager() = default;

    static std::shared_ptr<LoadManager> instance();

    virtual std::shared_ptr<Object> load(std::string &name);
    virtual void set_loader(std::shared_ptr<AbstractLoadController> _loader);

private:
    LoadManager();

    std::shared_ptr<AbstractLoadController> loader;
};
