#include <load_controller/scene/scene_load_controller.h>

#include <error.h>

std::shared_ptr<Object> SceneLoadController::load(std::string &fname) {
    try {
        loader->open(fname);
    } catch (SourceError &error) {
        throw SourceError((std::string &) "can't open source");
    }

    std::shared_ptr<Object> scene;
    try {
        scene = loader->load(builder);
    } catch (std::exception &error) {
        throw SourceError((std::string &) "can't read model");
    }

    loader->close();

    return scene;
}
