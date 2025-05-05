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

// Firma de la función que construye el AST
AST parseProgram(std::istream& in);

#endif // DDF_PARSER_HPP
