/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#include "Powerboat.h"
#include "Yacht.h"
#include <iostream>
#include <utility>
#include <iomanip>

//default constructor
Powerboat::Powerboat(): Yacht() {
    totHorsePower = 0.0;
    numEngines = 0;
}

Powerboat::~Powerboat() {
    std::cout << "Powerboat desructor...\n";
}

//move constructor
Powerboat::Powerboat(Powerboat &&other) noexcept {
    std::cout << "In move constructor P\n";

    *this = std::move(other);
}

//move assignment operator
Powerboat& Powerboat::operator=(Powerboat &&rhs) noexcept {
    std::cout << "In move assignment P\n";

    totHorsePower = std::move(rhs.totHorsePower);
    numEngines = std::move(rhs.numEngines);

    //call to the Yacht move assignment operator
    Yacht::operator=(rhs);

    return *this;
}

//copy constructor
Powerboat::Powerboat(const Powerboat& other) {
    std::cout << "In copy constructor P\n";
    totHorsePower = other.totHorsePower;
    numEngines = other.numEngines;
}

//copy assignment operator
Powerboat& Powerboat::operator=(const Powerboat &rhs) {
    std::cout << "In copy assignment P\n";
    totHorsePower = rhs.totHorsePower;
    numEngines = rhs.numEngines;

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
int Powerboat::getNumEngines() const {
    return numEngines;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
float Powerboat::getTotHorsePower() const {
    return totHorsePower;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
std::string Powerboat::getName() const {
    return Yacht::getName();
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
float Powerboat::getLength() const {
    return Yacht::getLength();
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
std::string Powerboat::getYearBuilt() const {
    return Yacht::getYearBuilt();
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Powerboat::setNumEngines(const int num) {
    //low level validation
    if(num <= 0) {
        std::cout << "ERROR. Number of engines "
        << "must be greater than zero. "
        << "Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to arg
    numEngines = num;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Powerboat::setTotHorsePower(const float pow) {
    //low level validation
    if(pow <= 0) {
        std::cout << "ERROR. Horse power must be "
        << "greater than zero.  Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    //set member to arg
    totHorsePower = pow;
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Powerboat::setName(const std::string nm) {
    //pass arg to base class
    Yacht::setName(nm);
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Powerboat::setLength(const float len) {
    //pass arg to base class
    Yacht::setLength(len);
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Powerboat::setYearBuilt(const std::string yr) {
    //pass arg to base class
    Yacht::setYearBuilt(yr);
}

std::ostream& operator<<(std::ostream& out, const Powerboat& obj) {
    
    return out << "Number of Engines: " << obj.getNumEngines() <<
    "\nTotal Horsepower: " << obj.getTotHorsePower() << 
    " horses.\n";
}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************
void Powerboat::print() const {
    
    Yacht::print();
    std::cout << std::fixed
    << std::setprecision(2)
    << *this;
}

void Powerboat::garbageCollector(const Powerboat* ptr) {
    std::cout << "Collecting Powerboat garbage...\n";
    Yacht::garbageCollector(ptr);
}


