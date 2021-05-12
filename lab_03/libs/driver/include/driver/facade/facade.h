#pragma once

#include <memory>

#include <commands/base_command.h>

#include <controller/abstract_controller.h>

class Facade {
public:
    Facade();

    void execute(BaseCommand &cmd);

private:
    std::shared_ptr<AbstractController> _controller;
};