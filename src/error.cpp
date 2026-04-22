/*
    Authors: Jack Rummell
    Description:
    
    Implementation of error.h

*/
#include "../lib/error.h"

Error::Error(int type, std::string message) :
type(type),
message(message){}

void Error::log(){
    std::cout << "ERROR: " << message << "\n";
}