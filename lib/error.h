/*
    Authors: Jack Rummell
    Description:
    
    This package provides an error class to be thrown and caught in a try catch block.
    It also provides error types to check against when caught.

*/
#pragma once
#include <string>
#include <iostream>

const int 
    INVRANGE = 0, 
    DIVBYZERO = 1, 
    INVCHAR = 2, 
    MISSOPERAND = 3, 
    MISSOPERATOR = 4, 
    ODDPAREN = 5;

class Error{
    public:

    Error(int type, std::string message);

    void log();

    private:

    int type;
    std::string message;
};