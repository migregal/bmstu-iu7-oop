#include <managers/load_manager.h>

#include <utility>

void LoadManager::set_loader(std::shared_ptr<AbstractLoader> _loader) { loader = std::move(_loader); }

std::shared_ptr<Model> LoadManager::load_model(std::string &name) {
    loader->load_model(name);
}
