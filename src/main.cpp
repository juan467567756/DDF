#include <iostream>
#include <memory>
#include <vector>
#include "ast.hpp"
#include "parser.hpp"
#include "semantic.hpp"
#include "utils.hpp"

int main(int argc, char* argv[]) {
    // Parseo de entrada (stdin o archivo según tu implementación)
    auto ast = parse(std::cin);

    // Opcional: chequeo semántico
    check_semantic(ast);

    // Recorremos el AST e imprimimos según tipo
    for (auto& node : ast) {
        if (const BoxNode* b = dynamic_cast<const BoxNode*>(node.get())) {
            std::cout << b->text << std::endl;
        }
        else if (const DecisionNode* d = dynamic_cast<const DecisionNode*>(node.get())) {
            std::cout << d->condition << std::endl;
        }
        else if (const LoopNode* l = dynamic_cast<const LoopNode*>(node.get())) {
            std::cout << l->label << std::endl;
        }
    }

    return 0;
}
