#ifndef NUMBERNODE_H
#define NUMBERNODE_H
#include "ASTNode.h"

/**
 * @class NumberNode
 * @brief An ASTNode for a numeric literal.
 * 
 * A NumberNode stores a numeric value and evaluates it.
 */
class NumberNode : public ASTNode {
  private:
    double value_; /**< The value stored in this NumberNode. */
    
  public:
    /**
     * @brief Constructor
     * 
     * @param value The numeric literal for this node.
     */
    explicit NumberNode(double value);

    /**
     * @brief Returns the value of this node.
     * 
     * @return The stored number.
     */
    double evaluate() const override;
};

#endif