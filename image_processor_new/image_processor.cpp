#include <iostream>
#include "parser.h"
#include "reader.h"
#include "writer.h"
#include "crop.h"
#include "controller.h"

int main(int argc, char* argv[]) {
    ParserResults parsed_results = Parse(argc, argv);
    ControllerOfEditing(parsed_results);
}