#include "utils.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    bool toDot = false;
    std::ostream* out = &std::cout;
    std::ofstream dotFile;
    if (argc > 1 && std::string(argv[1]) == "--dot") {
        toDot = true;
        dotFile.open("flowchart.dot");
        out = &dotFile;
        dotHeader(*out);
    }

    std::string line;
    int nodeCount = 0;
    std::vector<std::string> nodeStack;
    std::string prevNode;

    while (std::getline(std::cin, line)) {
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
            defineDotNode(*out, id, std::string("LOOP: ") + lbl);
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

    if (toDot) {
        dotFooter(*out);
        dotFile.close();
        std::cout << "Generado flowchart.dot" << std::endl;
    }
    return 0;
}


