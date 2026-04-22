/*
    Authors:
    Description:
    
    This is the evaluation layer of the expression evaluator. It is responsible for 
    evaluating the abstract syntax tree

*/
#pragma once
#include "data-types.h"


class EvaluationLayer{
    protected:

    double eval(AbstractSyntaxTree*);

    private:

    double evalAddOrSub(Token*);
    double evalMultDivMod(Token*);
    double evalExpo(Token*);
};