#include "parse-layer.h"
#include "../lib/error.h"
#include <string>
/*
    Author: Kevin Reilly
    Description: Recursively builds an Abstract Syntax Tree from an array of Tokens. 
*/

double ParseLayer::eval(Token* tokens){

}

void ParseLayer::buildAST(Token* tokens) {
    int index = 0; 
    Node* root = parseExpression(tokens, index);
    AST.setRoot(root);
}

Node* ParseLayer::parseExpression(Token* tokens, int& index) {
    Node* left = parseTerm(tokens, index);

    while (tokens[index].type == ADDOP || tokens[index].type == SUBOP) {
        Token opToken = tokens[index];
        index++;

        Node* right = parseTerm(tokens, index);

        left = new Node(opToken, left, right);
    }

    return left;
}

Node* ParseLayer::parseTerm(Token* tokens, int& index) {
    Node* left = parsePower(tokens, index);

    while (tokens[index].type == MULOP || tokens[index].type == DIVOP){
        Token opToken = tokens[index];
        index++;

        Node* right = parsePower(tokens, index);
        left = new Node(opToken, left, right);
    }

    return left;
}

Node* ParseLayer::parsePower(Token* tokens, int& index) {
    Node* left = parseUnary(tokens, index);

    if(tokens[index].type == EXPOP) {
        Token opToken = tokens[index];
        index++;
        Node* right = parsePower(tokens, index);
        left = new Node(opToken, left, right);
    }

    return left;
}

Node* ParseLayer::parseUnary(Token* tokens, int& index) {
    if(tokens[index].type == UNARYOP){
        Token opToken = tokens[index];
        index++;
        Node* child = parseUnary(tokens, index);

        return new Node(opToken, child);
    }

    return parsePrimary(tokens, index);
}

Node* ParseLayer::parsePrimary(Token* tokens, int& index) {
    if(tokens[index].type == NUMBER) {
        Token number = tokens[index];
        index++;
        return new Node(number);
    }

    if (tokens[index].type == L_PAREN) {
        index++;
        Node* insideParens = parseExpression(tokens, index);

        if (tokens[index].type != R_PAREN) {
            throw Error(ODDPAREN, "Odd number of parentheses");
        }
        index++;
        return insideParens;
    }
    throw Error(MISSOPERAND, "Expected a number or '('");
}