#pragma once

#include <cstddef>
#include <memory>

#include <commands/base_command.h>

class CameraBaseCommand : public BaseCommand {};

class AddCamera : public CameraBaseCommand {
public:
    AddCamera() = delete;
    AddCamera(const double x, const double y, const double z);
    ~AddCamera() override = default;

    void execute() override;

private:
    double x_pos;
    double y_pos;
    double z_pos;
};

class RemoveCamera : public CameraBaseCommand {
public:
    RemoveCamera() = delete;
    explicit RemoveCamera(const std::size_t &camera_numb);
    ~RemoveCamera() override = default;

    void execute() override;

private:
    std::size_t camera_numb;
};

class MoveCamera : public CameraBaseCommand {
public:
    MoveCamera() = delete;
    MoveCamera(const std::size_t &cam_number, const double &shift_ox, const double &shift_oy);
    ~MoveCamera() override = default;

    void execute() override;

private:
    std::size_t cam_number;

    double shift_ox;
    double shift_oy;
};

class SetCamera : public CameraBaseCommand {
public:
    SetCamera() = delete;
    explicit SetCamera(const std::size_t &cam_number);
    ~SetCamera() override = default;

    void execute() override;


private:
    std::size_t cam_number;
};

class CameraCount : public CameraBaseCommand {
public:
    CameraCount() = delete;
    explicit CameraCount(std::shared_ptr<size_t> &count);
    ~CameraCount() override = default;

    void execute() override;

private:
    std::shared_ptr<size_t> &_count;
};