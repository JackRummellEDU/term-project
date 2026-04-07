#include "UnaryOpNode.h"
#include "ExpressionError.h"

UnaryOpNode::UnaryOpNode(TokenType op, ASTNode* operand) 
  :op_(op), operand_(operand){    
}

UnaryOpNode::~UnaryOpNode() {
  delete operand_;
}

double UnaryOpNode::evaluate() const{
  double value = operand_->evaluate();

  switch (op_) {
    case TokenType::PLUS:
      return value;
    case TokenType::MINUS:
      return -value;
    default:
      throw ExpressionError("Invalid unary operator");
  }

}
