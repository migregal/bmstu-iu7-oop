//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_BASE_COLLECTION_HPP
#define LAB_02_BASE_COLLECTION_HPP

#include <cstddef>

class base_collection {
protected:
    size_t size = 0;

public:
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual ~base_collection() = default;
};

#endif//LAB_02_BASE_COLLECTION_HPP
