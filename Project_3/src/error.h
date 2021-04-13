/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#ifndef ERROR_H
#define ERROR_H
#include <string>

//function declarations for error.cpp

int checkIfInteger(const char &input);

int checkSingleChar(std::string);

const std::string validateName(std::string);

const float validateNumber(std::string);

bool checkValidFloat(const std::string);

#endif