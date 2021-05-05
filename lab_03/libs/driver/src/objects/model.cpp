#include <objects/model.h>

#include <memory>

Model::Model(const Model &_model) {
    this->_details = _model.get_details();
}

std::unique_ptr<Model> Model::clone() {
    return std::make_unique<Model>(*this);
}

void Model::add_point(const Point &point) {
    this->_details->add_point(point);
}

void Model::add_link(const Edge &edge) {
    this->_details->add_edge(edge);
}

void Model::reform(const Point &move_coeff, const Point &scale_coeff, const Point &turn_coeff) {
    this->_details->reform(move_coeff, scale_coeff, turn_coeff);
}

void Model::accept(std::shared_ptr<Visitor> _visitor) {
    _visitor->visit(*this);
}