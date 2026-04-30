/*
    Authors:Kevin Reilly
    Description:
    
    This is the parse layer of the expression evaluator. It is responsible for using
    a list of tokens to build an abstract syntax tree.

*/
#pragma once
#include "evaluation-layer.h"
#include "data-types.h"

class ParseLayer : public EvaluationLayer{
    protected:

    double eval(Token*);

    private:

    AbstractSyntaxTree AST;

    void buildAST(Token*); 
    
    //Helper functions for building the AST
    Node* parseExpression(Token* tokens, int& index);
    Node* parseTerm(Token* tokens, int& index);
    Node* parsePower(Token* tokens, int& index);
    Node* parseUnary(Token* tokens, int& index);
    Node* parsePrimary(Token* tokens, int& index);
};