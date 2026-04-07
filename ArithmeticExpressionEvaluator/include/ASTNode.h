#ifndef ASTNODE_H
#define ASTNODE_H

/**
 * @class ASTNode
 * @brief Abstract base class for a Abstract Syntax Tree.
 */
class ASTNode {
  public:
    /**
     * @brief Virtual destructor for safe deletion.
     */
    virtual ~ASTNode() = default;

    /**
     * @brief Evaluate the expression of this node.
     * @return The numeric result.
     */
    virtual double evaluate() const = 0;
};

#endif