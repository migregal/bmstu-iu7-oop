//
// Created by gregory on 21.04.2021.
//

#include <base_collection.h>

base_collection::~base_collection() = default;

bool base_collection::empty() const {
    return 0 == size;
}