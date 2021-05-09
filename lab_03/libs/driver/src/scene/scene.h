#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <objects/camera.h>
#include <objects/composite.h>

class Scene {
public:
    Scene() : models(new Composite){};
    ~Scene() = default;

    void add_model(const std::shared_ptr<Object> &model);
    void remove_model(const std::size_t model_index);

    void add_camera(const std::shared_ptr<Camera> &camera);
    void remove_camera(const std::size_t cam_index);

    std::vector<std::shared_ptr<Object>> get_models();
    std::shared_ptr<Composite> get_composite();
    std::vector<std::shared_ptr<Camera>> get_cams();

protected:
    std::shared_ptr<Composite> models;
    std::vector<std::shared_ptr<Camera>> cams;
};

#endif
