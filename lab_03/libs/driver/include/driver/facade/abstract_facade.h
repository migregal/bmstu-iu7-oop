#pragma once

#include <load/base_loader.h>
#include <managers/draw_manager.h>
#include <managers/scene_manager.h>
#include <managers/reform_manager.h>
#include <managers/load_manager.h>

class AbstractFacade {
public:
    AbstractFacade() = default;
    AbstractFacade(const AbstractFacade &) = default;
    AbstractFacade &operator=(const AbstractFacade &) = delete;

    virtual ~AbstractFacade() = default;

    virtual void load_model(std::string fname) = 0;
    virtual void add_model(const std::shared_ptr<Object> &) = 0;
    virtual void remove_model(const size_t &index) = 0;

    virtual void add_camera(const Point &cam_pos) = 0;
    virtual void remove_camera(const size_t &index) = 0;
    virtual void set_camera(const size_t &camera_numb) = 0;

    virtual void draw_scene(const std::shared_ptr<BaseDrawer>& _drawer) = 0;

    virtual void reform_model(const size_t &model_numb, const Point &move, const Point &scale, const Point &turn) = 0;
    virtual void reform_cam(const size_t &cam_numb, const Point &shift) = 0;

    virtual size_t cams_count() = 0;
    virtual size_t models_count() = 0;
};

