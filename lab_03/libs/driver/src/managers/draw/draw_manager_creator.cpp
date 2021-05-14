#include <managers/draw/draw_manager_creator.h>

std::shared_ptr<DrawManager> DrawManagerCreator::create_manager() {
    if (nullptr == _manager)
        create_instance();

    return _manager;
}

void DrawManagerCreator::create_instance() {
    static std::shared_ptr<DrawManager> manager(new DrawManager());

    _manager = manager;
}
