/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#include "error.h"
#include <iostream>
#include <string>
#include <sstream>


//*******************************************************
// name: checkIfInteger
// called by: checkSingleChar
// passed: const char&
// returns: int
// The checkIfInteger function checks if the argument   *
// is in fact a digit.  If this is true, input is       *
// is converted to an int by subtracting the ASCII value*
// '0'.  If it is not a digit, 0 is returned.  Note: it *
// is understood that 0 is a valid integer, but in the  *
// case of the program requirments, the user entered    *
// value needs to be greater than 0.                    *
//*******************************************************
int checkIfInteger(const char &input){
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
}

//*******************************************************
// name: checkSingleChar
// called by: menu, editCustomerMenu
// passed: std::string 
// returns: int
// The checkSingleChar function ensures that the string *
// argument is valid.  Once it is validated, the input  *
// placed in a char and passed to checkIfInteger for    *
// validation.  Once that is returned, the valid int is *
// returned.                                            *
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
// name: validateName
// called by: addNewCustomer, editCustomer 
// passed: std::string
// returns: const std::string
// The validateName function validates the string input *
// by looping while the invariants are true, prompting  *
// the user for valid input.  One the input is verified *
// a string is returned.
//*******************************************************
const std::string validateName(std::string name) {
    
    //loop will execute until name is valid
    while(name.size() > 15 || name.size() <= 0) {

        std::cout << "\nThat name is invalid.\n";
        std::cout << "Please enter a non-empty value less than "
        << " or equal to 15 characters: ";

        getline(std::cin, name);
    }
    //return valid name
    return name;
}

//*******************************************************
// name: validateNumber
// called by: addNewCustomer, editCustomer              *
// called by: searchContract
// passed: std::string
// returns: const float
// The validateNumber function loops while 2 conditions *
// are true: 1. that value is <= 0, and that it is not a*
// valid float.  The validate number is returned when   *
// the while loop breaks                                *
//*******************************************************
const float validateNumber(std::string num) {
    // will hold the value of the the number
    float value;
    // change num to a float
    std::istringstream i(num);
    i >> value;
    //verify that num is a valid float, then convert to float
    while(value <= 0 || !checkValidFloat(num)) {
        std::cout << "\nInput is invalid.\n";
        std::cout << "Please enter a non-zero value: ";
        getline(std::cin, num);
        std::istringstream i(num);
        i >> value;
    }
    //return valid float
    return value;

}//end validateNumber

//*******************************************************
// name: checkValidFloat
// called by: validateNumber
// passed: const std::string
// returns: bool
// The checkValidFloat function validates that the arg  *
// a valid float by checking for decimal point(s), and  *
// checking if every character is a digit.  If any      *
// non-digits are found, false is returned.  Otherwise  *
// true is returned.                                    *
//*******************************************************
bool checkValidFloat(const std::string num) {
    //validate num
    for (size_t j = 0; j < num.size(); ++j) {
        //decimal found continue with process
        if(num[j] == '.') {
            continue;
        }
        //entry is not a digit, return false
        else if(!isdigit(num[j])) {
            return false;
        }
    }// number is valid
    return true;

}//end checkValidFloat

