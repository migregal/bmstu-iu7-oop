#include <commands/model_command.h>

#include <utility>

#define cd const double

MoveModel::MoveModel(cd &dx, cd &dy, cd &dz, const size_t &mnumb) : dx(dx), dy(dy), dz(dz), model_numb(mnumb) {}

void MoveModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point turn(0, 0, 0);

    facade->reform_model(model_numb, move, scale, turn);
}

ScaleModel::ScaleModel(cd &kx, cd &ky, cd &kz, const std::size_t &mnumb) : kx(kx), ky(ky), kz(kz), model_numb(mnumb) {}

void ScaleModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point turn(0, 0, 0);

    facade->reform_model(model_numb, move, scale, turn);
}

RotateModel::RotateModel(cd &ox, cd &oy, cd &oz, const std::size_t &mnumb) : ox(ox), oy(oy), oz(oz), model_numb(mnumb) {}

void RotateModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point turn(ox, oy, oz);

    facade->reform_model(model_numb, move, scale, turn);
}

ReformModel::ReformModel(const size_t &numb, const Point &move, const Point &scale, const Point &turn) :
        model_numb(numb), move(move), scale(scale), turn(turn) {}

void ReformModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    facade->reform_model(model_numb, move, scale, turn);
}

LoadModel::LoadModel(std::string fname) : fname(std::move(fname)) {}

void LoadModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    facade->load_model(fname);
}

AddModel::AddModel(std::shared_ptr<Object> model) : model(std::move(model)) {}

void AddModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    facade->add_model(model);
}

RemoveModel::RemoveModel(const size_t &model_numb) : model_numb(model_numb) {}

void RemoveModel::execute(std::shared_ptr<AbstractFacade> &facade) {
    facade->remove_model(model_numb);
}
