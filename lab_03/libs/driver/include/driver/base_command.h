#pragma once

#include <facade/facade.h>

class BaseCommand {
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;
    virtual void execute(std::shared_ptr<Facade> &facade) = 0;
};