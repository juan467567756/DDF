# Gramática del mini-lenguaje DDF

Usaremos una sintaxis BNF extendida:

<program> ::= { <statement> }
<statement> ::= BOX <texto>
| ARROW
| DECIDE <condición>
| ELSE
| LOOP <etiqueta>
| ENDLOOP

<texto> ::= cadena_de_caracteres ; todo lo que sigue en la línea
<condición> ::= cadena_de_caracteres ; expresión booleana en forma de texto
<etiqueta> ::= cadena_de_caracteres ; etiqueta para bucles

- **`{…}`** significa “repetir cero o más veces”  
- Los literales (BOX, ARROW, …) son keywords **en mayúsculas**  
- El parser debe ignorar líneas vacías y comentarios que empiecen con `#`

## Casos de ejemplo

1. **Secuencia simple**  

BOX INICIO
ARROW
BOX FIN


2. **Decisión con else**  

BOX INICIO
DECIDE X > 0
BOX Positivo
ELSE
BOX No positivo
ENDLOOP ; esto es un error: ENDLOOP sin LOOP


3. **Bucle**  


LOOP contador
BOX Repetir
ENDLOOP

  GNU nano 8.3                           docs/grammar.md                           Modified
# Gramática del mini-lenguaje DDF

Usaremos una sintaxis BNF extendida:

<program> ::= { <statement> }
<statement> ::= BOX <texto>
| ARROW
| DECIDE <condición>
| ELSE
| LOOP <etiqueta>
| ENDLOOP

<texto> ::= cadena_de_caracteres ; todo lo que sigue en la línea
<condición> ::= cadena_de_caracteres ; expresión booleana en forma de texto
<etiqueta> ::= cadena_de_caracteres ; etiqueta para bucles

- **`{…}`** significa “repetir cero o más veces”
- Los literales (BOX, ARROW, …) son keywords **en mayúsculas**
- El parser debe ignorar líneas vacías y comentarios que empiecen con `#`

## Casos de ejemplo

1. **Secuencia simple**

BOX INICIO
ARROW
BOX FIN


2. **Decisión con else**

BOX INICIO
DECIDE X > 0
BOX Positivo
ELSE
BOX No positivo
ENDLOOP ; esto es un error: ENDLOOP sin LOOP


3. **Bucle**


LOOP contador
BOX Repetir
ENDLOOP


## Errores de sintaxis

- Keyword desconocido  
- ELSE sin DECIDE previo  
- ENDLOOP sin LOOP previo  
- Texto vacío después de BOX/DECIDE/LOOP


