#include "../src/parser.hpp"
#include <gtest/gtest.h>
#include <sstream>

AST parseStr(const std::string& input) {
    std::istringstream iss(input);
    return parseProgram(iss);
}

TEST(ParserTest, ParseBoxAndArrow) {
    AST ast = parseStr("BOX Inicio\nARROW\nBOX Fin");
    ASSERT_EQ(ast.size(), 3);
    EXPECT_NE(dynamic_cast<BoxNode*>(ast[0].get()), nullptr);
    EXPECT_NE(dynamic_cast<ArrowNode*>(ast[1].get()), nullptr);
    EXPECT_NE(dynamic_cast<BoxNode*>(ast[2].get()), nullptr);
}

TEST(ParserTest, ParseDecisionAndElse) {
    AST ast = parseStr("DECIDE X > 0\nBOX Positivo\nELSE\nBOX Negativo");
    ASSERT_EQ(ast.size(), 4);
    EXPECT_NE(dynamic_cast<DecisionNode*>(ast[0].get()), nullptr);
    EXPECT_NE(dynamic_cast<BoxNode*>(ast[1].get()), nullptr);
    EXPECT_NE(dynamic_cast<ElseNode*>(ast[2].get()), nullptr);
    EXPECT_NE(dynamic_cast<BoxNode*>(ast[3].get()), nullptr);
}

TEST(ParserTest, ParseLoop) {
    AST ast = parseStr("LOOP repetir\nBOX Acción\nENDLOOP");
    ASSERT_EQ(ast.size(), 3);
    EXPECT_NE(dynamic_cast<LoopNode*>(ast[0].get()), nullptr);
    EXPECT_NE(dynamic_cast<BoxNode*>(ast[1].get()), nullptr);
    EXPECT_NE(dynamic_cast<EndLoopNode*>(ast[2].get()), nullptr);
}

TEST(ParserTest, ParseInvalidKeyword) {
    EXPECT_THROW(parseStr("FOOBAR"), ParserError);
}

TEST(ParserTest, ParseMissingText) {
    EXPECT_THROW(parseStr("BOX"), ParserError);
    EXPECT_THROW(parseStr("DECIDE"), ParserError);
    EXPECT_THROW(parseStr("LOOP"), ParserError);
}

