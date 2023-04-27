#pragma once
#include "reader.h"
#include "image.h"
#include "filter.h"
#include "converter.h"

const double RED_INTENSITY = 0.299;
const double GREEN_INTENSITY = 0.587;
const double BLUE_INTENSITY = 0.114;

class Grayscale : public Filter {
public:
    void Apply(Image &image) override;
};