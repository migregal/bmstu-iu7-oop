#include <facade/facade.h>

#include <controller/base_controller_creator.h>

Facade::Facade() {
    _controller = std::shared_ptr<AbstractController>(BaseControllerCreator().createController());
}

void Facade::execute(BaseCommand &cmd) {
    cmd.execute(_controller);
}
