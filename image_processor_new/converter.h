#pragma once
#include "image.h"
#include <vector>
#include <cstdint>

std::vector<uint8_t> SizeTToFourBytes(size_t size);

std::uint32_t FourIntsToUint32(const std::vector<uint8_t> &header, size_t start);

size_t ValidCoords(int64_t coord, int64_t max_value);

double NormalizeValue(double &value);