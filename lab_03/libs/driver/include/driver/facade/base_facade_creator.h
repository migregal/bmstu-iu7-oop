#pragma once

#include <facade/abstract_facade_creator.h>

class BaseFacadeCreator : public AbstractFacadeCreator {
public:
    std::shared_ptr<AbstractFacade> createFacade() override;
};