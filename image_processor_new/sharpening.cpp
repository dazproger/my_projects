#include "sharpening.h"

Sharpening::Sharpening() {
    matrix_ = SHARP_MATRIX;
}
void Sharpening::Apply(Image& image) {
    FilterWithMatrix::Apply(image);
}
