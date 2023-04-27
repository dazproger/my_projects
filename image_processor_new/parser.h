#pragma once
#include <vector>
#include <string>

struct FilterConfig {
    std::string name;
    std::vector<std::string> arguments;
};

struct ParserResults {
    std::string input_path;
    std::string output_path;
    std::vector<FilterConfig> filters;
};

ParserResults Parse(int argc, char *argv[]);