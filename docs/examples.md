# Ejemplos de diagramas de flujo

## Ejemplo 1: Comparar paridad

**Archivo `example1.txt`:**

BOX INICIO
ARROW
BOX Leer X
ARROW
DECIDE X % 2 == 0
BOX Par
ARROW
BOX FIN


**Salida esperada:**

+-------+
| INICIO |
+-------+
|
v
+--------+
| Leer X |
+--------+
|
v
+-------------+
| X % 2 == 0 ? |
+-------------+
/
v v
+-----+
| Par |
+-----+
|
v
+-----+
| FIN |
+-----+


## Ejemplo 2: Número mayor que 10

**Archivo `example2.txt`:**

BOX INICIO
ARROW
BOX Ingresar X
ARROW
DECIDE X > 10
BOX Grande
ARROW
BOX Pequeño
ARROW
BOX FIN


**Salida esperada:**

+-------+
| INICIO |
+-------+
|
v
+--------------+
| Ingresar X |
+--------------+
|
v
+-----------+
| X > 10 ? |
+-----------+
/
v v
+-------+
| Grande |
+-------+
|
v
+---------+
| Pequeño |
+---------+
|
v
+-----+
| FIN |
+-----+


