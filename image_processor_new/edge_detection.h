#pragma once
#include "filter_with_matrix.h"
#include "grayscale.h"

static const std::vector<std::vector<double>> EDGE_MATRIX = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};

class EdgeDetection : public FilterWithMatrix, public Grayscale {
private:
    double threshold_;

public:
    explicit EdgeDetection(std::vector<std::string> info);

    void Apply(Image &image) override;
};
