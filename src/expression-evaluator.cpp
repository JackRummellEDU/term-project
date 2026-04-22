/*
    Authors: Jack Rummell
    Description:
    
    Implementation of expression-evaliator.h

*/
#include "../lib/expression-evaluator.h"


double ExpressionEvaluator::eval(std::string exp){
    return LexicalLayer::eval(exp);
}