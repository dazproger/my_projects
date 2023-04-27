#include "crop.h"
#include <string>
#include <sstream>

void Crop::Apply(Image &image) {
    size_t needed_height = std::min(heigth_, static_cast<size_t>(FourIntsToUint32(image.Header, HEIGHT_BEG)));
    size_t needed_width = std::min(width_, static_cast<size_t>(FourIntsToUint32(image.Header, WIDTH_BEG)));
    image.Pixels.erase(image.Pixels.begin(), image.Pixels.end() - static_cast<int64_t>(needed_height));
    for (size_t i = 0; i < needed_height; ++i) {
        image.Pixels[i].erase(image.Pixels[i].begin() + static_cast<int64_t>(needed_width), image.Pixels[i].end());
    }
    auto height_vec = SizeTToFourBytes(needed_height);
    auto width_vec = SizeTToFourBytes(needed_width);
    for (size_t i = 0; i < 4; ++i) {
        image.Header[i + HEIGHT_BEG] = height_vec[i];
        image.Header[i + WIDTH_BEG] = width_vec[i];
    }
}
Crop::Crop(std::vector<std::string> info) {
    std::stringstream stream(info[0]);
    stream >> heigth_;
    std::stringstream stream_2(info[1]);
    stream_2 >> width_;
}
