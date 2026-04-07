#include "Parser.h"
#include "ExpressionError.h"
#include "NumberNode.h"
#include "UnaryOpNode.h"
#include "BinaryOpNode.h"

Parser::Parser(const std::string& input)
  : tokenizer_(input), currentToken_(TokenType::END) {
    advance();
}

void Parser::advance() {
  currentToken_ = tokenizer_.getNextToken();
}

void Parser::expect(TokenType expectedType){
  if(currentToken_.getType() != expectedType) {
    throw ExpressionError("Unexpected token");
  }
  advance();
}

ASTNode* Parser::parse() {
  ASTNode* root = parseExpression();

  if(currentToken_.getType() != TokenType::END) {
    delete root;
    throw ExpressionError("Unexpected token after expression");
  }

  return root;
}

ASTNode* Parser::parseExpression() {
  ASTNode* left = parseTerm();

  while(currentToken_.getType() == TokenType::PLUS || 
        currentToken_.getType() == TokenType::MINUS){
    TokenType op = currentToken_.getType();
    advance();

    ASTNode* right = parseTerm();
    left = new BinaryOpNode(op, left, right);
  }

  return left;
}

ASTNode* Parser::parseTerm() {
  ASTNode* left = parsePower();

  while (currentToken_.getType() == TokenType::MULTIPLY || 
         currentToken_.getType() == TokenType::DIVIDE ||
         currentToken_.getType() == TokenType::MODULO){
      TokenType op = currentToken_.getType();
      advance();

      ASTNode* right = parsePower();
      left = new BinaryOpNode(op, left, right);
    }
  
    return left;
}

ASTNode* Parser::parsePower() {
  ASTNode* left = parseUnary();

  TokenType op = currentToken_.getType();
  if (op == TokenType::POWER) {
    advance();

    ASTNode* right = parsePower();
    left = new BinaryOpNode(op, left, right);
  }

  return left;
}

ASTNode* Parser::parseUnary() {
  TokenType op = currentToken_.getType();
  if (op == TokenType::PLUS || op == TokenType::MINUS){
    advance();

    ASTNode* operand = parseUnary();
    return new UnaryOpNode(op, operand);
  }

  return parsePrimary();
}

ASTNode* Parser::parsePrimary() {
  TokenType type = currentToken_.getType();

  if (type == TokenType::NUM) {
    double value = currentToken_.getValue();
    advance();

    return new NumberNode(value);
  } else if (type == TokenType::L_PAREN){
    advance();
    
    ASTNode* expression = parseExpression();
    expect(TokenType::R_PAREN);

    return expression;
  } else {
    throw ExpressionError("Expected number or '('");
  }
}