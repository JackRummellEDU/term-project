/*
    Authors:
    Description:
    
    This is the lexical layer of the expression evaluator. It is responsible for 
    validating input, building a list of tokens, and validating those tokens.

*/
#pragma once
#include "data-types.h"
#include "parse-layer.h"

const int MAX_TOKENS = 2048;

class LexicalLayer : public ParseLayer{
    protected:

    double eval(std::string);

    private:

    Token tokens[MAX_TOKENS];

    std::string removeWhitespace(std::string);
    std::string validateCharacters(std::string);
    void buildTokens(std::string);
    void validateToken(Token*);
};