#include <cctype>
#include <string>
#include "ExpressionError.h"
#include "Tokenizer.h"

Tokenizer::Tokenizer(const std::string& input) 
  :input_(input), position_(0){
}

bool Tokenizer::isAtEnd() const{
  return position_ >= input_.length();
}

char Tokenizer::peek() const{
  return isAtEnd() ? '\0' : input_.at(position_);
}

char Tokenizer::peekNext() const{
  return position_ + 1 >= input_.length() ? '\0' : input_.at(position_ + 1);
}

void Tokenizer::skipWhiteSpace(){
  while(!isAtEnd() && std::isspace(peek())){
    position_++;
  }
}

Token Tokenizer::readNum(){
  size_t start = position_;
  bool hasDecimal = false;
  
  while(!isAtEnd()){
    char current = peek();

    if(std::isdigit(current)){
      position_++;
    } else if (current == '.'){
      if(hasDecimal){
        throw ExpressionError("Invalid number: multiple decimals at position " + 
        std::to_string(position_));
      }
      hasDecimal = true;
      position_++;
    } else {
      break;
    }
  }

  std::string numString = input_.substr(start, position_ - start);

  return Token(TokenType::NUM, std::stod(numString));
}

Token Tokenizer::getNextToken(){
  skipWhiteSpace();

  if(isAtEnd()){
    return Token(TokenType::END);
  }

  char current = peek();

  if(std::isdigit(current) || (current == '.' && std::isdigit(peekNext()))){
    return readNum();
  }

  switch(current){
    case '(':
      position_++;
      return Token(TokenType::L_PAREN);
    case ')':
      position_++;
      return Token(TokenType::R_PAREN);
    case '*':
      if(peekNext() == '*'){
        position_ += 2;
        return Token(TokenType::POWER);
      } else {
        position_++;
        return Token(TokenType::MULTIPLY);
      }
    case '/':
      position_++;
      return Token(TokenType::DIVIDE);
    case '%':
      position_++;
      return Token(TokenType::MODULO); 
    case '+':
      position_++;
      return Token(TokenType::PLUS);
    case '-':
      position_++;
      return Token(TokenType::MINUS);
    default:
      throw ExpressionError(std::string("Unexpected character: '") + current + 
        "' at position: " + std::to_string(position_));
  }
}
