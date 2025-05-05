#include "ast.hpp"
#include "parser.hpp"
#include "utils.h"
#include <iostream>
#include <fstream>
#include "semantic.hpp"



int main(int argc, char* argv[]) {
    // setup de streams (igual a v0.7)...
    std::istream* in = &std::cin;
    std::ifstream inFile;
    // ... manejo de --input/--output si lo tienes

    try {
        AST ast = parseProgram(*in);
validateSemantics(ast);
        for (auto& node : ast) {
            if (auto b = dynamic_cast<BoxNode*>(node.get())) {
                box(b->text);
            } else if (dynamic_cast<ArrowNode*>(node.get())) {
                arrow();
            } else if (auto d = dynamic_cast<DecisionNode*>(node.get())) {
                decision(d->condition);
            } else if (dynamic_cast<ElseNode*>(node.get())) {
                elseBranch();
            } else if (auto l = dynamic_cast<LoopNode*>(node.get())) {
                loopStart(l->label);
            } else if (dynamic_cast<EndLoopNode*>(node.get())) {
                loopEnd();
            }
        }
    } catch (const ParserError& e) {
        std::cerr << "Error de sintaxis: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
