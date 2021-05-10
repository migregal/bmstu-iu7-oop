#pragma once

#include <facade/abstract_facade.h>

class AbstractFacadeCreator {
public:
    virtual std::shared_ptr<AbstractFacade> createFacade() = 0;
};