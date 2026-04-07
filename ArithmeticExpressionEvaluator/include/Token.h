#ifndef TOKEN_H
#define TOKEN_H

/**
 * @enum TokenType
 * @brief The different token types for the tokenizer.
 */
enum class TokenType {
  NUM, /**< A numeric literal */
  L_PAREN, /**< Left parenthesis */
  R_PAREN, /**< Right parenthesis */
  POWER, /**< Exponent operator */
  MULTIPLY, /**< Multiplication operator */
  DIVIDE, /**< Division operator */
  PLUS, /**< Addition operator */
  MINUS, /**< Subtraction opertor */
  MODULO, /**< Modulus operator */
  END /**< Marks the end of input */
};

/**
 * @class Token
 * @brief A single token from the input expression.
 */
class Token {
  private:
    TokenType type_; /**< The TokenType for this Token. */
    double value_; /**< Numeric value of this token. */

  public:
    /**
     * @brief Constructor with a type.
     * @param type The token type.
     */
    explicit Token(TokenType type);

    /**
     * @brief Constructor with a type and a value.
     * @param type The token type.
     * @param value The numeric value.
     */
    explicit Token(TokenType type, double value);

    /**
     * @brief Gets the type of this token.
     * @return The token type.
     */
    TokenType getType() const;

    /**
     * @brief Gets the value of this token.
     * @return The value stored in this token.
     */
    double getValue() const;
};

#endif