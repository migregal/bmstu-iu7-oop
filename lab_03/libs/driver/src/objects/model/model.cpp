#include <objects/model/model.h>

#include <memory>

Model::Model(const Model &_model) {
    _details = _model.get_details();
}

void Model::reform(const Point &move_coeff, const Point &scale_coeff, const Point &turn_coeff) {
    _details->reform(move_coeff, scale_coeff, turn_coeff);
}

void Model::accept(std::shared_ptr<Visitor> _visitor) {
    _visitor->visit(*this);
}