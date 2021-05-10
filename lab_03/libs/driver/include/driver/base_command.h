#pragma once

#include <facade/base_facade.h>

class BaseCommand {
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;
    virtual void execute(std::shared_ptr<AbstractFacade> &facade) = 0;
};