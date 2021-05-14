#pragma once

#include <error.h>

class FileError : public SourceError {
public:
    FileError() = default;
    explicit FileError(std::string &message) : SourceError(message){};

    [[nodiscard]] const char *what() const noexcept override {
        return "File corrupt or does not exist.";
    }
};