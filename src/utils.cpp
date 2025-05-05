#include "utils.hpp"
#include <iostream>
#include <string>
#include <ostream>


// Dibuja un recuadro ASCII alrededor de `text`
void box(const std::string& text) {
    // Borde superior e inferior con el texto dentro
    std::cout << "+-" << text << "-+" << "\n";
    // Línea central
    std::cout << "| " << text << " |" << "\n";
    // Repetimos el mismo borde
    std::cout << "+-" << text << "-+" << "\n";
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
