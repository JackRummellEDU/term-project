/*
    Authors:
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
};