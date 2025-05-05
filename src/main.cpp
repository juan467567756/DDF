#include "parser.hpp"
#include "semantic.hpp"
#include "utils.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "-h" || a == "--help") {
            std::cout
                << "Usage: ddf [--input <file>] [--output <file>] [--format <fmt>] [--help]\n"
                << "  --input <file>    Lee el diagrama de <file> (por defecto stdin)\n"
                << "  --output <file>   Escribe el resultado en <file> (por defecto stdout)\n"
                << "  --format <fmt>    Elige formato: ascii o dot (por defecto ascii)\n"
                << "  -h, --help        Muestra esta ayuda\n";
            return 0;
        }
    }
    // 1) Abrir input (o stdin)
    std::istream* in = &std::cin;
    std::ifstream inFile;
    if (argc > 1) {
        inFile.open(argv[1]);
        if (!inFile) {
            std::cerr << "Error al abrir " << argv[1] << std::endl;
            return 1;
        }
        in = &inFile;
    }

    try {
        // 2) Parsear y validar
        AST ast = parseProgram(*in);
        validateSemantics(ast);

        // 3) Recorrer AST y renderizar
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
    } catch (const SemanticError& e) {
        std::cerr << "Error semántico: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
