// -------- src/utils.h --------
#pragma once
#include <string>

// Dibuja un bloque rectangular con texto centrado
void box(const std::string& text);

// Flecha vertical hacia abajo
void arrow();

// Bloque de decisión (pregunta) con ramas SÍ / NO
void decision(const std::string& question);

// Inicio de bucle con etiqueta
void loopStart(const std::string& label);

// Fin de bucle
void loopEnd();

// Rama ELSE en decisiones anidadas
void elseBranch();


