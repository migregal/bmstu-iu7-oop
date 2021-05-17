#pragma once

#include <builder/base_builder.h>
#include <objects/model/model.h>

class ModelBuilder : public BaseBuilder {
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    [[nodiscard]] bool is_build() const override;
    void build() override;
    void build_point(const double &x, const double &y, const double &z);
    void build_edge(const std::size_t &pt1, const std::size_t &pt2);

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Model> model_ptr;
};