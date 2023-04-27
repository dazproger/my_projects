#pragma once
#include "filter.h"

const std::vector<std::vector<int>> NEIGHBOURS =
    std::vector<std::vector<int>>{{1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}};

class FilterWithMatrix : public Filter {
protected:
    std::vector<std::vector<double>> matrix_;

public:
    void Apply(Image &image) override;

    FilterWithMatrix();
};
