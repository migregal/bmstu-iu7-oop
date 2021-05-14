#include <managers/load/load_manager_creator.h>

std::shared_ptr<LoadManager> LoadManagerCreator::create_manager() {
    if (nullptr == _manager)
        create_instance();

    return _manager;
}

void LoadManagerCreator::create_instance() {
    static std::shared_ptr<LoadManager> manager(new LoadManager());

    _manager = manager;
}
