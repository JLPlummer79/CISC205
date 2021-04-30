/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#include "error.h"
#include <iostream>
#include <sstream>

//*******************************************************
// name: checkSingleInt
// called by: menu
// passed: std::string
// returns: int
// The checkSingleInt function takes an std::string arg *
// calls checkSingleChar, checkIfInteger, then returns  *
// the result of checkIfInteger                         *
//*******************************************************
int checkSingleInt(std::string input) {
    // declare variables
    char s;             //holds single char
    int num;            //holds validated entry

    s = checkSingleChar(input);
    
    //validate if s is an int
    num = checkIfInteger(s);

    //return valid entry if int, 0 if invalid
    return num;    
}//end checkSingleChar

//*******************************************************
// name: checkSingleChar
// called by: checkSingleInt
// passed: std::string
// returns: char
// The checkSingleChar function takes a std::string arg *
// and ensures that it is not greater than 1 or empty.  *
// When these conditions are met, the string is         *
// converted to a char and returned.                    *
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
// called by: checkSingleInt
// passed: const char&
// returns: int
// The checkIfInteger function checks if the input is a *
// digit, then if so, converts it to an int and returns *
// the result.  If not, zero is returned.               *
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
// name: validateInteger
// called by: menu
// passed: std::string
// returns: int
// The validateInteger function ensures that the arg is *
// a number and is not empty.  Once these conditions are*
// satisfied the string is converted to an int and      *
// returned.                                            *
//*******************************************************
int validateInteger(std::string input) {
        
        while(!checkValidNumber(input) || input.empty()) {
            std::cout << "Invalid entry. "
            << "Please enter a non-empty number.\n";
            std::getline(std::cin, input);
        }
        //return the validated number
        return stoi(input);

}//end checkIfInteger

//*******************************************************
// name: checkValidNumber
// called by: validateInteger, checkValidFloat, 
// called by: validateString
// passed: const std::string
// returns: bool
// The checkValidNumber function iterates over the arg  *
// checking if each character is a digit or a '.'       *
// If anything other than that is found, false is       *
// returned.  Otherwise true is returned.               *
//*******************************************************
bool checkValidNumber(const std::string num) {
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

//*******************************************************
// name: checkValidFloat
// called by: newYacht, newPowerBoat, newSailBoat
// passed: std::string
// returns: float
// The checkValidFloat function ensures that the arg is *
// not empty, a number, and less than 10 digits long.   *
// When these conditions are met the arg is converted to*
// a float and returned.                                *
//*******************************************************
float checkValidFloat(std::string num) {
    //the reason for less than 10 characters long is to
    //ensure the resulting float is not beyond the max
    //capacity of a float.
    while(num.empty() || !checkValidNumber(num) || 
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
// name: validateString
// called by: newYacht, newPowerBoat, newSailBoat
// passed: std::string, int
// returns: std::string
// The validateString function performs error checking  *
// in 2 different ways. First, when the arg en is not   *
// digit it ensures that the string is less than 20 and *
// not empty. Second, when the arg mag is less than or  *
// equal to 4 it is ensured that the arg en is a valid  *
// number and its size is 4.  When these conditions are *
// met, a std::string is returned.                      *
//*******************************************************
std::string validateString(std::string en, int mag){
    bool flag = true;
    while(flag) {
        //when we want to verify a name
        if(!isdigit(en[0])) {
            while(en.empty() || en.size() > 20) {
                std::cout << "\nThe entry is invalid. "
                << "Please enter a name less than 20 "
                << "characters.\n";
                std::getline(std::cin, en);
            }
            //break big while
            flag = false;
        }
        //when we want to verify a year
        else if(mag <= 4) {
            while(!checkValidNumber(en) && en.size() != 4){
                std::cout << "\nThat entry is invalid. "
                << "Please make your entry 4 digits.\n";
                std::getline(std::cin, en);
            }
            //break big while
            flag = false;
        }
        //catch the miscallenous entries
        else {
            std::cout << "Invalid entry.  Please enter a name "
            << "less than or equal to 20 characters or a "
            << "year 4 digits in length.\n";
            std::getline(std::cin, en);
            mag = en.length();
        }
    }//end while
    
    //return valid data
    return en;
}//end validate string

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************