#include <configuration/libconf/libconf_configuration.h>

#include <error/error.h>
#include <sstream>

LibconfConfiguration::LibconfConfiguration(std::shared_ptr<std::string> &source) : AbstractConfiguration(source) {}

void LibconfConfiguration::read_configuration(std::shared_ptr<std::string> source) {

    cfg = std::make_shared<libconfig::Config>();

    try {
        cfg->readFile(_source ? _source->c_str() : source->c_str());
    } catch (const libconfig::FileIOException &fioex) {
        auto msg = std::string("I/O error while reading file.");
        throw FileError(msg);
    } catch (const libconfig::ParseException &pex) {
        std::stringstream msg;
        msg << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        auto str = msg.str();
        throw FileError(str);
    }
}

AbstractConfiguration::frames LibconfConfiguration::get_frame() {
    if (!cfg)
        read_configuration(std::make_shared<std::string>(DEFAULT_FILE));

    auto &root = cfg->getRoot();

    std::string frame;
    try {
        const auto &ui = root["graphics"];

        if (!ui.lookupValue("frame", frame))
            frame = "qt";

    } catch (const libconfig::SettingNotFoundException &nfex) {
        return QT;
    }

    if ("qt" == frame) {
        return QT;
    } else {
        return QT;
    }
}
AbstractConfiguration::sources LibconfConfiguration::get_load_source() {
    if (!cfg)
        read_configuration(std::make_shared<std::string>(DEFAULT_FILE));

    auto &root = cfg->getRoot();

    std::string frame;
    try {
        const auto &ui = root["storage"];

        if (!ui.lookupValue("load_source", frame))
            frame = "file";

    } catch (const libconfig::SettingNotFoundException &nfex) {
        return FILE;
    }

    if ("file" == frame) {
        return FILE;
    } else {
        return FILE;
    }
}
