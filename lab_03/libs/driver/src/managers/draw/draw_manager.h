#pragma once

#include <memory>

#include <drawer/abstract_drawer.h>
#include <managers/base_manager.h>
#include <objects/camera/camera.h>
#include <objects/model/model.h>
#include <objects/composite/composite.h>
#include <objects/model/details/point/point.h>
#include <visitor.h>

class DrawManager : public Visitor, public BaseManager {
public:
    DrawManager() = default;
    DrawManager(const DrawManager &) = delete;
    DrawManager &operator=(const DrawManager &) = delete;
    ~DrawManager() = default;

    void visit(const Camera &cam) override;
    void visit(const Model &model) override;
    void visit(const Composite &composite) override;

    void set_drawer(std::shared_ptr<AbstractDrawer>);
    void set_cam(std::shared_ptr<Camera>);

private:

    Point proect_point(const Point &point);
    std::shared_ptr<AbstractDrawer> _drawer;
    std::shared_ptr<Camera> cam;
};
