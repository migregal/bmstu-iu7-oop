#include <load/abstract_loader.h>

void AbstractLoader::set_loader(std::shared_ptr<BaseSource> _loader) {
    loader = std::move(_loader);
}
