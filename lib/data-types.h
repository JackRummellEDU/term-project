/*
    Authors: Dylan Richardson
    Description: Header file declaring important structs/classes for project.
    VERSION: v0.2

    REMINDER: This is an early development build. This may change, as the functionality
    or requirements change to better suit the development of the parser and lexer.

*/
#pragma once
#include <string>


// Token Types will be defined as an enum.
enum Operations { NUMBER,
     ADDOP,
     SUBOP,
     MULOP,
     DIVOP,
     EXPOP,
     UNARYOP,
     MODOP,
     L_PAREN,
     R_PAREN
} typedef Operations;


// Struct can contained within header file as no methods are required.
struct Token{
    Operations type;

    // Numbers are considered strings until checked later in parsing.
    std::string value;
    int position;
};


class Node{
    private:

	Token value;

	// children split into two distinct children.
    	Node *leftChild;
	Node *rightChild;

    public:
	Node(Token value);
	Node(Token value, Node *leftChild);
	Node(Token value, Node *leftChild, Node *rightChild);

	Node *getLeftChild() const;
	Node *getRightChild() const;
	void pushLeftChild(Node *child);
	void pushRightChild(Node *child);
};

class AbstractSyntaxTree{
    public:
	Node *getRoot() const;
	void setRoot(Node *newRoot);
	// addChild method excluded for, as I am unsure how it would be
	// implemented besides just using the Node class to add children.


    private:
	Node *root;


};
