#pragma once

#include <facade/abstract_facade.h>
#include <load/base_loader.h>
#include <managers/draw_manager.h>
#include <managers/load_manager.h>
#include <managers/reform_manager.h>
#include <managers/scene_manager.h>

class BaseFacade : public AbstractFacade {
public:
    BaseFacade();
    BaseFacade(const BaseFacade &) = delete;
    BaseFacade &operator=(const BaseFacade &) = delete;

    ~BaseFacade() override = default;

    void load_model(std::string fname) override;
    void add_model(const std::shared_ptr<Object> &) override;
    void remove_model(const size_t &index) override;

    void add_camera(const Point &cam_pos) override;
    void remove_camera(const size_t &index) override;
    void set_camera(const size_t &camera_numb) override;

    void draw_scene(const std::shared_ptr<BaseDrawer> &_drawer) override;

    void reform_model(const size_t &model_numb, const Point &move, const Point &scale, const Point &turn) override;
    void reform_cam(const size_t &cam_numb, const Point &shift) override;

    size_t cams_count() override;
    size_t models_count() override;

private:
    SceneManager _scene_manager;
    std::shared_ptr<LoadManager> _load_manager;
    std::shared_ptr<DrawManager> _draw_manager;
};
