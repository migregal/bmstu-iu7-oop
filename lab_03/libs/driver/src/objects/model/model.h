#pragma once

#include <memory>
#include <utility>

#include <visitor.h>

#include <objects/model/details/details.h>
#include <objects/model/details/edge/edge.h>
#include <objects/model/details/point/point.h>
#include <objects/object.h>

class Model : public VisibleObject {
public:
    Model() : _details(new ModelDetails){};
    explicit Model(std::shared_ptr<ModelDetails> details) : _details(std::move(details)){};
    Model(const Model &model);
    ~Model() override = default;

    std::unique_ptr<Model> clone();

    [[nodiscard]] const std::shared_ptr<ModelDetails> get_details() const { return _details; };
    void add_point(const Point &point);
    void add_link(const Edge &edge);

    void reform(const Point &move, const Point &scale, const Point &rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    std::shared_ptr<ModelDetails> _details;
};