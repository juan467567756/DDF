# DDF
Una pequeña herramienta que dado cierto input (por ejemplo texto o pseudocódigo), genera visualizaciones básicas en consola (con texto) de diagramas de flujo simples.
<pre markdown> ## Uso 1. Crea un archivo de instrucciones, por ejemplo `sample.txt`, con este contenido: ``` BOX INICIO ARROW BOX Ingresar X ARROW DECIDE X > 10 BOX Grande ARROW BOX FIN ``` 
2. (Opcional local) Compila el programa: ```bash g++ src/main.cpp src/utils.cpp -o ddf ``` 
3. Ejecuta el generador leyendo desde ese archivo: ```bash ./ddf < sample.txt ``` 
4. Verás el diagrama de flujo en ASCII en tu consola. </pre>
