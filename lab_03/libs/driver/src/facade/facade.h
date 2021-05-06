#pragma once

#include <load/base_loader.h>
#include <managers/draw_manager.h>
#include <managers/scene_manager.h>
#include <managers/reform_manager.h>
#include <managers/load_manager.h>

class Facade {
public:
    Facade(const Facade &) = delete;
    Facade &operator=(const Facade &) = delete;

    static std::shared_ptr<Facade> instance()
    {
        static std::shared_ptr<Facade> _facade(new Facade());

        return _facade;
    }

    ~Facade() = default;

    void load_model(std::string fname);
    void add_model(const std::shared_ptr<Object> &);
    void remove_model(const size_t &index);

    void add_camera(const Point &cam_pos);
    void remove_camera(const size_t &index);
    void set_camera(const size_t &camera_numb);

    void draw_scene(const std::shared_ptr<BaseDrawer>& _drawer);

    void reform_model(const size_t &model_numb, const Point &move, const Point &scale, const Point &turn);
    void reform_cam(const size_t &cam_numb, const Point &shift);

    size_t cams_count();
    size_t models_count();

private:
    Facade();

    SceneManager _scene_manager;
    std::shared_ptr<AbstractLoader> _load_manager;
    std::shared_ptr<DrawManager> _draw_manager;
};

