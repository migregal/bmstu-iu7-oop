#include <managers/load_manager.h>

#include <load/file_loader.h>
#include <load/model_loader.h>
#include <utility>

LoadManager::LoadManager() {
    std::shared_ptr<BaseLoader> floader(new FileLoader);
    loader = std::shared_ptr<AbstractLoader>(new ModelLoader(floader));
}

std::shared_ptr<LoadManager> LoadManager::instance() {
    static std::shared_ptr<LoadManager> _manager(new LoadManager());
    return _manager;
}

void LoadManager::set_loader(std::shared_ptr<AbstractLoader> _loader) { loader = std::move(_loader); }

std::shared_ptr<Model> LoadManager::load_model(std::string &name) {
    return loader->load_model(name);
}
