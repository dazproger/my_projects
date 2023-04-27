#include "filter_with_matrix.h"
#include "converter.h"
#include "reader.h"
#include "writer.h"

void FilterWithMatrix::Apply(Image& image) {
    int64_t height = static_cast<int64_t>(FourIntsToUint32(image.Header, HEIGHT_BEG));
    int64_t width = static_cast<int64_t>(FourIntsToUint32(image.Header, WIDTH_BEG));
    size_t x = 0;
    size_t y = 0;
    std::vector<std::vector<RGB>> new_image = image.Pixels;
    for (int64_t i = 0; i < height; ++i) {
        for (int64_t j = 0; j < width; ++j) {
            new_image[i][j].red *= matrix_[1][1];
            new_image[i][j].green *= matrix_[1][1];
            new_image[i][j].blue *= matrix_[1][1];
            for (auto coords : NEIGHBOURS) {
                x = ValidCoords(i + coords[0], height);
                y = ValidCoords(j + coords[1], width);
                new_image[i][j].green += (image.Pixels[x][y].green * matrix_[coords[0] + 1][coords[1] + 1]);
                new_image[i][j].blue += (image.Pixels[x][y].blue * matrix_[coords[0] + 1][coords[1] + 1]);
                new_image[i][j].red += (image.Pixels[x][y].red * matrix_[coords[0] + 1][coords[1] + 1]);
            }
            new_image[i][j].green = NormalizeValue(new_image[i][j].green);
            new_image[i][j].blue = NormalizeValue(new_image[i][j].blue);
            new_image[i][j].red = NormalizeValue(new_image[i][j].red);
        }
    }
    for (int64_t i = 0; i < height; ++i) {
        for (int64_t j = 0; j < width; ++j) {
            image.Pixels[i][j].green = new_image[i][j].green;
            image.Pixels[i][j].blue = new_image[i][j].blue;
            image.Pixels[i][j].red = new_image[i][j].red;
        }
    }
}

FilterWithMatrix::FilterWithMatrix() {
}
