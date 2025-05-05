#include "utils.hpp"
#include <iostream>
#include <string>
#include <ostream>

// Dibuja un recuadro ASCII alrededor de `text`
void box(const std::string& text) {
    std::string border(text.size() + 2, '-');
    std::cout << "+" << border << "+" << "\n";
    std::cout << "| " << text << " |" << "\n";
    std::cout << "+" << border << "+" << "\n";
}

// Flecha hacia abajo
void arrow() {
    std::cout << "  |" << "\n";
    std::cout << "  v" << "\n";
}

// Decisión en rombo ASCII con `question` adentro
void decision(const std::string& question) {
    std::string border(question.size() + 2, '-');
    std::cout << " /" << border << "\\" << "\n";
    std::cout << "< " << question << " >" << "\n";
    std::cout << " \\" << border << "/" << "\n";
}

// Inicio de bucle: imprime etiqueta y flecha
void loopStart(const std::string& label) {
    std::cout << label << "\n";
    arrow();
}

// Fin de bucle: flecha hacia arriba
void loopEnd() {
    std::cout << "^ loop end" << "\n";
}

// Rama else en ASCII
void elseBranch() {
    std::cout << "--- else --->" << "\n";
}

// Cabecera de un .dot de Graphviz
void dotHeader(std::ostream& out) {
    out << "digraph G {\n";
}
