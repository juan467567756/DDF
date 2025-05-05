#pragma once
#include <string>
#include <ostream>

// ASCII helpers
void box(const std::string& text);
void arrow();
void decision(const std::string& question);
void loopStart(const std::string& label);
void loopEnd();
void elseBranch();

// Graphviz (.dot) output
void dotHeader(std::ostream& out);
void dotFooter(std::ostream& out);
void defineDotNode(std::ostream& out, const std::string& id, const std::string& label);
void defineDotEdge(std::ostream& out, const std::string& from, const std::string& to);
