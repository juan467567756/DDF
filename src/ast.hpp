#pragma once
#include <string>
#include <memory>
#include <vector>

// Nodo base
struct Node {
    virtual ~Node() = default;
};

// Cada tipo de statement hereda de Node
struct BoxNode      : Node { std::string text;        BoxNode(const std::string& t): text(t) {} };
struct ArrowNode    : Node {                                  };
struct DecisionNode : Node { std::string condition; BoxNode(const std::string& c): condition(c) {} };
struct ElseNode     : Node {                                  };
struct LoopNode     : Node { std::string label;     LoopNode(const std::string& l): label(l) {} };
struct EndLoopNode  : Node {                                  };

// Un programa es simplemente una secuencia de nodos
using AST = std::vector<std::unique_ptr<Node>>;
