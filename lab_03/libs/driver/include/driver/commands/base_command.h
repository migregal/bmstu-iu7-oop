#pragma once

#include <controller/base_controller.h>

class BaseCommand {
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;
    virtual void execute(std::shared_ptr<AbstractController> &controller) = 0;
};