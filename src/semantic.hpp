#pragma once
#include "ast.hpp"
#include <stdexcept>

struct SemanticError : std::runtime_error {
  SemanticError(const std::string& msg): std::runtime_error(msg) {}
};

// Recorre el AST y verifica reglas semánticas
void validateSemantics(const AST& ast);
