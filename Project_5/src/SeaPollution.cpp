/*
 *
 * Jesse Plummer
 *
 * Chapter 14, Programming Challenge #5 Sea Pollution
 *
 * April 19th, 2021
 * 
*/

#include "SeaPollution.h"
#include <iostream>
#include <utility>
#include <limits>
#include <string>
#include <iomanip>

//actual declaration of static member variable
int SeaPollution::id{0}; 

//default constructor
SeaPollution::SeaPollution() {

    name = "Zzyzx";
    surfaceArea = 256.25;
    pollutionArea = 251.25;
    salinityLevel = 50.0;
    ++id;

}

//overloaded constructor
SeaPollution::SeaPollution(std::string n, float sa, float pa, float sl) {
   
    name = n;
    surfaceArea = sa;
    pollutionArea = pa;
    salinityLevel = sl;
    ++id;

}

//getters
//*******************************************************
// name: getName
// called by: searchSeas, 
// called by: overloaded stream insertion operator
// passed: nothing
// returns: const std::string
// The getName function returns the value of the member *
// variable name                                        *
//*******************************************************
const std::string SeaPollution::getName() const {
    return name;
}

//*******************************************************
// name: getSurfaceArea
// called by: overloaded addition operator
// called by: overloaded greater than operator
// called by: overloaded less than operator
// called by: overloaded  equivalence operator
// called by: overloaded stream insertion operator
// passed: nothing
// returns: const float
// The getSurfaceArea function return the value of the  *
// member variable surfaceArea                          *
//*******************************************************
const float SeaPollution::getSurfaceArea() const {
    return surfaceArea;
}

//*******************************************************
// name: getPollutionArea
// called by: overloaded stream insertion operator
// passed: nothing
// returns: const float
// The getPollutionArea function returns the value of   *
// the member variable pollutionArea                    *
//*******************************************************
const float SeaPollution::getPollutionArea() const {
    return pollutionArea;
}

//*******************************************************
// name: getSalinityLevel
// called by: overloaded stream insertion operator
// passed: nothing
// returns: const float
// The getSalinityLevel function returns the value of   *
// the member variable salinityLevel                    *
//*******************************************************
const float SeaPollution::getSalinityLevel() const {
    return salinityLevel;
}
//*******************************************************
// name: setName
// called by: enterSea, overloaded addition operator
// called by: overloaded subtraction operator
// passed: const std::string
// returns: nothing
// The setName function first checks if the argument is *
// "valid" by being less than 20 characters and not non-*
// empty.  If it is valid, the member variable name is  *
// set to the arg.  If the argument is invalid, an error*
// message is printed, and then the program is exited.  *
//*******************************************************
void SeaPollution::setName(const std::string n) {
    //low level validation
    if(n.size() > 20 || n.empty()) {
        std::cout << "ERROR. Name must " <<
        "be less than or equal to 20 " << 
        "characters and greater than zero. " <<
        "Exiting Program.\n";
        exit(EXIT_FAILURE);
    }
    //set member variable to argument
    name = n;
}

//*******************************************************
// name: setPollutionArea
// called by: enterSea
// passed: const float
// returns: nothing
// The seaPollutionArea function first checks if the    *
// argument is "valid" by being more than 0 and less    *
// than the numeric limits of a float.  If it is valid  *
// the member variable pollutionArea is set to the value*
// of pa. If the argument is invalid, an error message  *
// is printed, and the program is exited.               *
//*******************************************************
void SeaPollution::setPollutionArea(const float pa) { 
    //low level validation
    if(pa <= 0 || pa > std::numeric_limits<float>::max()) {
        std::cout << "ERROR. Sea Pollution value must " <<
        "be greater than zero and less than the " <<
        "maximum size of a float.\n" <<
        "Exiting Program.\n";
        exit(EXIT_FAILURE);
    }
    //set member variable to argument
    pollutionArea = pa;
}

//*******************************************************
// name: setSurfaceArea
// called by: enterSea, overloaded addition operator
// called by: overloaded subtraction operator
// passed: const float
// returns: nothing
// The setSurfaceArea function first checks if the      *
// argument is "valid" by being more than 0 and less    *
// than the numeric limits of a float. If it is valid   *
// the member variable surfaceArea is set to the value  *
// of sa.  If the argument is invalid, an error message *
// is printed, and the program is exited.               *
//*******************************************************
void SeaPollution::setSurfaceArea(const float sa) {
    //low level validation
    if(sa <= 0 || sa > std::numeric_limits<float>::max()){
        std::cout << "ERROR. Surface Area value must " <<
        "be greater than zero and less than the " <<
        "maximum size of a float.\n" <<
        "Exiting Program.\n";
        exit(EXIT_FAILURE);
    }
    //set member variable to argument
    surfaceArea = sa;

}

//*******************************************************
// name: setSalinityLevel
// called by: enterSea
// passed: const float
// returns: nothing
// The setSalinityLevel function first checks if the    *
// arugment is "valid" by being more than 0 and less    *
// than the numeric limits of a float.  If it is valid  *
// the member variable salinityLevel is set to the value*
// of sl.  If the argument is invalid, an error message *
// is printed, and the program is exited.               *
//*******************************************************
void SeaPollution::setSalinityLevel(const float sl) {
    //low level
    if(sl <= 0 || sl > std::numeric_limits<float>::max()) {
        std::cout << "ERROR. Salinity Level value must " <<
        "be greater than zero and less than the " <<
        "maximum size of a float.\n" <<
        "Exiting Program.\n";
        exit(EXIT_FAILURE);
    }
    //set member variable to argument
    salinityLevel = sl;
}

//move constructor
SeaPollution::SeaPollution(SeaPollution &&other) noexcept{
    *this = std::move(other);
}
//move assignment operator 
SeaPollution& SeaPollution::operator=(SeaPollution &&other) noexcept {
    //std::cout << "In move assignment operator\n";
    //name = std::move(other.name);
    this->setName(std::move(other.getName())); 
    //surfaceArea = std::move(other.surfaceArea);
    this->setSurfaceArea(std::move(other.getSurfaceArea()));
    //pollutionArea = std::move(other.pollutionArea);
    this->setPollutionArea(std::move(other.getPollutionArea()));
    //salinityLevel = std::move(other.salinityLevel);
    this->setSalinityLevel(std::move(other.getSalinityLevel()));

    return *this;
}

//copy constructor
SeaPollution::SeaPollution(const SeaPollution& other) {
    name = other.name;
    surfaceArea = other.surfaceArea;
    pollutionArea = other.pollutionArea;
    salinityLevel = other.salinityLevel;
}

//copy assignment operator
SeaPollution& SeaPollution::operator=(const SeaPollution &other) {
    //std::cout << "In copy assignment operator\n";
    //name = other.name;
    this->setName(other.getName());
    //surfaceArea = other.surfaceArea;
    this->setSurfaceArea(other.getSurfaceArea());
    //pollutionArea = other.pollutionArea;
    this->setPollutionArea(other.getPollutionArea());
    //salinityLevel = other.salinityLevel;
    this->setSalinityLevel(other.getSalinityLevel());

    return *this;
}
//overloaded operator + 
SeaPollution SeaPollution::operator+(const SeaPollution &rhs) {
    SeaPollution temp;

    temp.setSurfaceArea(this->getSurfaceArea() + rhs.getSurfaceArea());

    temp.setName("temporary-" + std::to_string(id));

    //return newly created object
    return temp;

}
//overloaded operator > 
bool SeaPollution::operator>(const SeaPollution& rhs){
    if(this->getSurfaceArea() > rhs.getSurfaceArea()){
        return true;
    }
    
    return false;
}

//overloaded operator <
bool SeaPollution::operator<(const SeaPollution& rhs) {
    
    if(this->getSurfaceArea() < rhs.getSurfaceArea()) {
        return true;
    }

    return false;
}

//overloaded operator -
SeaPollution SeaPollution::operator-(const SeaPollution& rhs) {
    SeaPollution temp;

    temp.setSurfaceArea(this->getSurfaceArea() - rhs.getSurfaceArea());
    
    temp.setName("temporary-" + std::to_string(id));

    //return newly created object
    return temp;
}

//overloaded equivalence operator
bool SeaPollution::operator==(const SeaPollution& rhs){

    if(this->getSurfaceArea() == rhs.getSurfaceArea()) {
        return true;
    } 
    return false;
}

//overloaded stream insertion operator
std::ostream& operator<<(std::ostream& out, const SeaPollution& obj){
    return out << "\nSea Name: " << obj.getName() << 
    "\nSurface Area: " << obj.getSurfaceArea() << " square miles" <<
    "\nPollution Area: " << obj.getPollutionArea() << " square miles" <<
    "\nSalinity: " << obj.getSalinityLevel() << " %.\n";
}
//*******************************************************
// name: print
// called by: searchSeasPrint, compareSeas
// called by: arithmeticSeas, printAllSeas
// passed: nothing
// returns: nothing
// The print function calls std::cout & the overloaded  *
// stream insertion operator on the deferenced this     *
// pointer (that points to the current object)          *
// printing the object using precision(2) formatting    *
//*******************************************************
void SeaPollution::print() const {

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