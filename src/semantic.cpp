#include "semantic.hpp"
#include "ast.hpp"
#include <stack>
#include <string>

void validateSemantics(const AST& ast) {
  std::stack<bool> loopStack;
  bool sawDecide = false;

  for (size_t i = 0; i < ast.size(); ++i) {
    auto& node = ast[i];

    if (dynamic_cast<LoopNode*>(node.get())) {
      loopStack.push(true);
      sawDecide = false;
    }
    else if (dynamic_cast<EndLoopNode*>(node.get())) {
      if (loopStack.empty())
        throw SemanticError("ENDLOOP sin LOOP en posición " + std::to_string(i));
      loopStack.pop();
    }
    else if (dynamic_cast<DecisionNode*>(node.get())) {
      sawDecide = true;
    }
    else if (dynamic_cast<ElseNode*>(node.get())) {
      if (!sawDecide)
        throw SemanticError("ELSE sin DECIDE previo en posición " + std::to_string(i));
      sawDecide = false;  // sólo un ELSE por DECIDE
    }
    // El resto de nodos no influyen semánticamente
  }

  if (!loopStack.empty())
    throw SemanticError("Faltan ENDLOOP para " + std::to_string(loopStack.size()) + " bucle(s)");
}
