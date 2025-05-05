#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void printUsage() {
    std::cout << "Uso: ddf [--input <file>] [--output <file>] [--format ascii|dot]" << std::endl;
}

int main(int argc, char* argv[])
{
    std::string inputFile;
    std::string outputFile;
    std::string format = "ascii";

    // Parse CLI args
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--input" && i + 1 < argc) {
            inputFile = argv[++i];
        } else if (arg == "--output" && i + 1 < argc) {
            outputFile = argv[++i];
        } else if (arg == "--format" && i + 1 < argc) {
            format = argv[++i];
        } else if (arg == "--help") {
            printUsage();
            return 0;
        } else {
            std::cerr << "Parámetro desconocido: " << arg << std::endl;
            printUsage();
            return 1;
        }
    }

    // Setup input stream
    std::istream* in = &std::cin;
    std::ifstream inFile;
    if (!inputFile.empty()) {
        inFile.open(inputFile);
        if (!inFile) {
            std::cerr << "No se pudo abrir el archivo de entrada: " << inputFile << std::endl;
            return 1;
        }
        in = &inFile;
    }

    // Setup output stream
    std::ostream* out = &std::cout;
    std::ofstream outFile;
    if (!outputFile.empty()) {
        outFile.open(outputFile);
        if (!outFile) {
            std::cerr << "No se pudo abrir el archivo de salida: " << outputFile << std::endl;
            return 1;
        }
        out = &outFile;
    }

    bool toDot = (format == "dot");
    if (toDot) dotHeader(*out);

    std::string line;
    int nodeCount = 0;
    std::string prevNode;

    while (std::getline(*in, line)) {
        std::string id = "n" + std::to_string(nodeCount++);
        if (line.rfind("BOX ", 0) == 0) {
            std::string text = line.substr(4);
            if (!toDot) box(text);
            defineDotNode(*out, id, text);
        } else if (line == "ARROW") {
            if (!toDot) arrow();
        } else if (line.rfind("DECIDE ", 0) == 0) {
            std::string q = line.substr(7);
            if (!toDot) decision(q);
            defineDotNode(*out, id, q + "?");
        } else if (line.rfind("LOOP ", 0) == 0) {
            std::string lbl = line.substr(5);
            if (!toDot) loopStart(lbl);
            defineDotNode(*out, id, "LOOP: " + lbl);
        } else if (line == "ENDLOOP") {
            if (!toDot) loopEnd();
            defineDotNode(*out, id, "END LOOP");
        } else if (line == "ELSE") {
            if (!toDot) elseBranch();
            defineDotNode(*out, id, "ELSE");
        }
        if (!prevNode.empty()) defineDotEdge(*out, prevNode, id);
        prevNode = id;
    }

    if (toDot) dotFooter(*out);
    return 0;
}

