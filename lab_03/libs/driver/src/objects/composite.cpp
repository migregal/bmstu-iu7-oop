#include <objects/composite.h>

Composite::Composite(std::shared_ptr<Object> &component) {
    objects.push_back(component);
}

Composite::Composite(const Vector<std::shared_ptr<Object>> &vector) {
    objects = vector;
}

bool Composite::add(const std::shared_ptr<Object> &component) {
    objects.push_back(component);
    return true;
}

bool Composite::remove(const Iterator<std::shared_ptr<Object>> &iterator) {
    objects.remove(iterator);
    return true;
}

Iterator<std::shared_ptr<Object>> Composite::begin() {
    return objects.begin();
}

Iterator<std::shared_ptr<Object>> Composite::end() {
    return objects.end();
}

bool Composite::is_composite() const {
    return true;
}

size_t Composite::size() const {
    return objects.get_size();
}

void Composite::reform(const Point &move, const Point &scale, const Point &turn) {
    for (const auto &elem : objects) {
        elem->reform(move, scale, turn);
    }
}

void Composite::accept(std::shared_ptr<Visitor> visitor) {
    for (const auto &obj : objects) {
        obj->accept(visitor);
    }
}