#pragma once

#include <scene/scene.h>
#include <managers/base_manager.h>

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;
    ~SceneManager() = default;

    [[nodiscard]] std::shared_ptr<Scene> get_scene() const;
    [[nodiscard]] std::shared_ptr<Camera> get_cam() const;

    void set_scene(std::shared_ptr<Scene> scene_);
    void set_cam(const std::size_t &cam_numb);

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> current_cam;
};
