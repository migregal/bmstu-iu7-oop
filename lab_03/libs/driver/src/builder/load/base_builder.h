#pragma once

#include <objects/object.h>

namespace Load {
    class BaseBuilder {
    public:
        BaseBuilder() = default;
        ~BaseBuilder() = default;

        [[nodiscard]] virtual bool is_build() const = 0;
        virtual void build() = 0;

        virtual std::shared_ptr<Object> get() = 0;
    };
}// namespace Load