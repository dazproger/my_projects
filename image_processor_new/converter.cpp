#include "converter.h"

std::vector<uint8_t> SizeTToFourBytes(size_t size) {
    std::vector<uint8_t> res = std::vector<uint8_t>(4);
    for (size_t i = 0; i < 3; ++i) {
        res[i] = size % (UINT8_MAX + 1);
        size -= res[i];
        size /= (UINT8_MAX + 1);
    }
    res[3] = size;
    return res;
}

std::uint32_t FourIntsToUint32(const std::vector<uint8_t> &header, size_t start) {
    return (((header[start + 3] * (UINT8_MAX + 1) + header[start + 2]) * (UINT8_MAX + 1) + header[start + 1]) *
                (UINT8_MAX + 1) +
            header[start]);
}

size_t ValidCoords(int64_t coord, int64_t max_value) {
    if (coord < 0) {
        return 0;
    }
    if (coord > max_value - 1) {
        return coord - 1;
    }
    return coord;
}

double NormalizeValue(double &value) {
    if (value > 1) {
        return 1;
    }
    if (value < 0) {
        return 0;
    }
    return value;
}