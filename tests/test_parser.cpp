#include "../src/parser.hpp"
#include <gtest/gtest.h>
#include <sstream>

// Helper
static AST parseStr(const std::string& s) {
    std::istringstream iss(s);
    return parseProgram(iss);
}

TEST(ParserTest, ParseBoxAndArrow) {
    AST ast = parseStr("BOX A\nARROW\nBOX B");
    ASSERT_EQ(ast.size(), 3);
    EXPECT_TRUE(dynamic_cast<BoxNode*>(ast[0].get()) != nullptr);
    EXPECT_TRUE(dynamic_cast<ArrowNode*>(ast[1].get()) != nullptr);
    EXPECT_TRUE(dynamic_cast<BoxNode*>(ast[2].get()) != nullptr);
}

TEST(ParserTest, ErrorUnknownKeyword) {
    EXPECT_THROW(parseStr("FOO"), ParserError);
}
