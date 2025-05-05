#pragma once
#include "ast.hpp"
#include <stdexcept>

// Error semántico
struct SemanticError : std::runtime_error {
    explicit SemanticError(const std::string& msg)
        : std::runtime_error(msg) {}
};

// Verifica reglas semánticas en el AST
void validateSemantics(const AST& ast);
