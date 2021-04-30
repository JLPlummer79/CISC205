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
    //std::cout << "In move constructor S\n";

    *this = std::move(other);
}

//move assignment operator (overloaded)
Sailboat& Sailboat::operator=(Sailboat &&rhs) noexcept {
    //std::cout << "In move assignment S\n";

    //sailArea = std::move(rhs.sailArea);
    this->setSailArea(std::move(rhs.getSailArea()));

    //call to the Yacht move assignent operator
    Yacht::operator=(rhs);

    return *this;
}

//copy constructor
Sailboat::Sailboat(const Sailboat& other) {
    //std::cout << "In copy constructor S\n";
    sailArea = other.sailArea;
}

//copy assignment operator (overloaded)
Sailboat& Sailboat::operator=(const Sailboat &rhs) {
    //std::cout << "In copy assignment S\n";
    //sailArea = rhs.sailArea;

    this->setSailArea(rhs.getSailArea());

    //call Yacht copy assignment operator
    Yacht::operator=(rhs);

    return *this;
}

//*******************************************************
// name: getSailArea
// called by: overloaded << (Sailboat class)
// passed: nothing
// returns: float 
// The getSailArea function returns the value of the    *
// member variable sailArea                             *
//*******************************************************
float Sailboat::getSailArea() const {
    return sailArea;
}

//*******************************************************
// name: getName
// called by: overloaded << operator 
// passed: nothing
// returns: std::string
// The getName function returns the value of the member *
// variable, name.  Note: name is a member of Yacht     *
// class, but since Sailboat inherits from Yacht, it can*
// access it                                            *
//*******************************************************
std::string Sailboat::getName() const {
    return Yacht::getName();
}

//*******************************************************
// name: getLength
// called by: overloaded << operator 
// passed: nothing
// returns: float
// The getLength function returns the value of the      *
// member variable, length.  Note: length is a member of*
// Yacht class, Sailboat inherits from Yacht, thus      *
// Sailboat can access it                               *
//*******************************************************
float Sailboat::getLength() const {
    return Yacht::getLength();
}

//*******************************************************
// name: getYearBuilt
// called by: overloaded << operator
// passed: nothing
// returns: std::string
// The getYearBuilt function returns the value of the   *
// member variable, yearBuilt.  Note: yearBuilt is a    *
// member of Yacht class, Sailboat inherits from Yacht, *
// thus Sailboat can access it                          *
//*******************************************************
std::string Sailboat::getYearBuilt() const {
    return Yacht::getYearBuilt();
}

//*******************************************************
// name: setSailArea
// called by: newSailBoat
// passed: const float
// returns: nothing
// The setSailArea function ensures that sa is greater  *
// than zero, if so it sets the member variable sailArea*
// to the arg.  If not greater than zero, the program is*
// exited.                                              *
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
// name: setName
// called by: newSailBoat
// passed: const std::sring
// returns: nothing
// The setName function calls the same function, from   *
// Yacht class, passing it the same arugment.  This is  *
// possible since class Sailboat inherits from class    *
// Yacht                                                *
//*******************************************************
void Sailboat::setName(const std::string nm) {
    //set member to argument, low level 
    //error checking handled in base class
    Yacht::setName(nm);
}

//*******************************************************
// name: setLength
// called by: newSailBoat
// passed: const float
// returns: nothing
// The setLength function calls the same function, from *
// Yacht class, passing it the same arugment.  This is  *
// possible since class Sailboat inherits from class    *
// Yacht                                                *
//*******************************************************
void Sailboat::setLength(const float len) {
    //set member to arg, low level error check
    //handled in base class
    Yacht::setLength(len);
}

//*******************************************************
// name: setYearBuild
// called by: newSailBoat
// passed: const std::string
// returns: nothing
// The setYearBuilt function calls the same function,   *
// from Yacht class, passing it the same arugment.  This*
// is possible since class Sailboat inherits from class *
// Yacht                                                *
//*******************************************************
void Sailboat::setYearBuilt(const std::string yb) {
    Yacht::setYearBuilt(yb);
}

//overloaded << operator
std::ostream& operator<<(std::ostream& out, const Sailboat& obj) {
    
    return out << "Sail Area: " << obj.getSailArea() << 
    " square feet.\n";
}

//*******************************************************
// name: print
// called by: printAll
// passed: nothing
// returns: nothing
// The prints function prints a Sailboat object based on*
// the overloaded << operator.  Note: print is declared *
// virtual in the base class so that when print() is    *
// called the correct print() (based on the object) is  *
// called                                               *
//*******************************************************
void Sailboat::print() const {

    Yacht::print();
    std::cout << std::fixed
    << std::setprecision(2)
    << *this;
}
