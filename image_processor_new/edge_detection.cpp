#include "edge_detection.h"
#include <string>
#include <sstream>

void EdgeDetection::Apply(Image& image) {
    Grayscale::Apply(image);
    FilterWithMatrix::Apply(image);
    int64_t height = static_cast<int64_t>(FourIntsToUint32(image.Header, HEIGHT_BEG));
    int64_t width = static_cast<int64_t>(FourIntsToUint32(image.Header, WIDTH_BEG));
    for (int64_t i = 0; i < height; ++i) {
        for (int64_t j = 0; j < width; ++j) {
            if (image.Pixels[i][j].blue > threshold_) {
                image.Pixels[i][j] = {1, 1, 1};
            } else {
                image.Pixels[i][j] = {0, 0, 0};
            }
        }
    }
}

EdgeDetection::EdgeDetection(std::vector<std::string> info) {
    matrix_ = EDGE_MATRIX;
    std::stringstream stream(info[0]);
    stream >> threshold_;
}
