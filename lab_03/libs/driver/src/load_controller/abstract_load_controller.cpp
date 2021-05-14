#include <load_controller/abstract_load_controller.h>

void AbstractLoadController::set_loader(std::shared_ptr<BaseLoader> _loader) {
    loader = std::move(_loader);
}
