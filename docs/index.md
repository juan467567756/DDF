---
title: DDF – Generador de Diagramas de Flujo
---

# DDF

¡Bienvenido a la demo de DDF!  

Este proyecto convierte un “mini‑lenguaje” (BOX, ARROW, DECIDE, LOOP, ELSE)  
en diagramas de flujo ASCII y en ficheros Graphviz.

## Cómo usarlo

```bash
# Formato ASCII
ddf --input example1.txt --format ascii

# Graphviz .dot
ddf --input example1.txt --output flowchart.dot --format dot
