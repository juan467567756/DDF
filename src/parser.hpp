#pragma once
#include "ast.hpp"
#include <istream>
#include <stdexcept>

// Excepción para errores de sintaxis
struct ParserError : std::runtime_error {
    ParserError(const std::string& msg): std::runtime_error(msg) {}
};

// Función que lee TODO un istream y devuelve el AST
AST parseProgram(std::istream& in);
