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

//default constructor
Yacht::Yacht() {
    name = "";
    length = 0;
    yearBuilt = "";

}

//move constructor
Yacht::Yacht(Yacht &&other) noexcept {
    std::cout << "In move constructor Y\n";
    *this = std::move(other);
}

//move assignment operator (overloaded)
Yacht& Yacht::operator=(Yacht &&rhs) noexcept {
    std::cout << "In move assignment Y\n";
      name = std::move(rhs.name);
      length = std::move(rhs.length);
      yearBuilt = std::move(rhs.yearBuilt);

      return *this;
}

//copy constructor
Yacht::Yacht(const Yacht& other) {
    std::cout << "In copy constructor Y\n";
    name = other.name;
    length = other.length;
    yearBuilt = other.yearBuilt;
}

 //copy assignment operator (overloaded)
Yacht& Yacht::operator=(const Yacht &rhs) {
    std::cout << "In copy assignment Y\n";
    name = rhs.name;
    length = rhs.length;
    yearBuilt = rhs.yearBuilt;

    return *this;
}

std::string Yacht::getName() const {
    return name;
}

float Yacht::getLength() const {
    return length;
}

std::string Yacht::getYearBuilt() const {
    return yearBuilt;
}

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

void Yacht::setLength(const float len) {
    //low level validation
    if(len <= 0) {
        std::cout << "ERROR. Length of vessel "
        << "must be greater than zero. "
        << "Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to argument
    length = len;
}

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
    return out <<  "\nYacht Name: " << obj.getName() << 
    "\nLength of vessel: " << obj.getLength() << " feet" <<
    "\nYear vessel was built: " << obj.getYearBuilt() << "\n";
}

void Yacht::print() const {
    std::cout << std::fixed
    << std::setprecision(2)
    << *this;

}

void Yacht::garbageCollector(const Yacht* ptr) {
    //for error checking
    std::cout << "Collecting Yacht garbage...\n";
    delete ptr;
    ptr = nullptr;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************