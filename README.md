# DDF

![Build & Test DDF](https://github.com/juan467567756/DDF/actions/workflows/build.yml/badge.svg)
![Coverage Status](https://codecov.io/gh/juan467567756/DDF/branch/main/graph/badge.svg)
![License: MIT](https://img.shields.io/github/license/juan467567756/DDF)
![Release](https://img.shields.io/github/v/release/juan467567756/DDF)

---

## English

### Description
DDF (Diagram Definition Format) is a lightweight C++17 tool that parses a simple DSL into flow diagrams. It supports ASCII art output and Graphviz (“.dot”) files.

### Features
- **Parse & Render**  
  Commands: `BOX`, `ARROW`, `DECIDE`, `ELSE`, `LOOP`, `ENDLOOP`  
  Outputs: terminal ASCII diagrams or `.dot` files for Graphviz  
- **Syntax & Semantic Validation**  
  Catches unknown keywords, missing text, unclosed loops, and `ELSE` without `DECIDE`.  
- **Flexible CLI**  
  `ddf [--input <file>] [--output <file>] [--format <ascii|dot>] [--help]`  
- **Automated Testing & CI**  
  - GoogleTest suites: core_tests, parser_tests, semantic_tests  
  - Static analysis with cppcheck & clang-tidy  
  - Code coverage via lcov + Codecov  
  - GitHub Actions pipeline with build, tests, coverage and Docker smoke test  
- **Cross-Platform Releases**  
  Prebuilt Linux, macOS, and Windows binaries published on GitHub Releases.

### Installation
1. Clone the repo:  
   `git clone https://github.com/juan467567756/DDF.git`  
 :)

### Usage
- **ASCII (default)**  
  `printf "BOX Start\nARROW\nBOX End\n" | build/ddf`  
- **Graphviz (.dot)**  
  `build/ddf --input flow.txt --output flow.dot --format dot`  
  then `dot -Tpng flow.dot -o flow.png`  
- **Help**  
  `ddf --help`

### Contributing
See CONTRIBUTING.md and CODE_OF_CONDUCT.md for guidelines.

### License
MIT License (see LICENSE file)

### Technologies
C++17 · CMake · GoogleTest · cppcheck · clang-tidy · GitHub Actions · lcov/Codecov · Docker · Graphviz · GitHub Pages

---

## Español

### Descripción
DDF (Diagram Definition Format) es una herramienta en C++17 para convertir un DSL sencillo en diagramas de flujo. Soporta salida ASCII en terminal y archivos Graphviz (`.dot`).

### Características
- **Parseo y Renderizado**  
  Comandos: `BOX`, `ARROW`, `DECIDE`, `ELSE`, `LOOP`, `ENDLOOP`  
  Salidas: ASCII art en la terminal o archivos `.dot`  
- **Validación Sintáctica y Semántica**  
  Detecta keywords desconocidas, texto faltante, bucles sin cerrar y `ELSE` sin `DECIDE`.  
- **CLI Flexible**  
  `ddf [--input <archivo>] [--output <archivo>] [--format <ascii|dot>] [--help]`  
- **Pruebas Automáticas y CI**  
  - Suites GoogleTest: core_tests, parser_tests, semantic_tests  
  - Análisis estático con cppcheck y clang-tidy  
  - Cobertura con lcov + Codecov  
  - Pipeline en GitHub Actions para build, tests, cobertura y smoke test en Docker  
- **Releases Multiplataforma**  
  Binarios listos para Linux, macOS y Windows en GitHub Releases.

### Instalación
1. Clona el repositorio:  
   `git clone https://github.com/juan467567756/DDF.git`  
 :)

### Uso
- **ASCII (por defecto)**  
  `printf "BOX Inicio\nARROW\nBOX Fin\n" | build/ddf`  
- **Graphviz (.dot)**  
  `build/ddf --input diagrama.txt --output diagrama.dot --format dot`  
  luego `dot -Tpng diagrama.dot -o diagrama.png`  
- **Ayuda**  
  `ddf --help`

### Contribuir
Consulta CONTRIBUTING.md y CODE_OF_CONDUCT.md.

### Licencia
MIT License (ver archivo LICENSE)

### Tecnologías
C++17 · CMake · GoogleTest · cppcheck · clang-tidy · GitHub Actions · lcov/Codecov · Docker · Graphviz · GitHub Pages
