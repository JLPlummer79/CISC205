/*
 *
 * Jesse Plummer
 *
 * Chapter 14, Programming Challenge #5 Sea Pollution
 *
 * April 19th, 2021
 * 
*/

#include "error.h"
#include <string>
#include <iostream>
#include <sstream>

//*******************************************************
// name: checkSingleChar
// called by: menu
// passed: std::string
// returns: int
// The 'name' function 'what function does'             *
//*******************************************************
int checkSingleChar(std::string input) {
    // declare variables
    char s;             //holds single char
    int num;            //holds validated entry

    //loop until valid entry is entered
    while(input.size() > 1 || input.size() <= 0) {
        std::cout << "Entry invalid. "
        << "Please enter a single non-zero number " 
        << "from the menu: ";

        //get user input
        std::getline(std::cin, input);
    }
    //convert string to char
    std::istringstream i(input);
    i >> s;
    
    //validate if s is an int
    num = checkIfInteger(s);

    //return valid entry if int, 0 if invalid
    return num;    
}//end checkSingleChar

//*******************************************************
// name: checkIfInteger
// called by: checkSingleChar
// passed: const char&
// returns: int
// The 'name' function 'what function does'             *
//*******************************************************
int checkIfInteger(const char& input) {
        //will hold number if verified
        int digit;
        //checks if the input is a digit
        //converts it to an int, then returns 
        if(std::isdigit(input)) {
            digit = input - '0';
            return digit;
        }
        //returns a invalid answer 
        else {
            return 0;
        }
}//end checkIfInteger

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************