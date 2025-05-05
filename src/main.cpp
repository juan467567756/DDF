#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

void printUsage() {
    std::cout << "Uso: ddf [--input <file>] [--output <file>] [--format ascii|dot]\n";
}

int main(int argc, char* argv[]) {
    std::string inputFile, outputFile, format = "ascii";

    // Parse CLI args
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--input" && i+1 < argc) {
            inputFile = argv[++i];
        } else if (arg == "--output" && i+1 < argc) {
            outputFile = argv[++i];
        } else if (arg == "--format" && i+1 < argc) {
            format = argv[++i];
        } else if (arg == "--help") {
            printUsage();
            return 0;
        } else {
            std::cerr << "Parámetro desconocido: " << arg << "\n";
            printUsage();
            return 1;
        }
    }

    // Input stream
    std::istream* in = &std::cin;
    std::ifstream inFile;
    if (!inputFile.empty()) {
        inFile.open(inputFile);
        if (!inFile) {
            std::cerr << "No se pudo abrir: " << inputFile << "\n";
            return 1;
        }
        in = &inFile;
    }

    // Output stream
    std::ostream* out = &std::cout;
    std::ofstream outFile;
    if (!outputFile.empty()) {
        outFile.open(outputFile);
        if (!outFile) {
            std::cerr << "No se pudo abrir: " << outputFile << "\n";
            return 1;
        }
        out = &outFile;
    }

    bool toDot = (format == "dot");
    if (toDot) dotHeader(*out);

    std::string line, prev;
    int count = 0;
    while (std::getline(*in, line)) {
        std::string id = "n" + std::to_string(count++);
        if (line.rfind("BOX ",0)==0) {
            auto txt = line.substr(4);
            if (!toDot) box(txt);
            defineDotNode(*out,id,txt);
        } else if (line=="ARROW") {
            if (!toDot) arrow();
        } else if (line.rfind("DECIDE ",0)==0) {
            auto q = line.substr(7);
            if (!toDot) decision(q);
            defineDotNode(*out,id,q+"?");
        } else if (line.rfind("LOOP ",0)==0) {
            auto lbl=line.substr(5);
            if (!toDot) loopStart(lbl);
            defineDotNode(*out,id,"LOOP: "+lbl);
        } else if (line=="ENDLOOP") {
            if (!toDot) loopEnd();
            defineDotNode(*out,id,"END LOOP");
        } else if (line=="ELSE") {
            if (!toDot) elseBranch();
            defineDotNode(*out,id,"ELSE");
        }
        if (!prev.empty()) defineDotEdge(*out,prev,id);
        prev=id;
    }

    if (toDot) dotFooter(*out);
    return 0;
}

