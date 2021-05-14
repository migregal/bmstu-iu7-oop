#include <managers/reform/reform_manager.h>

void ReformManager::reform_object(const std::shared_ptr<Object>& _object, const Point &move, const Point &scale, const Point &turn) {
    _object->reform(move, scale, turn);
}

void ReformManager::move_object(const std::shared_ptr<Object>& _object, const double &dx, const double &dy, const double &dz) {
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point turn(0, 0, 0);

    _object->reform(move, scale, turn);
}

void ReformManager::scale_object(const std::shared_ptr<Object>& _object, const double &kx, const double &ky, const double &kz) {
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point turn(0, 0, 0);

    _object->reform(move, scale, turn);
}

void ReformManager::turn_object(const std::shared_ptr<Object>& _object, const double &ox, const double &oy, const double &oz) {
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point turn(ox, oy, oz);

    _object->reform(move, scale, turn);
}
