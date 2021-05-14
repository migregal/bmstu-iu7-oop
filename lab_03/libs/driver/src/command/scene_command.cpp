#include <commands/scene_command.h>

#include <load_controller/scene/scene_load_controller.h>
#include <loader/scene/file_scene_loader.h>
#include <managers/draw_manager.h>
#include <managers/load_manager.h>
#include <managers/scene_manager.h>
#include <utility>

DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(std::move(drawer)) {
}

void DrawScene::execute() {
    auto _draw_manager = DrawManager::instance();
    auto _scene_manager = SceneManager::instance();

    _drawer->clear_scene();
    _draw_manager->set_drawer(_drawer);
    _draw_manager->set_cam(_scene_manager->get_cam());
    _scene_manager->get_scene()->get_composite()->accept(_draw_manager);
}

LoadScene::LoadScene(std::string fname): _fname(std::move(fname)) {}

void LoadScene::execute() {
    auto manager = LoadManager::instance();
    std::shared_ptr<BaseSceneLoader> floader(new FileSceneLoader);
    manager->set_loader(std::shared_ptr<AbstractLoadController>(new SceneLoadController(floader)));
    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_fname));
    SceneManager::instance()->set_scene(scene);
}
