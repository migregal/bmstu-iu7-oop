#pragma once

#include <string>
#include <utility>

class AbstractConfiguration {
public:
    enum frames { QT };

    explicit AbstractConfiguration(std::shared_ptr<std::string> source = nullptr) : _source(std::move(source)) {};

    virtual void read_configuration(std::shared_ptr<std::string> source = nullptr) = 0;

    virtual AbstractConfiguration::frames get_frame() = 0;

protected:
    std::shared_ptr<std::string> _source;
};
