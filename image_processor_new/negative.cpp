#include "negative.h"
void Negative::Apply(Image& image) {
    size_t img_height = static_cast<size_t>(FourIntsToUint32(image.Header, HEIGHT_BEG));
    size_t img_width = static_cast<size_t>(FourIntsToUint32(image.Header, WIDTH_BEG));
    for (size_t i = 0; i < img_height; ++i) {
        for (size_t j = 0; j < img_width; ++j) {
            (image.Pixels[i][j].red *= -1)++;
            (image.Pixels[i][j].green *= -1)++;
            (image.Pixels[i][j].blue *= -1)++;
        }
    }
}
