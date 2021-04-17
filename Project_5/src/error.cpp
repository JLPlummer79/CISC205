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
int checkSingleInt(std::string input) {
    // declare variables
    char s;             //holds single char
    int num;            //holds validated entry

    //loop until valid entry is entered
    while(input.size() > 1 || input.size() <= 0) {
        std::cout << "Entry invalid. "
        << "Please enter a single non-zero number "
        << "from the menu.\n";

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
// name: checkSingleChar
// called by: 
// passed: std::string
// returns: char
// The 'name' function 'what function does'             *
//*******************************************************
char checkSingleChar(std::string input) {
    
    char s;

    while(input.length() > 1 || input.empty()) {
        std::cout << "Entry invalid. "
        << "Please enter a single non-zero "
        << "character.\n";

        //get user input
        std::getline(std::cin, input);
    }
    //convert string to char
    std::istringstream i(input);
    i >> s;

    //return valid char
    return s;
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
// name: validateString
// called by: enterSea
// passed: std::string
// returns: std::string
// The validateString function ensures that the argument*
// Meets the requirements of the sea name specification:*
// 1. It is 20 characters or less, 2. It is not empty.  *
// Once these conditions are met the string returns.    *
//*******************************************************
std::string validateString(std::string input) {
    while( input.size() > 20 || input.empty() ) {
        std::cout << "The entry is invalid."
        << "Please enter a non-empty value less"
        << "than or equal 20 characters.\n";
    }
    //return a valid string
    return input;
}

//*******************************************************
// name: checkValidInteger
// called by: checkValidFloat
// passed: const std::string
// returns: bool
// The 'name' function 'what function does'             *
//*******************************************************
bool checkValidInteger(const std::string num) {
    //validate num
    for (size_t j = 0; j < num.size(); ++j) {
        //entry is decimal, skip the next part
        if(num[j] == '.'){
            continue;
        }
        //entry is not a digit, return false
        if(!isdigit(num[j])) {
            return false;
        }
    }//end for
    // number is valid
    return true;
}//end checkValidInteger

float checkValidFloat(std::string num) {
    //the reason for less than 10 characters long is to
    //ensure the resulting float is not beyond the max
    //capacity of a float.
    while(num.empty() || !checkValidInteger(num) || 
    num.length() > 10) {
        std::cout << "The entry is invalid.  "
        << "Please make your entry non-empty and less "
        << "than 10 digits long.\n";
        std::getline(std::cin, num);
    }
    //convert num to a float and return the value
    return stof(num);

}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************