#pragma once

#include <objects/object.h>
#include <visitor.h>

class Camera : public InvisibleObject
{
public:
    Camera() = default;
    explicit Camera(const Point &pos) : current_pos(pos) {};
    ~Camera() override = default;

    void reform(const Point &pos, const Point &turn, const Point &scale) override;
    void accept(std::shared_ptr<Visitor> visitor) override;
    Point get_pos() { return current_pos; };

    void move_x(const double &shift);
    void move_y(const double &shift);
    void move_z(const double &shift);

private:
    Point current_pos;
};
