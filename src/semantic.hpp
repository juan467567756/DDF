#ifndef DDF_SEMANTIC_HPP
#define DDF_SEMANTIC_HPP

#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include "ast.hpp"

// Excepción de errores semánticos
struct SemanticError : std::runtime_error {
    explicit SemanticError(const std::string& msg)
        : std::runtime_error(msg)
    {}
};

// Declara tu función de chequeo semántico
void check_semantic(const std::vector<std::unique_ptr<Node>>& ast);

#endif // DDF_SEMANTIC_HPP
