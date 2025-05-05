#ifndef DDF_PARSER_HPP
#define DDF_PARSER_HPP

#include <stdexcept>
#include <string>
#include <istream>
#include <vector>
#include <memory>
#include "ast.hpp"

// Excepción de errores de parsing
struct ParserError : std::runtime_error {
    explicit ParserError(const std::string& msg)
        : std::runtime_error(msg)
    {}
};

// Declara tu función parse (ajusta firma si era distinta)
std::vector<std::unique_ptr<Node>> parse(std::istream& in);

#endif // DDF_PARSER_HPP
