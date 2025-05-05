#include "utils.h"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string line;
    // Lee línea a línea desde stdin hasta EOF
    while (std::getline(std::cin, line)) {
        if (line.rfind("BOX ", 0) == 0) {
            std::string text = line.substr(4);
            box(text);
        } else if (line == "ARROW") {
            arrow();
        } else if (line.rfind("DECIDE ", 0) == 0) {
            std::string question = line.substr(7);
            decision(question);
        } else if (line.rfind("COMMENT ", 0) == 0) {
            // permitir comentarios en la entrada
            continue;
        } else if (line.empty()) {
            continue;
        } else {
            std::cerr << "Línea desconocida: '" << line << "'\n";
        }
    }
    return 0;
}
