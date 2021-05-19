#include <load_controller/abstract_load_controller.h>

void Load::AbstractLoadController::set_loader(std::shared_ptr<Load::BaseLoader> _loader) {
    loader = std::move(_loader);
}
