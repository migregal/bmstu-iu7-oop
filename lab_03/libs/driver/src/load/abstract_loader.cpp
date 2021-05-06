#include <load/abstract_loader.h>

void AbstractLoader::set_loader(std::shared_ptr<BaseLoader> _loader) {
    loader = std::move(_loader);
}
