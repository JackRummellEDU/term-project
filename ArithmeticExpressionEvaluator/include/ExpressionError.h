#ifndef EXPRESSIONERROR_H
#define EXPRESSIONERROR_H
#include <stdexcept>
#include <string>

/**
 * @class ExpressionError
 * @brief Errors that occur during parsing or evaluation an arithmetic expression.
 * 
 * This class derives from std::runtime_error in order to report errors with a descriptive message.
 */
class ExpressionError : public std::runtime_error {
    public:
        /**
         * @brief Constructor
         * 
         * @param message A message describing the expression error.
         */
        explicit ExpressionError(const std::string& message);       
};

#endif