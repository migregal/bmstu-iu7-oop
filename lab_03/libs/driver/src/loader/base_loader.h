#pragma once

#include <fstream>
#include <string>

#include <builder/base_builder.h>
#include <error.h>
#include <objects/object.h>

class BaseLoader {
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &fname) = 0;
    virtual void close() = 0;
};
