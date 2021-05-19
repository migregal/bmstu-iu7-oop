#pragma onсe

#include <memory>

#include <configuration/abstract_configuration.h>

class ConfigurationCreator {
public:
    std::shared_ptr<AbstractConfiguration> get_configuration(std::shared_ptr<std::string> source = nullptr);

private:
    void create_instance(std::shared_ptr<std::string> &source);

    std::shared_ptr<AbstractConfiguration> _conf;
};
