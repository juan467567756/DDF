#pragma once
#include <string>
#include <ostream>

// Dibuja un bloque rectangular con texto centrado (ASCII)
void box(const std::string& text);
// Flecha vertical hacia abajo (ASCII)
void arrow();
// Bloque de decisión con ramas SÍ/NO (ASCII)
void decision(const std::string& question);
// Inicio de bucle con etiqueta (ASCII)
void loopStart(const std::string& label);
// Fin de bucle (ASCII)
void loopEnd();
// Rama ELSE (ASCII)
void elseBranch();

// --- Graphviz (.dot) output ---
// Escribe cabecera de un grafo dirigido
void dotHeader(std::ostream& out);
// Escribe cierre de grafo
void dotFooter(std::ostream& out);
// Agrega un nodo con etiqueta
defineDotNode(std::ostream& out, const std::string& id, const std::string& label);
// Agrega una arista de id_from a id_to
defineDotEdge(std::ostream& out, const std::string& from, const std::string& to);

