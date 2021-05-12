#pragma once

#include <controller/abstract_controller.h>

class AbstractControllerCreator {
public:
    virtual std::shared_ptr<AbstractController> createController() = 0;
};