#pragma once

#include <controller/abstract_controller_creator.h>

class BaseControllerCreator : public AbstractControllerCreator {
public:
    std::shared_ptr<AbstractController> createController() override;
};