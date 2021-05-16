#include <load_controller/model/model_load_controller_creator.h>

#include <memory>

#include <configuration/configuration_creator.h>
#include <loader/model/file_model_loader.h>

std::shared_ptr<ModelLoadController> ModelLoadControllerCreator::create_controller() {
    if (nullptr == _controller)
        create_instance();

    return _controller;
}

std::shared_ptr<ModelLoadController> ModelLoadControllerCreator::create_controller(const std::shared_ptr<BaseModelLoader> &loader) {
    if (nullptr == _controller)
        create_instance();

    _controller->set_loader(loader);

    return _controller;
}

void ModelLoadControllerCreator::create_instance() {
    static std::shared_ptr<ModelLoadController> controller;

    if (!controller) {
        std::shared_ptr<BaseModelLoader> loader;

        switch (ConfigurationCreator().get_configuration()->get_load_source()) {
            case AbstractConfiguration::FILE:
            default:
                loader = std::shared_ptr<BaseModelLoader>(new FileModelLoader);
        }

        controller = std::make_shared<ModelLoadController>(loader);
    }

    _controller = controller;
}

