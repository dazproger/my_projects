#include "writer.h"
#include "reader.h"
#include <fstream>

void WriteImage(const std::string &output_path, Image &img) {
    std::ofstream file(output_path, std::ios::binary);
    for (size_t i = 0; i < LEN_OF_HEADER_VEC; ++i) {
        file.put(static_cast<char>(img.Header[i]));
    }
    for (size_t i = 0; i < img.Pixels.size(); ++i) {
        for (size_t j = 0; j < img.Pixels[i].size(); ++j) {
            file.put(static_cast<char>(static_cast<int16_t>(NormalizeValue(img.Pixels[i][j].blue) * UINT8_MAX)));
            file.put(static_cast<char>(static_cast<int16_t>(NormalizeValue(img.Pixels[i][j].green) * UINT8_MAX)));
            file.put(static_cast<char>(static_cast<int16_t>(NormalizeValue(img.Pixels[i][j].red) * UINT8_MAX)));
        }
        size_t width = FourIntsToUint32(img.Header, WIDTH_BEG);
        if ((width * 3) % 4 != 0) {
            for (size_t k = 0; k < 4 - ((width * 3) % 4); ++k) {
                file.put(0);
            }
        }
    }
    file.close();
}