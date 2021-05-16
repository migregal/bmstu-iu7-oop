#include <commands/model_command.h>

#include <load_controller/model/model_load_controller_creator.h>
#include <managers/load/load_manager_creator.h>
#include <managers/reform/reform_manager_creator.h>
#include <managers/scene/scene_manager_creator.h>
#include <utility>

#define cd const double

MoveModel::MoveModel(cd &dx, cd &dy, cd &dz, const std::size_t &mnumb) : dx(dx), dy(dy), dz(dz), model_numb(mnumb) {}

void MoveModel::execute() {
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point turn(0, 0, 0);

    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->get_models().at(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

ScaleModel::ScaleModel(cd &kx, cd &ky, cd &kz, const std::size_t &mnumb) : kx(kx), ky(ky), kz(kz), model_numb(mnumb) {}

void ScaleModel::execute() {
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point turn(0, 0, 0);

    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->get_models().at(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

RotateModel::RotateModel(cd &ox, cd &oy, cd &oz, const std::size_t &mnumb) : ox(ox), oy(oy), oz(oz), model_numb(mnumb) {}

void RotateModel::execute() {
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point turn(ox, oy, oz);

    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->get_models().at(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

ReformModel::ReformModel(const std::size_t &numb, const Point &move, const Point &scale, const Point &turn) : model_numb(numb), move(move), scale(scale), turn(turn) {}

void ReformModel::execute() {
    std::shared_ptr<Object> model = SceneManagerCreator().create_manager()->get_scene()->get_models().at(model_numb);
    ReformManagerCreator().create_manager()->reform_object(model, move, scale, turn);
}

LoadModel::LoadModel(std::string fname) : fname(std::move(fname)) {}

void LoadModel::execute() {
    auto controller = ModelLoadControllerCreator().create_controller();
    auto manager = LoadManagerCreator().create_manager(controller);

    auto model = manager->load(fname);
    SceneManagerCreator().create_manager()->get_scene()->add_model(model);
}

AddModel::AddModel(std::shared_ptr<Object> model) : model(std::move(model)) {}

void AddModel::execute() {
    SceneManagerCreator().create_manager()->get_scene()->add_model(model);
}

RemoveModel::RemoveModel(const std::size_t &model_numb) : model_numb(model_numb) {}

void RemoveModel::execute() {
    SceneManagerCreator().create_manager()->get_scene()->remove_model(model_numb);
}

ModelCount::ModelCount(std::shared_ptr<size_t> &count) : _count(count) {}

void ModelCount::execute() {
    (*_count) = SceneManagerCreator().create_manager()->get_scene()->get_models().size();
}
