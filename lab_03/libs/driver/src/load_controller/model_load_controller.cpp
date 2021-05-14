#include <error.h>
#include <load_controller/model_load_controller.h>

std::shared_ptr<Object> ModelLoadController::load(std::string &fname) {
    try {
        loader->open(fname);
    } catch (SourceError &error) {
        throw SourceError((std::string &) "can't open source");
    }

    std::shared_ptr<Object> model;
    try {
        model = loader->load(builder);
    } catch (std::exception &error) {
        throw SourceError((std::string &) "can't read model");
    }

    loader->close();

    return model;
}