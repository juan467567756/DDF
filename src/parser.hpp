#pragma once
#include "ast.hpp"
#include <stdexcept>
#include <istream>

struct ParserError : std::runtime_error {
    explicit ParserError(const std::string& msg)
        : std::runtime_error(msg) {}
};

AST parseProgram(std::istream& in);
