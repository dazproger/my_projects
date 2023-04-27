#include "grayscale.h"
void Grayscale::Apply(Image& image) {
    size_t img_height = static_cast<size_t>(FourIntsToUint32(image.Header, HEIGHT_BEG));
    size_t img_width = static_cast<size_t>(FourIntsToUint32(image.Header, WIDTH_BEG));
    for (size_t i = 0; i < img_height; ++i) {
        for (size_t j = 0; j < img_width; ++j) {
            double gs_value = RED_INTENSITY * image.Pixels[i][j].red + GREEN_INTENSITY * image.Pixels[i][j].green +
                              BLUE_INTENSITY * image.Pixels[i][j].blue;
            image.Pixels[i][j].red = gs_value;
            image.Pixels[i][j].green = gs_value;
            image.Pixels[i][j].blue = gs_value;
        }
    }
}
