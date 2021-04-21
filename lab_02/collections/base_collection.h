//
// Created by gregory on 10.04.2021.
//

#ifndef LAB_02_BASE_COLLECTION_H
#define LAB_02_BASE_COLLECTION_H

#include <cstddef>

class base_collection {
protected:
    size_t size = 0;

public:
    virtual bool empty() const;
    virtual void clear() = 0;
    virtual ~base_collection() = 0;
};

#endif//LAB_02_BASE_COLLECTION_H
