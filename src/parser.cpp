#include "parser.hpp"
#include <sstream>

AST parseProgram(std::istream& in) {
    AST ast;
    std::string line;
    int lineNo = 0;

    while (std::getline(in, line)) {
        ++lineNo;
        auto start = line.find_first_not_of(" \t\r\n");
        if (start == std::string::npos) continue;
        auto end = line.find_last_not_of(" \t\r\n");
        std::string token = line.substr(start, end - start + 1);
        if (token.empty() || token[0] == '#') continue;

        std::istringstream iss(token);
        std::string kw;
        iss >> kw;

        if (kw == "BOX") {
            std::string txt = token.substr(4);
            if (txt.empty()) throw ParserError("Línea " + std::to_string(lineNo) + ": BOX sin texto");
            ast.emplace_back(std::make_unique<BoxNode>(txt));
        }
        else if (kw == "ARROW") {
            ast.emplace_back(std::make_unique<ArrowNode>());
        }
        else if (kw == "DECIDE") {
            std::string cond = token.substr(7);
            if (cond.empty()) throw ParserError("Línea " + std::to_string(lineNo) + ": DECIDE sin condición");
            ast.emplace_back(std::make_unique<DecisionNode>(cond));
        }
        else if (kw == "ELSE") {
            ast.emplace_back(std::make_unique<ElseNode>());
        }
        else if (kw == "LOOP") {
            std::string lbl = token.substr(5);
            if (lbl.empty()) throw ParserError("Línea " + std::to_string(lineNo) + ": LOOP sin etiqueta");
            ast.emplace_back(std::make_unique<LoopNode>(lbl));
        }
        else if (kw == "ENDLOOP") {
            ast.emplace_back(std::make_unique<EndLoopNode>());
        }
        else {
            throw ParserError("Línea " + std::to_string(lineNo) + ": keyword desconocida '" + kw + "'");
        }
    }

    return ast;
}
