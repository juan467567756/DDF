#include "utils.h"
#include <iostream>

void box(const std::string& text)
{
    std::string line(text.size(), '-');
    std::cout << "+-" << line << "-+\n";
    std::cout << "| "  << text << " |\n";
    std::cout << "+-" << line << "-+\n";
}

void arrow()
{
    std::cout << "  |\n  v\n";
}

void decision(const std::string& question)
{
    box(question + " ?");
    std::cout << " / \\\n"
                 "v   v\n";
}

void loopStart(const std::string& label)
{
    box("LOOP: " + label);
    arrow();
}

void loopEnd()
{
    box("END LOOP");
    arrow();
}

void elseBranch()
{
    box("ELSE");
    arrow();
}

