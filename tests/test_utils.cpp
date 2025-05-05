#include "../src/utils.h"
#include <gtest/gtest.h>
#include <sstream>

// Captura la salida de box()
std::string captureBox(const std::string& text) {
    std::ostringstream ss;
    auto* old = std::cout.rdbuf(ss.rdbuf());
    box(text);
    std::cout.rdbuf(old);
    return ss.str();
}

TEST(UtilsTest, BoxFramesText) {
    std::string out = captureBox("X");
    EXPECT_NE(out.find("+-X-+"), std::string::npos);
    EXPECT_NE(out.find("| X |"), std::string::npos);
}
