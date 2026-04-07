#include "Parser.h"
#include "ExpressionError.h"
#include <iostream>
#include <string>

int main() {
  std::string input;
  std::cout << ">";
  std::getline(std::cin, input);

  try {
    Parser parser(input);
    ASTNode* root = parser.parse();
    double result = root->evaluate();
    std::cout << result << std::endl;
    delete root;
  } catch (const ExpressionError& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}