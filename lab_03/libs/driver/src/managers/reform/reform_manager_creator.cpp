#include <managers/reform/reform_manager_creator.h>

std::shared_ptr<ReformManager> ReformManagerCreator::create_manager() {
    if (nullptr == _manager)
        create_instance();

    return _manager;
}

void ReformManagerCreator::create_instance() {
    static std::shared_ptr<ReformManager> manager(new ReformManager());

    _manager = manager;
}
