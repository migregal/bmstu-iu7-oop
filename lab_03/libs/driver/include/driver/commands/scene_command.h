#pragma once


#include <memory>

#include <commands/base_command.h>
#include <drawer/abstract_drawer.h>


class SceneBaseCommand : public BaseCommand {};


class DrawScene : public SceneBaseCommand {
public:
    DrawScene() = delete;
    explicit DrawScene(std::shared_ptr<AbstractDrawer> drawer);
    ~DrawScene() override = default;

    void execute() override;

private:
    std::shared_ptr<AbstractDrawer> _drawer;
};

class LoadScene : public SceneBaseCommand {
public:
    LoadScene() = delete;
    explicit LoadScene(std::string fname);
    ~LoadScene() override = default;

    void execute() override;

private:
    std::string _fname;
};

class ExportScene : public SceneBaseCommand {
public:
    ExportScene() = delete;
    explicit ExportScene(std::string fname);
    ~ExportScene() override = default;

    void execute() override;

private:
    std::string _fname;
};
