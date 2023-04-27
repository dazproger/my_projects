#pragma once
#include "image.h"
#include <string>

class Filter {
public:
    virtual void Apply(Image &image) = 0;
};
