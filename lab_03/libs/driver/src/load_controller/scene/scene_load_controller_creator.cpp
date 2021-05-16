#include <load_controller/scene/scene_load_controller_creator.h>

#include <memory>

#include <configuration/configuration_creator.h>
#include <loader/scene/file_scene_loader.h>

std::shared_ptr<SceneLoadController> SceneLoadControllerCreator::create_controller() {
    if (nullptr == _controller)
        create_instance();

    return _controller;
}

std::shared_ptr<SceneLoadController> SceneLoadControllerCreator::create_controller(const std::shared_ptr<BaseSceneLoader> &loader) {
    if (nullptr == _controller)
        create_instance();

    _controller->set_loader(loader);

    return _controller;
}

void SceneLoadControllerCreator::create_instance() {
    static std::shared_ptr<SceneLoadController> controller;

    if (!controller) {
        std::shared_ptr<BaseSceneLoader> loader;

        switch (ConfigurationCreator().get_configuration()->get_load_source()) {
            case AbstractConfiguration::FILE:
            default:
                loader = std::shared_ptr<BaseSceneLoader>(new FileSceneLoader);
        }

        controller = std::make_shared<SceneLoadController>(loader);
    }

    _controller = controller;
}
