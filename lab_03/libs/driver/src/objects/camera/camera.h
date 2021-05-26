#pragma once

#include <managers/draw/draw_manager.h>
#include <objects/object.h>

class Camera : public InvisibleObject {
    friend DrawManager;

public:
    Camera() = default;
    explicit Camera(const Point &pos) : current_pos(pos){};
    ~Camera() override = default;

    void reform(const Point &pos, const Point &turn, const Point &scale) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

protected:
    Point get_pos() { return current_pos; };

private:
    void move_x(const double &shift);
    void move_y(const double &shift);
    void move_z(const double &shift);

    Point current_pos;
};
