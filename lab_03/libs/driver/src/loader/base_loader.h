#pragma once

#include <fstream>
#include <string>

#include <builder/load/base_builder.h>
#include <error.h>
#include <objects/object.h>

namespace Load {
    class BaseLoader {
    public:
        BaseLoader() = default;
        virtual ~BaseLoader() = default;

        virtual void open(std::string &fname) = 0;
        virtual void close() = 0;
    };
}// namespace Load