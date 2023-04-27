#pragma once
#include "reader.h"
#include "image.h"
#include "filter.h"
#include "converter.h"

class Negative : public Filter {
public:
    void Apply(Image &image) override;
};