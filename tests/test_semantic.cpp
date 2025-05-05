#include "../src/parser.hpp"
#include "../src/semantic.hpp"
#include <gtest/gtest.h>
#include <sstream>

// Helper
static AST parseStr(const std::string& s) {
    std::istringstream iss(s);
    return parseProgram(iss);
}

TEST(SemanticTest, ElseWithoutDecide) {
    AST ast = parseStr("ELSE");
    EXPECT_THROW(validateSemantics(ast), SemanticError);
}

TEST(SemanticTest, UnmatchedLoop) {
    AST ast = parseStr("ENDLOOP");
    EXPECT_THROW(validateSemantics(ast), SemanticError);
}

TEST(SemanticTest, ValidProgram) {
    AST ast = parseStr("LOOP X\nENDLOOP\nDECIDE A\nELSE");
    EXPECT_NO_THROW(validateSemantics(ast));
}
