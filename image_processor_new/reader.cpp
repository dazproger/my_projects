#include "reader.h"
#include "image.h"
#include "rgb.h"
#include "exceptions.h"
#include "converter.h"
#include <fstream>
#include <limits.h>
#include <iostream>
#include <vector>
#include <limits>

Image ReadImage(const std::string &input_path) {
    std::vector<uint8_t> header_vec(LEN_OF_HEADER_VEC);
    std::ifstream file(input_path, std::ios::binary);
    for (size_t i = 0; i < LEN_OF_HEADER_VEC; ++i) {
        header_vec[i] = file.get();
    }
    if (!(static_cast<char>(header_vec[0]) == 'B' && static_cast<char>(header_vec[1]) == 'M')) {
        throw ParserException();
    }
    size_t height = FourIntsToUint32(header_vec, HEIGHT_BEG);
    size_t width = FourIntsToUint32(header_vec, WIDTH_BEG);
    std::vector<std::vector<RGB>> pixels(height, std::vector<RGB>(width));

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            UintColor current;
            current.blue = file.get();
            current.green = file.get();
            current.red = file.get();
            pixels[i][j] = {static_cast<double>(current.blue) / std::numeric_limits<uint8_t>::max(),
                            static_cast<double>(current.green) / std::numeric_limits<uint8_t>::max(),
                            static_cast<double>(current.red) / std::numeric_limits<uint8_t>::max()};
        }
        if ((width * 3) % 4 != 0) {
            for (size_t k = 0; k < 4 - ((width * 3) % 4); ++k) {
                file.get();
            }
        }
    }
    Image img;
    img.Header = std::move(header_vec);
    img.Pixels = std::move(pixels);
    file.close();
    return img;
}