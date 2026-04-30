/*
    Authors: 
    Gabriel Gonzalez
    
    Description:
    This is the lexical layer of the expression evaluator. It is responsible for taking a raw input string, stripping whitespace,validating characters, and building a list of tokens.
    After the tokenization is complete it then passes the token list to the parse layer and returns the result.

*/

#include "lexical-layer.h"
#include "error/error.h"
#include<cctype>

double LexicalLayer::eval(std::string input) {
    /*
        Removes the whitespace of the string, then runs it through validateCharacters and once confirmed that it is all valid, the string is then moved to build the tokens, then passes it to ParseLayer::eval.
    */
    std::string cleaned = removeWhitespace(input);
    cleaned = validateCharacters(cleaned);
    buildTokens(cleaned);
    return ParseLayer::eval(tokens);
}

std::string LexicalLayer::removeWhitespace(std::string input){
    /*
        Removes all the whitespace of the string character by character.
    */
    std::string result = "";
    for (char c: input){
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r'){
            result += c;
        }
    }
    return result;
}

std::string LexicalLayer::validateCharacters(std::string input){
    /*
        Loops through the input string and checks if is all valid characters, if not it throws the INVCHAR error. 
    */
    for(int i=0;i<(int)input.size();i++){
        char c =input[i];
        bool valid = std::isdigit(c)
            || c == '+'
            || c == '-'
            || c == '*'
            || c == '/'
            || c == '^'
            || c == '('
            || c == ')'
            || c == '.';
        if (!valid) {
            throw Error(INVCHAR,
                "Invalid character '" + std::string(1,c) + "' at position " + std::to_string(i) + ".");
        }
    }
    return input;
}

void LexicalLayer::buildTokens(std::string input) {
    /*
        Keeps track of token count and loops through the input and categorizes each character based on what it is.
        At the end it writes a sentinel token to signal that the token stream is finished.
    */
    tokenCount = 0;
    for (int i =0;i <(int)input.size(); i++) {
        if (tokenCount >= MAX_TOKENS) {
            throw Error (INVRANGE, "Token limit exceeded. Maximum is " + std::to_string(MAX_TOKENS) + " tokens.");
        }
        char c = input[i];
        Token t;
        t.value = std::string(1,c);
        t.position = i;
        if (std::isdigit(c)) {
            t.type = NUMBER;
        } else if (c == '.') {
            t.type = NUMBER;
        } else if (c == '+') {
            t.type = ADDOP;
        } else if (c == '-') {
            bool isUnary = (i == 0) || (tokens[tokenCount -1].type == L_PAREN);
            t.type = isUnary ? UNARYOP: SUBOP;
        } else if (c == '*') {
            t.type = MULOP;
        } else if (c == '/') {
            t.type = DIVOP;
        } else if (c == '^') {
            t.type = EXPOP;
        } else if (c == '(') {
            t.type = L_PAREN;
        } else if (c == ')'){
            t.type = R_PAREN;
        }
        validateToken(&t);
        tokens[tokenCount ++] = t;
    }
    tokens[tokenCount].type = NUMBER;
    tokens[tokenCount].value = "";
    tokens[tokenCount].position = (int)input.size();
}

void LexicalLayer::validateToken(Token*t) {
    /*
        Checks to see if a '.' is after a number and if not throws a INVCHAR error.
        Then checks to see if there are two consecutive binary operators and if there are it throws a MISSOPERAND error.
    */
    if (t -> value == "." && tokenCount > 0) {
        if (tokens[tokenCount -1].type != NUMBER) {
            throw Error(INVCHAR, "Unexpected '.' at position " + std::to_string(t -> position) + ".");
        }
    }
    if (tokenCount > 0) {
        Operations prev = tokens[tokenCount - 1].type;
        Operations curr = t -> type;

        bool currIsBinaryOp = (curr == ADDOP || curr == SUBOP || curr == MULOP || curr == DIVOP || curr == EXPOP);
        bool prevIsBinaryOp = (prev == ADDOP || prev == SUBOP || prev == MULOP || prev == DIVOP || prev == EXPOP);

        if (prevIsBinaryOp && currIsBinaryOp) {
            throw Error(MISSOPERAND, "Missing operand at position " + std::to_string(t -> position) + ".");
        }
    }
}