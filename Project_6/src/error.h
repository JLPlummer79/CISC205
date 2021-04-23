/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#ifndef ERROR_H
#define ERROR_H
#include <string>

int checkSingleInt(std::string);

char checkSingleChar(std::string);

int checkIfInteger(const char&);

bool checkValidNumber(const std::string);

float checkValidFloat(std::string);

std::string validateString(std::string, int);


#endif