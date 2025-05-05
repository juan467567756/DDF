#ifndef DDF_SEMANTIC_HPP
#define DDF_SEMANTIC_HPP

#include <stdexcept>
#include "ast.hpp"

// Excepción de errores semánticos
struct SemanticError : std::runtime_error {
    explicit SemanticError(const std::string& msg)
        : std::runtime_error(msg)
    {}
};

// Firma de la función de chequeo semántico
void validateSemantics(const AST& ast);

#endif // DDF_SEMANTIC_HPP
