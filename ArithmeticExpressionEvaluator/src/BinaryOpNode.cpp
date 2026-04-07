#include "BinaryOpNode.h"
#include "ExpressionError.h"
#include <cmath>

BinaryOpNode::BinaryOpNode(TokenType op, ASTNode* leftChild, ASTNode* rightChild)
  :op_(op), leftChild_(leftChild), rightChild_(rightChild){
  }

BinaryOpNode::~BinaryOpNode(){
  delete leftChild_;
  delete rightChild_;
}

double BinaryOpNode::evaluate() const{
  double leftValue = leftChild_->evaluate();
  double rightValue = rightChild_->evaluate();

  switch(op_) {
    case TokenType::PLUS:
      return leftValue + rightValue;
    case TokenType::MINUS:
      return leftValue - rightValue;
    case TokenType::MULTIPLY:
      return leftValue * rightValue;
    case TokenType::DIVIDE:
      if (rightValue == 0.0){
        throw ExpressionError("Division by zero");
      }
      return leftValue / rightValue;
    case TokenType::MODULO:
      if (rightValue == 0.0){
        throw ExpressionError("Modulo by zero");
      }
      return std::fmod(leftValue, rightValue);
    case TokenType::POWER:
      return std::pow(leftValue, rightValue);
    default:
      throw ExpressionError("Invalid binary operator");
  }
}