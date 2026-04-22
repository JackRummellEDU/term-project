/*
    Authors: Jack Rummell
    Description:
    
    This class is the interface layer of the expression evaluator

*/
#pragma once
#include <string>
#include "lexical-layer.h"


class ExpressionEvaluator : public LexicalLayer{
    public:

    double eval(std::string);
};