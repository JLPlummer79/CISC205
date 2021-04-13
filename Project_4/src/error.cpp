#include "error.h"
#include "Patient.h"
#include <string>
#include <iostream>
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
int checkIfInteger(const char &input) {
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
// name: checkSingleChar
// called by: mainMenu(), patientDisplayMenu()          *
// called by: editPatient()
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
// name: validateName
// called by: newPatient(), editPatient()
// passed: std::string 
// returns: const std::string
// The validateName function ensures that the string    *
// argument is valid for the specifications of the name:*
// 1. It is not 0 or less characters, 2. it is less than*
// 25 characters in length.  Once those conditions are  *
// met, the value is returned to the caller             *
//*******************************************************
const std::string validateName(std::string name) {
    
    //loop will execute until name is valid
    while(name.size() > 25 || name.size() <= 0) {

        std::cout << "\nThat name is invalid.\n";
        std::cout << "Please enter a non-empty value less than "
        << " or equal to 25 characters: ";

        //get user input
        getline(std::cin, name);
    }
    //return valid name
    return name;
}

//*******************************************************
// name: validateAddress
// called by: newPatient(), editPatient()
// passed: std::string 
// returns: const std::string
// The validateAddress function ensures that the string *
// argument is valid for the specifications of address: *
// 1. It is not 0 or less characters, 2. it is less than*
// 50 characters in length.  Once those conditions are  *
// met, the value is returned to the caller             *
//*******************************************************
const std::string validateAddress(std::string address) {
    //loop will execute until address is valid
    while(address.size() > 50 || address.size() <= 0) {
        std::cout << "\nThat address is invalid.\n";
        std::cout << "Please enter a non-empty value "
        << "less than or equal to 50 characters: ";

        //get user input
        std::getline(std::cin, address);
    }
    //return valid address
    return address;
}//end validateAddress

//*******************************************************
// name: validatePhone
// called by: newPatient(), editPatient()
// passed: std::string 
// returns: const std::string
// The validatePhone function ensures that the string   *
// argument is valid for the specifications of phone:   *
// 1. It is not 0 or less characters, 2. it is less than*
// 11 characters in length, 3. The characters are valid *
// integers.  Once those conditions are met the value   *
//  is returned to the caller                           *
//*******************************************************
const std::string validatePhone(std::string phone) {
    //continue looping until phone is valid
    while(phone.size() > 11 || phone.size() <= 0 || 
    !checkValidInteger(phone)) {
        std::cout << "\nThat phone number is invalid.\n";
        std::cout << "Please enter a non-empty value "
        << "less than or equal to 11 digits: ";

        //get user input
        std::getline(std::cin, phone);
    }
    //return valid phone number
    return phone;
}//end validatePhone

//*******************************************************
// name: checkValidInteger
// called by: validatePhone, validatePatientId
// passed: const std::string 
// returns: bool
// The checkValidInteger function ensures that the      *
// string argument contains ony digits. At any point if *
// a non-digit is found, false is returned.  Otherwise  *
// the argument contains only digits, & true is returned*
//*******************************************************
bool checkValidInteger(const std::string num) {
    //validate num
    for (size_t j = 0; j < num.size(); ++j) {
        //entry is not a digit, return false
        if(!isdigit(num[j])) {
            return false;
        }
    }// number is valid
    return true;

}//end checkValidInteger

//*******************************************************
// name: validatePatientId
// called by: editPatient, newPatient
// passed: pointer to Patient array, std::string, int& 
// returns: const int
// The validatePatientId function ensures the string id *
// arg is valid for the specifications of patientId:    *
// 1. It is not 0 or less characters, 2. All of the     *
// charactes are digits, 3. id is unique when compared  *    
// to the ids of the Patient array, 4. It is less than  *  
// 10 characters long (so it cannot be larger than the  *
//memory size of an integer). Once those conditions are *
// met, a const int is returned to the caller           *
//*******************************************************
const int validatePatientId(Patient* customers, std::string id, int& numPatients) {
    bool same = true;       //controls flow of 1st while loop
    int num;                //holds number/id number
    //this while will run to ensure error checking for uniqueness
    while(same == true) {
    
        //validate if id is a digit, prompt user if invalid
        while(id.size() <= 0 || id.size() >= 10 || !checkValidInteger(id)) {
            std::cout << "That patient Id entry is invalid.\n";
            std::cout << "Please enter a non-empty, unique number "
            << "that is less than 10 digits long: ";
    
            //get user input
            std::getline(std::cin, id);

        }//end while

            //convert string to int
            std::istringstream i(id);
            i >> num;
        
        //validate that num is unique        
        if(validateUniqueNumber(customers, num, numPatients)) {
            std::cout << "That patient Id entry is invalid.\n";
            std::cout << "Please enter a non-empty, unique number "
            << "that is less than 10 digits long: ";
        
            //get user input
            std::getline(std::cin, id);
        }
        //the id is unique, break the 1st while loop
        else {
            same = false;
        }
    }//end same while

    //return the validated number
    return num;

}//end validatePatientId

//*******************************************************
// name: validateUniqueNumber
// called by: validatePatientId
// passed: pointer to Patient array, int, int& 
// returns: bool
// The validateUniqueNumber function ensures the int num*
// arg is valid for the specifications of patientId:    *
// 1. It is not equal to 0 , 2. it is unique compared   *
// with the patientId's in the arg Patient array. Once  *
//those conditions are met, a bool  is returned to the  *
//caller                                                *
//*******************************************************
bool validateUniqueNumber(Patient* customers, int num, int& numPatients) {
   
    //validate num is not zero
    if(num == 0) {
        return true;
    }
    //validate that id is unique 
    for (size_t i=0; i < numPatients; ++i) {
    
        //num is not unique
        if(customers[i].getPatientId() == num) {
            return true;
        }
    }//end for

    //num is unique
    return false;

}//end validateUniqueNumber

//*******************************************************
// name: validateDaysInHospital
// called by: dischargePatient
// passed: std::string
// returns: int
// The validateDaysInHospital function ensures string   *
// arg is valid for the specifications of days in       *
// hospital 1. It is not equal to 0 , 2. it is less than*
// 4 digits long, 3. It is a valid integer. Once these  *
// conditions are met, the valid int is returned to the *
// caller                                               *
//*******************************************************
int validateDaysInHospital(std::string days) {
    // will hold the number of days after verification of digits
    int numDays = 0;

    //loop while days is invalid
    while(days.size() > 4 || !checkValidInteger(days)) {

        std::cout << "The number of hospital days entered is invalid.\n"
        << "Please enter a number of days greater than zero and less "
        << "than 9999: ";
        std::getline(std::cin, days);
    }
        //convert string to int
        numDays = std::stoi(days);

        //check if numDays is greater than 0
        if(numDays <= 0) {
            //loop while numDays is invalid
            while(numDays <= 0) {
                std::cout << "The number of hospital days entered is invalid.\n"
                << "Please enter a number of days greater than zero and less "
                << "than 9999: ";

                //get user input
                std::getline(std::cin, days);
            }
            //convert string to int
            numDays = std::stoi(days);
        }

    // returns a valid number of days
    return numDays;

}//end validateDaysInHospital