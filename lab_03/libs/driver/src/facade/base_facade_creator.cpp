#include <facade/base_facade.h>
#include <facade/base_facade_creator.h>


std::shared_ptr<AbstractFacade> BaseFacadeCreator::createFacade() {
    static std::shared_ptr<BaseFacade> _facade(new BaseFacade());

    return _facade;
}
