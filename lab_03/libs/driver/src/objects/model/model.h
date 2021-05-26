#pragma once

#include <memory>
#include <utility>

#include <managers/draw/draw_manager.h>

#include <objects/model/details/details.h>
#include <objects/model/details/edge/edge.h>
#include <objects/model/details/point/point.h>
#include <objects/object.h>

class Model : public VisibleObject {
    friend void DrawManager::visit(const Model &model);

public:
    Model() : _details(new ModelDetails){};
    explicit Model(std::shared_ptr<ModelDetails> details) : _details(std::move(details)){};
    Model(const Model &model);
    ~Model() override = default;

    void reform(const Point &move, const Point &scale, const Point &rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

protected:
    [[nodiscard]] const std::shared_ptr<ModelDetails> get_details() const { return _details; };

private:
    std::shared_ptr<ModelDetails> _details;
};