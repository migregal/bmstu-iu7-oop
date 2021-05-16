#include <managers/load/load_manager.h>

#include <load_controller/model/model_load_controller.h>
#include <load_controller/scene/scene_load_controller_creator.h>
#include <loader/model/file_model_loader.h>
#include <utility>

LoadManager::LoadManager() {
    loader = SceneLoadControllerCreator().create_controller();
}

void LoadManager::set_loader(std::shared_ptr<AbstractLoadController> _loader) { loader = std::move(_loader); }

std::shared_ptr<Object> LoadManager::load(std::string &name) {
    return loader->load(name);
}
