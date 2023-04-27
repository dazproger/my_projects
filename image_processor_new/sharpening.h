#pragma once
#include "filter_with_matrix.h"

static const std::vector<std::vector<double>> SHARP_MATRIX = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

class Sharpening : public FilterWithMatrix {
public:
    Sharpening();

    void Apply(Image &image) override;
};
