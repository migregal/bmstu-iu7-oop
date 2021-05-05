#pragma once

#include <object.h>
#include <objects/model.h>

class Composite : public Object {
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &component);
    explicit Composite(const Vector<std::shared_ptr<Object>>& vector);

    [[nodiscard]] std::size_t size() const;

    bool add(const std::shared_ptr<Object> &component) override;
    bool remove(const Iterator<std::shared_ptr<Object>> &iterator) override;

    Iterator<std::shared_ptr<Object>> begin() override;
    Iterator<std::shared_ptr<Object>> end() override;

    [[nodiscard]] bool is_composite() const override;
    void reform(const Point &move, const Point &scale, const Point &turn) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Vector<std::shared_ptr<Object>> &get_objects() { return objects; };

private:
    Vector<std::shared_ptr<Object>> objects;
};