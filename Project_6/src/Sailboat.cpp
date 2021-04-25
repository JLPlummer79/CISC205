/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#include "Sailboat.h"
#include "Yacht.h"
#include <iostream>
#include <utility>
#include <iomanip>

//default constructor
Sailboat::Sailboat(): Yacht() {
    sailArea = 0;
}
Sailboat::~Sailboat() {
    std::cout << "Sailboat destructor...\n";
}

//move constructor
Sailboat::Sailboat(Sailboat &&other) noexcept {
    std::cout << "In move constructor S\n";

    *this = std::move(other);
}

//move assignment operator (overloaded)
Sailboat& Sailboat::operator=(Sailboat &&rhs) noexcept {
    std::cout << "In move assignment S\n";

    sailArea = std::move(rhs.sailArea);

    //call to the Yacht move assignent operator
    Yacht::operator=(rhs);

    return *this;
}

//copy constructor
Sailboat::Sailboat(const Sailboat& other) {
    std::cout << "In copy constructor S\n";
    sailArea = other.sailArea;
}

//copy assignment operator (overloaded)
Sailboat& Sailboat::operator=(const Sailboat &rhs) {
    std::cout << "In copy assignment S\n";
    sailArea = rhs.sailArea;

    //call Yacht copy assignment operator
    Yacht::operator=(rhs);

    return *this;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
float Sailboat::getSailArea() const {
    return sailArea;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
std::string Sailboat::getName() const {
    return Yacht::getName();
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
float Sailboat::getLength() const {
    return Yacht::getLength();
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
std::string Sailboat::getYearBuilt() const {
    return Yacht::getYearBuilt();
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Sailboat::setSailArea(const float sa) {
    //low level validation
    if(sa <= 0) {
        std::cout << "ERROR. Area of "
        << "sail must be greater than "
        << "zero. Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to argument
    sailArea = sa;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Sailboat::setName(const std::string nm) {
    //set member to argument, low level 
    //error checking handled in base class
    Yacht::setName(nm);
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Sailboat::setLength(const float len) {
    //set member to arg, low level error check
    //handled in base class
    Yacht::setLength(len);
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Sailboat::setYearBuilt(const std::string yb) {
    Yacht::setYearBuilt(yb);
}


std::ostream& operator<<(std::ostream& out, const Sailboat& obj) {
    
    return out << "Sail Area: " << obj.getSailArea() << 
    " square feet.\n";
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Sailboat::print() const {

    Yacht::print();
    std::cout << std::fixed
    << std::setprecision(2)
    << *this;
}

void Sailboat::garbageCollector(const Sailboat* ptr) {
    std::cout << "Collecting Sailboat garbage...\n";
    Yacht::garbageCollector(ptr);
}