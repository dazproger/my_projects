#pragma once
#include "rgb.h"
#include "converter.h"
#include <vector>

const int LEN_OF_HEADER_VEC = 54;

struct Image {
    std::vector<std::vector<RGB>> Pixels;
    std::vector<uint8_t> Header = std::vector<uint8_t>(LEN_OF_HEADER_VEC);
};

void SwitchSize(Image &img, size_t size, size_t where);