#pragma once


#include <memory>

#include <commands/base_command.h>
#include <drawer.h>


class SceneBaseCommand : public BaseCommand {};


class DrawScene : public SceneBaseCommand {
public:
    DrawScene() = delete;
    explicit DrawScene(std::shared_ptr<BaseDrawer> drawer);
    ~DrawScene() override = default;

    void execute(std::shared_ptr<AbstractController> &facade) override;

private:
    std::shared_ptr<BaseDrawer> _drawer;
};
