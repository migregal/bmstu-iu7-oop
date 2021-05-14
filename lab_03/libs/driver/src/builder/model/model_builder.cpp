#include <builder/model/model_builder.h>

bool ModelBuilder::is_build() const {
    return nullptr != model_ptr;
}

void ModelBuilder::build() {
    model_ptr = std::make_shared<Model>();
}

void ModelBuilder::build_point(const double &x, const double &y, const double &z) {
    if (!is_build()) {}

    Point pt_obj(x, y, z);
    model_ptr->add_point(pt_obj);
}

void ModelBuilder::build_edge(const std::size_t &pt1, const std::size_t &pt2) {
    if (!is_build()) {}

    Edge edge_obj(pt1, pt2);
    model_ptr->add_link(edge_obj);
}

std::shared_ptr<Object> ModelBuilder::get() {
    return model_ptr;
}