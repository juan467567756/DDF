#include "../src/parser.hpp"   
#include <gtest/gtest.h>

// Cada TEST describe un caso de la gramática
TEST(ParserTest, EmptyProgram) {
  // TODO: invocar el parser con "" y esperar programa vacío
  SUCCEED();
}

TEST(ParserTest, SingleBox) {
  // TODO: invocar parser("BOX Hola") y comprobar AST con un BoxNode("Hola")
  SUCCEED();
}

TEST(ParserTest, DecisionElseLoopErrors) {
  // TODO: cada error sintáctico debe lanzar ParserError con línea y razón
  SUCCEED();
}
