#include <managers/load_manager.h>

#include <load_controller/model_load_controller.h>
#include <loader/file_model_loader.h>
#include <utility>

LoadManager::LoadManager() {
    std::shared_ptr<BaseModelLoader> floader(new FileModelLoader);
    loader = std::shared_ptr<AbstractLoadController>(new ModelLoadController(floader));
}

std::shared_ptr<LoadManager> LoadManager::instance() {
    static std::shared_ptr<LoadManager> _manager(new LoadManager());
    return _manager;
}

void LoadManager::set_loader(std::shared_ptr<AbstractLoadController> _loader) { loader = std::move(_loader); }

std::shared_ptr<Object> LoadManager::load(std::string &name) {
    return loader->load(name);
}
