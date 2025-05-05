![Build & Test DDF](https://github.com/juan467567756/DDF/actions/workflows/build.yml/badge.svg)
![Release](https://img.shields.io/github/v/release/juan467567756/DDF)
![License](https://img.shields.io/github/license/juan467567756/DDF)

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

Ejecuta `ddf` y proporciona la descripción por stdin:

```bash
echo -e "BOX Iniciar\nARROW\nDECIDE ¿Continuar?\nBOX Fin" | ./ddf
```

### Sintaxis del mini‑lenguaje

* `BOX <texto>`: Crea un bloque de proceso con `<texto>`.
* `ARROW`: Dibuja una flecha de conexión.
* `DECIDE <texto>`: Crea un bloque de decisión con `<texto>`.

## Ejemplo de salida

```
+-----------+
|  Iniciar  |
+-----------+
     |
     v
 +-------------+
 | ¿Continuar? |
 +-------------+
     |
    / \
   /   \
```

## Contribuir

¡Contribuciones bienvenidas! Si quieres mejorar DDF:

1. Haz un fork del repositorio.
2. Crea tu branch: `git checkout -b feature/nombre-feature`
3. Realiza tus cambios y haz commits descriptivos.
4. Envía un pull request.

## Licencia

Este proyecto está bajo la **Licencia MIT**. Consulta el archivo [LICENSE](LICENSE) para más detalles.
