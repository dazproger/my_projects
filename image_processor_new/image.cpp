#include "image.h"

void SwitchSize(Image &img, size_t size, size_t where) {
    auto bytes = SizeTToFourBytes(size);
    for (size_t i = 0; i < 4; ++i) {
        img.Header[where + i] = bytes[i];
    }
}
