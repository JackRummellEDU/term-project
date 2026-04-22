/*
    Authors: Dylan Richardson
    Description: Implementation of data types used in the evaluator.
    

*/

#include "../lib/data-types.h"



// Node class implementation:
Node::Node(Token value){
    this->value = value;
}

Node::Node(Token value, Node *leftChild){
    this->value = value;
    this->leftChild = leftChild;
}

Node::Node(Token value, Node *leftChild, Node *rightChild){
    this->value = value;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
}

Node* Node::getLeftChild() const{
    return this->leftChild;
}

Node* Node::getRightChild() const{
    return this->rightChild;
}

void Node::pushLeftChild(Node *child){
    this->leftChild = child;
}

void Node::pushRightChild(Node *child){
    this->rightChild = child;
}

// End Node Class implementation
// Begin AbstractSyntaxTree...

Node* AbstractSyntaxTree::getRoot() const{
    return this->root;
}

void AbstractSyntaxTree::setRoot(Node *newRoot){
    this->root = newRoot;
}



