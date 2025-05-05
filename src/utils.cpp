#include "utils.h"
#include <iostream>

void box(const std::string& text) {
    std::string line(text.size(), '-');
    std::cout << "+-" << line << "-+\n";
    std::cout << "| "  << text << " |\n";
    std::cout << "+-" << line << "-+\n";
}

void arrow() {
    std::cout << "  |\n  v\n";
}

void decision(const std::string& question) {
    box(question + " ?");
    std::cout << " / \\\n"
                 "v   v\n";
}

void loopStart(const std::string& label) {
    box("LOOP: " + label);
    arrow();
}

void loopEnd() {
    box("END LOOP");
    arrow();
}

void elseBranch() {
    box("ELSE");
    arrow();
}

void dotHeader(std::ostream& out) {
    out << "digraph Flow {\n";
    out << "  node [shape=box];\n";
}

void dotFooter(std::ostream& out) {
    out << "}\n";
}

void defineDotNode(std::ostream& out, const std::string& id, const std::string& label) {
    out << "  " << id << " [label=\"" << label << "\"];\n";
}

void defineDotEdge(std::ostream& out, const std::string& from, const std::string& to) {
    out << "  " << from << " -> " << to << ";\n";
}
