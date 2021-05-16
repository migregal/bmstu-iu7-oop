#include <commands/scene_command.h>

#include <load_controller/scene/scene_load_controller.h>
#include <loader/scene/file_scene_loader.h>
#include <managers/draw/draw_manager.h>
#include <managers/draw/draw_manager_creator.h>
#include <managers/load/load_manager.h>
#include <managers/load/load_manager_creator.h>
#include <managers/scene/scene_manager.h>
#include <managers/scene/scene_manager_creator.h>
#include <utility>

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(std::move(drawer)) {
}

void DrawScene::execute() {
    auto _draw_manager = DrawManagerCreator().create_manager();
    auto _scene_manager = SceneManagerCreator().create_manager();

    _drawer->clear_scene();
    _draw_manager->set_drawer(_drawer);
    _draw_manager->set_cam(_scene_manager->get_cam());
    _scene_manager->get_scene()->get_composite()->accept(_draw_manager);
}

LoadScene::LoadScene(std::string fname) : _fname(std::move(fname)) {}

void LoadScene::execute() {
    auto floader = std::shared_ptr<BaseSceneLoader>(new FileSceneLoader);
    auto controller = std::shared_ptr<AbstractLoadController>(new SceneLoadController(floader));

    auto manager = LoadManagerCreator().create_manager(controller);

    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_fname));
    SceneManagerCreator().create_manager()->set_scene(scene);
}
