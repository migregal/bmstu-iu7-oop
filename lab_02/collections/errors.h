//
// Created by gregory on 13.04.2021.
//

#ifndef LAB_02_ERRORS_H
#define LAB_02_ERRORS_H

#include <cstring>
#include <exception>
#include <string>

using str = std::string;

class base_err : public std::exception {
public:
    base_err(const str &time, const str &filename, const str &classname, const str &method) {
        error_info = "\nTime: " + time +
                     "\tFile: " + filename +
                     "\n\tClass: " + classname +
                     "\n\tMethod: " + method;
    }

    const char *what() const noexcept override {
        std::string message = "\nERROR: Something is wrong with your set." + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }

protected:
    std::string error_info;
};

class bad_alloc_err : base_err {
public:
    bad_alloc_err(const str &time, const str &filename, const str &classname, const str &method) : base_err(time, filename, classname, method){};

    const char *what() const noexcept override {
        std::string message = "\nERROR: Unable to allocate memory. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class iterator_error : base_err {
public:
    iterator_error(const str &time, const str &filename, const str &classname, const str &method) : base_err(time, filename, classname, method){};

    const char *what() const noexcept override {
        std::string message = "\nERROR: Invalid iterator. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

#endif//LAB_02_ERRORS_H
