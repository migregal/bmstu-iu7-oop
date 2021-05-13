#pragma once

#include <memory>

#include <commands/base_command.h>

class Facade {
public:
    void execute(BaseCommand &cmd);
};