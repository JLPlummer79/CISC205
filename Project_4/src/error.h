#ifndef ERROR_H
#define ERROR_H
#include <string>
#include "Patient.h"

//function declarations for error.cpp

int checkIfInteger(const char&);

int checkSingleChar(std::string);

const std::string validateName(std::string);

const std::string validateAddress(std::string);

const std::string validatePhone(std::string);

bool checkValidInteger(const std::string);

const int validatePatientId(Patient*, std::string, int&);

bool validateUniqueNumber(Patient* , int, int& );

int validateDaysInHospital(std::string);


#endif