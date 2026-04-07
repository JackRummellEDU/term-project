#ifndef BINARYOPNODE_H
#define BINARYOPNODE_H
#include "ASTNode.h"
#include "Token.h"

/**
 * @class BinaryOpNode
 * @brief ASTNode for binary arithmetic.
 * 
 * Stores an operator and two child nodes of an expression.
 */
class BinaryOpNode : public ASTNode{
  private:
    TokenType op_; /**< Operator for the child expressions. */
    ASTNode* leftChild_; /**< Pointer to the left subtree. */
    ASTNode* rightChild_; /**< Pointer to the right subtree. */

  public:
    /**
     * @brief Constructor.
     * @param op Binary operator for this BinaryOpNode.
     * @param leftChild Pointer to the left subtree.
     * @param rightChild Pointer to the right subtree.
     */
    BinaryOpNode(TokenType op, ASTNode* leftChild, ASTNode* rightChild);

    /**
     * @brief Destructor to safely delete child subtrees.
     */
    ~BinaryOpNode() override;

    /**
     * @brief Evaluates this binary operation.
     * @return The value from this binary operation.
     */
    double evaluate() const override;
};

#endif
