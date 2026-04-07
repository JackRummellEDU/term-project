#include "Token.h"

Token::Token(TokenType type) : type_(type), value_(0.0){  
}

Token::Token(TokenType type, double value) : type_(type), value_(value){
}

TokenType Token::getType() const{
  return type_;
}
double Token::getValue() const{
  return value_;
}