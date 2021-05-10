#pragma once

#include <commands/base_command.h>

class CameraBaseCommand : public BaseCommand {};

class AddCamera : public CameraBaseCommand
{
public:
    AddCamera() = delete;
    AddCamera(const double x, const double y, const double z);
    ~AddCamera() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    double x_pos;
    double y_pos;
    double z_pos;
};

class RemoveCamera : public CameraBaseCommand
{
public:
    RemoveCamera() = delete;
    explicit RemoveCamera(const size_t &camera_numb);
    ~RemoveCamera() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t camera_numb;
};

class MoveCamera : public CameraBaseCommand
{
public:
    MoveCamera() = delete;
    MoveCamera(const size_t &cam_number, const double &shift_ox, const double &shift_oy);
    ~MoveCamera() override = default;

    void execute(std::shared_ptr<AbstractFacade> &facade) override;

private:
    size_t cam_number;

    double shift_ox;
    double shift_oy;
};