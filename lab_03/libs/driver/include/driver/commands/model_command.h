#pragma once

#include <cstddef>
#include <memory>

#include <commands/base_command.h>


class ModelBaseCommand : public BaseCommand {};

class MoveModel : public ModelBaseCommand {
public:
    MoveModel() = delete;
    MoveModel(const double &dx, const double &dy, const double &dz, const size_t &mnumb);
    ~MoveModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t model_numb;

    double dx, dy, dz;
};

class ScaleModel : public ModelBaseCommand {
public:
    ScaleModel() = delete;
    ScaleModel(const double &kx, const double &ky, const double &kz, const std::size_t &mnumb);
    ~ScaleModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t model_numb;

    double kx, ky, kz;
};

class RotateModel : public ModelBaseCommand {
public:
    RotateModel() = delete;
    RotateModel(const double &ox, const double &oy, const double &oz, const std::size_t &mnumb);
    ~RotateModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t model_numb;

    double ox, oy, oz;
};

class ReformModel : public ModelBaseCommand
{
public:
    ReformModel() = delete;
    ReformModel(const size_t &numb, const Point &move, const Point &scale, const Point &turn);
    ~ReformModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t model_numb;

    Point move, scale, turn;
};

class LoadModel : public ModelBaseCommand
{
public:
    LoadModel() = delete;
    explicit LoadModel(std::string fname);
    ~LoadModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    std::string fname;
};

class AddModel : public ModelBaseCommand
{
public:
    AddModel() = delete;
    explicit AddModel(std::shared_ptr<Object> model);
    ~AddModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    std::shared_ptr<Object> model;
};

class RemoveModel : public ModelBaseCommand
{
public:
    RemoveModel() = delete;
    explicit RemoveModel(const size_t &model_numb);
    ~RemoveModel() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t model_numb;
};
