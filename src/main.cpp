/*
    Authors: Jack Rummell
    Description:

    The main function reads in a string from the console and passes it to
    an instance of the expression evaluator
    
*/
#include <iostream>
#include <string>
#include "../lib/error.h"
#include "../lib/expression-evaluator.h"

using std::cout;
using std::cin;


int main(){
    ExpressionEvaluator a;
    std::string input;

    cout << "Input an expression\n";
    cin >> input;

    try{
        cout << a.eval(input) << "\n";
    }catch(Error e){
        // Handle errors
        e.log();
        return 1;
    }

    return 0;
}