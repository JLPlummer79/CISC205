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
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
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
// name: 
// called by:
// passed: 
// returns: 
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
// name: 
// called by:
// passed: 
// returns: 
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
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
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
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
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
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
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