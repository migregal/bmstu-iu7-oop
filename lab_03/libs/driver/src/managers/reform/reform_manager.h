#pragma once

#include <managers/base_manager.h>
#include <objects/object.h>

class ReformManager : public BaseManager {
public:
    ReformManager() = default;
    ReformManager(const ReformManager &) = delete;
    ReformManager &operator=(const ReformManager &) = delete;
    ~ReformManager() = default;

    static void reform_object(const std::shared_ptr<Object> &_object, const Point &move, const Point &scale, const Point &turn);

    static void move_object(const std::shared_ptr<Object> &_object, const double &dx, const double &dy, const double &dz);
    static void scale_object(const std::shared_ptr<Object> &_object, const double &kx, const double &ky, const double &kz);
    static void turn_object(const std::shared_ptr<Object> &_object, const double &ox, const double &oy, const double &oz);
};
