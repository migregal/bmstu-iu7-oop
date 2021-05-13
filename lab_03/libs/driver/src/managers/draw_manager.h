#pragma once

#include <memory>

#include <base_drawer.h>
#include <managers/base_manager.h>
#include <objects/camera.h>
#include <objects/composite.h>
#include <objects/point.h>
#include <visitor.h>

class DrawManager : public Visitor, public BaseManager {
public:
    ~DrawManager() = default;

    static std::shared_ptr<DrawManager> instance();

    void visit(const Camera &cam) override;
    void visit(const Model &model) override;
    void visit(const Composite &composite) override;

    void set_drawer(std::shared_ptr<BaseDrawer>);
    void set_cam(std::shared_ptr<Camera>);

private:
    DrawManager() = default;

    Point proect_point(const Point &point);
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> cam;
};
