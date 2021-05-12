#include <controller/base_controller.h>
#include <controller/base_controller_creator.h>


std::shared_ptr<AbstractController> BaseControllerCreator::createController() {
    static std::shared_ptr<AbstractController> _facade(new BaseController());

    return _facade;
}
