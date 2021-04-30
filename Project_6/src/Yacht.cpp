/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#include "Yacht.h"
#include <utility>
#include <iostream>
#include <iomanip>
#include <limits>

//default constructor
Yacht::Yacht() {
    name = "";
    length = 0;
    yearBuilt = "";

}

Yacht::~Yacht() {
    std::cout << "Yacht destructor...\n";
}

//move constructor
Yacht::Yacht(Yacht &&other) noexcept {
    //std::cout << "In move constructor Y\n";
    *this = std::move(other);
}

//move assignment operator (overloaded)
Yacht& Yacht::operator=(Yacht &&rhs) noexcept {
    //std::cout << "In move assignment Y\n";
      //name = std::move(rhs.name);
      this->setName(std::move(rhs.getName()));
      //length = std::move(rhs.length);
      this->setLength(std::move(rhs.getLength()));
      //yearBuilt = std::move(rhs.yearBuilt);
      this->setYearBuilt(std::move(rhs.getYearBuilt()));

      return *this;
}

//copy constructor
Yacht::Yacht(const Yacht& other) {
    //std::cout << "In copy constructor Y\n";
    name = other.name;
    length = other.length;
    yearBuilt = other.yearBuilt;
}


 //copy assignment operator (overloaded)
Yacht& Yacht::operator=(const Yacht &rhs) {
    //std::cout << "In copy assignment Y\n";
    //name = rhs.name;
    this->setName(rhs.getName());
    //length = rhs.length;
    this->setLength(rhs.getLength());
    //yearBuilt = rhs.yearBuilt;
    this->setYearBuilt(rhs.getYearBuilt());

    return *this;
}

//*******************************************************
// name: getName
// called by: newYacht, Sailboat::getName(),
// called by: Powerboat::getName()
// passed: nothing
// returns: std::string
// The getName function returns the value of the member *
// variable name                                        *
//*******************************************************
std::string Yacht::getName() const {
    return name;
}

//*******************************************************
// name: getLength
// called by: Sailboat::getLength, Powerboat::getLength
// passed: nothing
// returns: float
// The getLength function returns the value of the      *
// member variable length                               *
//*******************************************************
float Yacht::getLength() const {
    return length;
}

//*******************************************************
// name: getYearBuilt
// called by: Powerboat::getYearBuilt, 
// called by: Sailboat::getYearBuilt
// passed: nothing
// returns: std::string
// The getYearBuilt function returns the value of the   *
// member variable yearBuilt                            *
//*******************************************************
std::string Yacht::getYearBuilt() const {
    return yearBuilt;
}

//*******************************************************
// name: setName
// called by: newYacht, Sailboat::setName, 
// called by: Powerboat::setName
// passed: cosnt std::string
// returns: nothing
// The setName function performs error checking on the  *
// arg; when the arg is above 20 characters or empty an *
// error message is printed, and the program is exited. *
// Otherwise, the member variable is set to the arg     *
//*******************************************************
void Yacht::setName(const std::string nm) {
    //low level validation
    if(nm.length() > 20 || nm.empty()) {
        std::cout << "ERROR. Name must be less "
        << "or equal to 20 and greater than zero. "
        << "Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to argument
    name = nm;
}

//*******************************************************
// name: setLength
// called by: newYacht, Powerboat::setLength, 
// called by: Sailboat::setLength
// passed: const float
// returns: nothing
// The setLength function performs error checking on the*
// arg. If it is 0 or less or greater than the max value*
// of a float then an error message is printed and the  *
// program is exited.  Otherwise the member variable    *
// is set to the arg                                    *
//*******************************************************
void Yacht::setLength(const float len) {
    //low level validation
    if(len <= 0 || len > std::numeric_limits<float>::max()) {
        std::cout << "ERROR. Length of vessel is invalid. "
        << "Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to argument
    length = len;
}

//*******************************************************
// name: setYearBuilt
// called by: newYacht, Sailboat::setYearBuilt,
// called by: Powerboat::setYearBuilt
// passed: const std::string
// returns: nothing
// The setYearBuilt function performs error checking on *
// the arg. If it is not equal to 4 characters in length*
// an error message is printed and the program is exited*
// Otherwise the member variable yearBuilt is set to the*
// arg.                                                 *
//*******************************************************
void Yacht::setYearBuilt(const std::string year) {
    //low level validation
    if(year.length() != 4){
        std::cout << "ERROR. Year vessel must be "
        << "four characters in length. "
        << "Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to arg
    yearBuilt = year;
}

//overloaded << operator
std::ostream& operator<<(std::ostream& out, const Yacht& obj) {
    return out <<  "\nName of vessel: " << obj.getName() << 
    "\nLength of vessel: " << obj.getLength() << " feet" <<
    "\nYear vessel was built: " << obj.getYearBuilt() << "\n";
}

//*******************************************************
// name: print
// called by: Sailboat::print(), Powerboat::print(),
// called by: printAll()
// passed: nothing
// returns: nothing
// The print function calls the overloaded << operator  *
// and prints the data in a formatted way using iomanip *
// library. Note in the Yacht.h file print is declared  *
// virtual, allowing the correct print function to be   *
// called for each class                                *
//*******************************************************
void Yacht::print() const {
    std::cout << std::fixed
    << std::setprecision(2)
    << *this;

}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************