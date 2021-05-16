
/*
 *
 * Jesse Plummer
 *
 * Chapter 16, Programming Challenge #7 Sea Pollution w/ try/catch
 *
 * May 17th, 2021
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

    name = " ";
    surfaceArea = 0.00;
    pollutionArea = 0.00;
    salinityLevel = 0.0;
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
    //need to add throw clause
    if(n.empty()) {
        throw EmptyValue();
    }
    else if(n.size() > 20) {
        throw BigName(n);
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
// argument is "valid" by being more than 0. If it is   *
// valid the member variable pollutionArea is set to the*
// value of pa. If the argument is invalid, an exception*
// is thrown                                            *
//*******************************************************
void SeaPollution::setPollutionArea(const float pa) { 
    //add throws clause
    if(pa < 0){
        throw NegativeValue(pa);
    }
    else if(pa > this->getSurfaceArea()){
        throw ImpossibleValue(pa);
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
// argument is "valid" by being zero or greater. If it  *
// is valid the member variable surfaceArea is set to   *
// the value of sa.  If the argument is invalid, an     *
// exception is thrown.                                 *
//*******************************************************
void SeaPollution::setSurfaceArea(const float sa) {
    //throws when there is an error
    if(sa < 0) {
        throw NegativeValue(sa);
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
// arugment is "valid" by being 0 or more. If it is     *
// valid the member variable salinityLevel is set to the*
// value of sl.  If the argument is invalid, an exeption*
// is thrown.                                           *
//*******************************************************
void SeaPollution::setSalinityLevel(const float sl) {
    //throws if there is an error
    if(sl < 0){
        throw NegativeValue(sl); 
    }
    else if(sl > 100) {
        throw ImpossibleValue(sl);
    }
    //set member variable to argument
    salinityLevel = sl;
}

//*******************************************************
// name: convertFloat
// called by: enterSea
// passed: std::string
// returns: float
// The convertFloat function performs error checking on *
// the arg and throws an exception when 1) arg is empty,*
// 2) the stof() function throws and exception. When the*
// try blocks execute without throwing, then a          *
// valid float is returned.                             *
//*******************************************************
float SeaPollution::convertFloat(std::string num) {
    float fNum;

    if(num.empty()) {
        throw EmptyValue();
    }
    try {
        fNum = stof(num);
    }
    catch (std::invalid_argument e) {
        std::string m = "Invalid argument.";
        std::cout << m << '\n';
        throw ImpossibleStr(m);
    }
    catch(std::out_of_range e) {
        std::string m = "Input out of range.";
        std::cout << m << '\n';
        throw ImpossibleStr(m);
    }

    return fNum;
}//end convertFloat

//*******************************************************
// name: convertChar
// called by: compareSeas, arithmeticSeas
// passed: std::string
// returns: char
// The convertChar function performs error checking on  *
// the arg and throws an exception when 1) arg is empty *
// 2) arg is larger than 1 character. When both of these*
// conditions are met, the arg (a string) is converted  *
// to a char and returned.                              *
//*******************************************************
char SeaPollution::convertChar(std::string input) {
    char ch;

    if(input.empty()) {
        throw EmptyValue();
    }
    else if(input.size() > 1) {
        throw SmallStr(input);
    }
    //string streams do not throw exceptions!
    std::istringstream i(input);
    i >> ch;
    
    return ch;
}

//*******************************************************
// name: convertInt
// called by: menu
// passed: std::string
// returns: int
// The convertInt function performs error checking on   *
// the arg and throws when 1) the arg is empty 2) the   *
// length is greater than 1 3) if stoi throws an        *
// exception.  If all the conditions are met, and stoi  *
// does not throw an exception, then the arg is         *
// converted to an int and returned.                    *
//*******************************************************
int SeaPollution::convertInt(std::string input) {
    int num;

    if(input.empty()) {
        throw EmptyValue();
    }
    else if(input.length() > 1) {
        throw SmallStr(input);
    }
    try {
        num = stoi(input);
    }
    catch(std::invalid_argument e) {
        std::cout << "Invalid Arg\n";
        std::string m = "Invalid argument.";
        throw ImpossibleStr(m);
    }
    catch(std::out_of_range e) {
        std::cout << "Out of range\n";
        std::string m = "Input out of range!";
        throw ImpossibleStr(m);
    }

    return num;
}

//move constructor
SeaPollution::SeaPollution(SeaPollution &&other) noexcept{
    *this = std::move(other);
}
//move assignment operator
SeaPollution& SeaPollution::operator=(SeaPollution &&other) noexcept {
    //std::cout << "In move assignment operator\n";
    name = std::move(other.name);
    //this->setName(std::move(other.getName())); 
    surfaceArea = std::move(other.surfaceArea);
    //this->setSurfaceArea(std::move(other.getSurfaceArea()));
    pollutionArea = std::move(other.pollutionArea);
    //this->setPollutionArea(std::move(other.getPollutionArea()));
    salinityLevel = std::move(other.salinityLevel);
    //this->setSalinityLevel(std::move(other.getSalinityLevel()));

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
    name = other.name;
    //this->setName(other.getName());
    surfaceArea = other.surfaceArea;
    //this->setSurfaceArea(other.getSurfaceArea());
    pollutionArea = other.pollutionArea;
    //this->setPollutionArea(other.getPollutionArea());
    salinityLevel = other.salinityLevel;
    //this->setSalinityLevel(other.getSalinityLevel());

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
bool SeaPollution::operator>(const SeaPollution& rhs) {
    if(this->getSurfaceArea() > rhs.getSurfaceArea()) {
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