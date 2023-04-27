#pragma once
#include "reader.h"
#include "image.h"
#include "filter.h"
#include "converter.h"
#include <algorithm>

class Crop : public Filter {
public:
    Crop(size_t height, size_t width) : heigth_(height), width_(width) {
    }

    explicit Crop(std::vector<std::string> info);

    void Apply(Image &image) override;

private:
    size_t heigth_;
    size_t width_;
};
