#ifndef DDF_AST_HPP
#define DDF_AST_HPP

#include <string>
#include <memory>
#include <vector>

struct Node {
    virtual ~Node() = default;
};

struct BoxNode : Node {
    std::string text;
    explicit BoxNode(const std::string& t)
        : text(t)
    {}
};

struct DecisionNode : Node {
    std::string condition;
    explicit DecisionNode(const std::string& c)
        : condition(c)
    {}
};

struct LoopNode : Node {
    std::string label;
    explicit LoopNode(const std::string& l)
        : label(l)
    {}
};

#endif // DDF_AST_HPP
