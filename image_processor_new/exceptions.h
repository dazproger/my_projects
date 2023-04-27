#pragma once
#include <exception>

class ImageProcessorException : public std::exception {};

class ParserException : public ImageProcessorException {};

class FilterConfigException : public ImageProcessorException {};