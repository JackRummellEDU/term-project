#include "ExpressionError.h"

ExpressionError::ExpressionError(const std::string& message) : std::runtime_error(message) {
}