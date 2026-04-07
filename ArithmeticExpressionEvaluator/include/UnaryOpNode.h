#ifndef UNARYOPNODE_H
#define UNARYOPNODE_H
#include "ASTNode.h"
#include "Token.h"

/**
 * @class UnaryOpNode
 * @brief ASTNode for unary arithmetic.
 * 
 * Stores an unary operator and an operand it's applied to.
 */
class UnaryOpNode : public ASTNode {
  private:
    TokenType op_; /**< The unary operator applied to the operand. */
    ASTNode* operand_; /**< Pointer to the operand. */
    
  public:
  /**
   * @brief Constructor.
   * @param op The operator.
   * @param operand Pointer to the operand.
   */
  UnaryOpNode(TokenType op, ASTNode* operand);

  /**
   * @brief Destructor safely deletes it's subtree.
   */
  ~UnaryOpNode() override;

  /**
   * @brief Evaluates it's unary operation.
   * @return The value of this unary operation.
   */
  double evaluate() const override;
};

#endif