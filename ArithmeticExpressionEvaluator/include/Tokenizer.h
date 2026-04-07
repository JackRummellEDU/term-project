#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <cstddef>
#include <string>
#include "Token.h"

/**
 * @class Tokenizer
 * @brief Converts an input into tokens.
 */
class Tokenizer {
  private:
    std::string input_; /**< The expression to be tokenized. */
    std::size_t position_; /**< Current position inside the input. */

    /**
     * @brief Skips any whitespace in the input.
     */
    void skipWhiteSpace();

    /**
     * @brief Reads the numeric literal at the current position.
     * @return A NUM token.
     */
    Token readNum();

    /**
     * @brief Returns the current character without increasing position.
     * @return The current character or '\0' if at the end.
     */
    char peek() const;

    /**
     * @brief Returns the next character without increasing position.
     * @return The next character or '\0' if at the end.
     */
    char peekNext() const;

    /**
     * @brief Checks if Tokenizer is at the end of the input.
     * @return If at the end True otherwise False.
     */
    bool isAtEnd() const;
    
  public:
    /**
     * @brief Constructor
     * @param input The expression string.
     */
    explicit Tokenizer(const std::string& input);

    /**
     * @brief Returns the next Token from the input.
     * @return The next Token.
     */
    Token getNextToken();
};

#endif