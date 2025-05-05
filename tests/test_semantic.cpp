#include "../src/semantic.hpp"
#include "../src/parser.hpp"
#include <gtest/gtest.h>
#include <sstream>

AST parseStr(const std::string& s) {
  return parseProgram(*(new std::istringstream(s)));
}

TEST(SemanticTest, ElseWithoutDecide) {
  AST ast = parseStr("ELSE");
  EXPECT_THROW(validateSemantics(ast), SemanticError);
}

TEST(SemanticTest, EndLoopWithoutLoop) {
  AST ast = parseStr("ENDLOOP");
  EXPECT_THROW(validateSemantics(ast), SemanticError);
}

TEST(SemanticTest, UnclosedLoop) {
  AST ast = parseStr("LOOP X");
  EXPECT_THROW(validateSemantics(ast), SemanticError);
}

TEST(SemanticTest, ValidNested) {
  AST ast = parseStr("LOOP A\nBOX X\nENDLOOP\nDECIDE Y\nELSE\nBOX Z");
  EXPECT_NO_THROW(validateSemantics(ast));
}
