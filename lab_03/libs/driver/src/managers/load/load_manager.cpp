#include <managers/load/load_manager.h>

#include <load_controller/model/model_load_controller.h>
#include <loader/model/file_model_loader.h>
#include <utility>

LoadManager::LoadManager() {
    std::shared_ptr<BaseModelLoader> floader(new FileModelLoader);
    loader = std::shared_ptr<AbstractLoadController>(new ModelLoadController(floader));
}

void LoadManager::set_loader(std::shared_ptr<AbstractLoadController> _loader) { loader = std::move(_loader); }

std::shared_ptr<Object> LoadManager::load(std::string &name) {
    return loader->load(name);
}
