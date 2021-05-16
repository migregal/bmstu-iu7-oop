#pragma once

#include <error.h>

class FileError : public SourceError {
public:
    FileError() = default;
    explicit FileError(std::string &message) : SourceError(message){};

    [[nodiscard]] const char *what() const noexcept override {
        return error_info.c_str();
    }
};