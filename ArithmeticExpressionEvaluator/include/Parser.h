#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "Tokenizer.h"
#include "Token.h"
#include "ASTNode.h"

/**
 * @class Parser
 * @brief Uses recursion to parse an expression into an Abstract Syntax Tree.
 */
class Parser {
  private:
    Tokenizer tokenizer_; /**< Tokenizer for getting tokens from the input expression. */
    Token currentToken_; /**< Current token to be processed. */

    /**
     * @brief Parses an expression of addition or subtraction.
     * @return A pointer to a subtree.
     */
    ASTNode* parseExpression();

    /**
     * @brief Parses a term of multiplication, division, modulo.
     * @return A pointer to a subtree.
     */
    ASTNode* parseTerm();

    /**
     * @brief Parses an exponent.
     * @return A pointer to a subtree.
     */
    ASTNode* parsePower();

    /**
     * @brief Parses a unary operator.
     * @return A pointer to a subtree.
     */
    ASTNode* parseUnary();

    /**
     * @brief Parses a primary expression such as a number or  parenthesized expression.
     */
    ASTNode* parsePrimary();

    /**
     * @brief Advances to the next token.
     */
    void advance();

    /**
     * @brief Checks that the current token matches the expected token type.
     * @param expectedType: The TokenType that is expected.
     */
    void expect(TokenType expectedType);

  public:
    /**
     * @brief Constructor.
     * @param input: Input string of an expression.
     */
    explicit Parser(const std::string& input);

    /**
     * @brief Parses the input string and returns an Abstract Syntax Tree.
     * @return A pointer to the root node of the Abstract Syntax Tree.
     */
    ASTNode* parse();
};

#endif