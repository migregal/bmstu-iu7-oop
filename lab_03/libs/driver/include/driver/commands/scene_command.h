#pragma once


#include <memory>

#include <base_drawer.h>
#include <commands/base_command.h>


class SceneBaseCommand : public BaseCommand {};


class DrawScene : public SceneBaseCommand {
public:
    DrawScene() = delete;
    explicit DrawScene(std::shared_ptr<BaseDrawer> drawer);
    ~DrawScene() override = default;

    void execute() override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};
