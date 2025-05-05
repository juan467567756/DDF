<!-- Build status -->
![Build & Test DDF](https://github.com/juan467567756/DDF/actions/workflows/build.yml/badge.svg)
<!-- Licencia MIT -->
![License: MIT](https://img.shields.io/github/license/juan467567756/DDF)
<!-- Última versión -->
![Release](https://img.shields.io/github/v/release/juan467567756/DDF)
<!-- Coverage -->
[![Coverage Status](https://codecov.io/gh/juan467567756/DDF/branch/main/graph/badge.svg)](https://codecov.io/gh/juan467567756/DDF)



# DDF: Generador de Diagramas de Flujo en ASCII

DDF es una herramienta de línea de comandos que convierte un mini‑lenguaje de descripción de diagramas de flujo en arte ASCII. Ideal para documentar procesos en terminales, documentación técnica y tutoriales.

## Tabla de Contenidos

* [Características](#características)
* [Tecnologías](#tecnologías)
* [Instalación](#instalación)
* [Uso](#uso)

  * [Sintaxis del mini‑lenguaje](#sintaxis-del-mini-lenguaje)
  * [Ejemplos](#ejemplos)
* [Contribuir](#contribuir)
* [Licencia](#licencia)

## Características

* **Parser** de mini‑lenguaje desde stdin (`BOX`, `ARROW`, `DECIDE`)
* **Generación** de bloques ASCII reutilizables (`box`, `arrow`, `decision`)
* **Estructura modular** en C++ con `utils.h` / `utils.cpp`
* **Integración continua** con GitHub Actions

## Tecnologías

* **Lenguaje**: C++17
* **Compilador**: g++ (GCC)
* **CI**: GitHub Actions
* **Soporte**: Linux, macOS, Windows (Git Bash)

## Instalación

```bash
git clone https://github.com/juan467567756/DDF.git
cd DDF
mkdir build && cd build
cmake ..
make
# Opcional: instalar globalmente
sudo make install
```

## Uso

### Interfaz de Línea de Comandos (CLI)

Puedes especificar archivo de entrada, salida y formato:

```bash
# Leer desde archivo y mostrar ASCII
ddf --input example1.txt --format ascii

# Generar diagrama Graphviz en archivo
ddf --input example1.txt --output flowchart.dot --format dot

# Usar stdin/stdout por defecto
cat example1.txt | ddf

# Ver ayuda
ddf --help

## Ejemplo de salida

```
-----------------------
```

## Contribuir

¡Contribuciones bienvenidas! Si quieres mejorar DDF:

1. Haz un fork del repositorio.
2. Crea tu branch: `git checkout -b feature/nombre-feature`
3. Realiza tus cambios y haz commits descriptivos.
4. Envía un pull request.

## Licencia

Este proyecto está bajo la **Licencia MIT**. Consulta el archivo [LICENSE](LICENSE) para más detalles.


```
Ayudame un poco loco.  [![Patrociname❤️](https://img.shields.io/badge/Patrocinar-%E2%9D%A4-FE0000?logo=github)](https://github.com/sponsors/juan467567756)

```  
