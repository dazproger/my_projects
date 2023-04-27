#include "controller.h"
#include "reader.h"
#include "writer.h"
#include "filter.h"
#include "crop.h"
#include "exceptions.h"
#include "grayscale.h"
#include "negative.h"
#include "filter_with_matrix.h"
#include "sharpening.h"
#include "edge_detection.h"

void ControllerOfEditing(ParserResults &parser_results) {
    Image img = ReadImage(parser_results.input_path);
    for (size_t i = 0; i < parser_results.filters.size(); ++i) {
        if (parser_results.filters[i].name == "crop") {
            if (parser_results.filters[i].arguments.size() != 2) {
                throw FilterConfigException();
            } else {
                Crop crop(parser_results.filters[i].arguments);
                crop.Apply(img);
            }
        } else if (parser_results.filters[i].name == "gs") {
            Grayscale grayscale;
            grayscale.Apply(img);
        } else if (parser_results.filters[i].name == "neg") {
            Negative negative;
            negative.Apply(img);
        } else if (parser_results.filters[i].name == "sharp") {
            Sharpening sharpening;
            sharpening.Apply(img);
        } else if (parser_results.filters[i].name == "edge") {
            EdgeDetection edge_detection(parser_results.filters[i].arguments);
            edge_detection.Apply(img);
        }
    }
    WriteImage(parser_results.output_path, img);
}