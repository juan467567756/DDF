#pragma once
#include <string>
#include <ostream>

// ASCII diagram helpers
void box(const std::string& text);
void arrow();
void decision(const std::string& question);
void loopStart(const std::string& label);
void loopEnd();
void elseBranch();

// Graphviz (.dot) output
void dotHeader(std::ostream& out);
