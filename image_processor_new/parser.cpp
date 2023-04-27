#include "exceptions.h"
#include "parser.h"

ParserResults Parse(int argc, char *argv[]) {
    ParserResults parser_results;
    if (argc <= 2) {
        throw ParserException();
    }
    parser_results.input_path = argv[1];
    parser_results.output_path = argv[2];
    for (int index = 3; index < argc;) {
        if (argv[index][0] == '-') {
            FilterConfig config;
            config.name = std::string(argv[index]).substr(1);
            ++index;
            while (index < argc && argv[index][0] != '-') {
                config.arguments.emplace_back(argv[index]);
                ++index;
            }
            parser_results.filters.emplace_back(config);
        }
    }
    return parser_results;
}