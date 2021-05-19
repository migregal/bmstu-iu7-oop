#include <builder/load/model/model_builder.h>

bool Load::ModelBuilder::is_build() const {
    return nullptr != model_ptr;
}

void Load::ModelBuilder::build() {
    model_ptr = std::make_shared<ModelDetails>();
}

void Load::ModelBuilder::build_point(const double &x, const double &y, const double &z) {
    if (!is_build()) {}

    Point pt_obj(x, y, z);
    model_ptr->add_point(pt_obj);
}

void Load::ModelBuilder::build_edge(const std::size_t &pt1, const std::size_t &pt2) {
    if (!is_build()) {}

    Edge edge_obj(pt1, pt2);
    model_ptr->add_edge(edge_obj);
}

std::shared_ptr<Object> Load::ModelBuilder::get() {
    return std::make_shared<Model>(Model(model_ptr));
}