/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/

#include "Painting.h"
#include <string>
#include <iostream>
#include <utility>
#include <iomanip>

//default constructor
Painting::Painting() {
    name = " ";
    boatName = " ";
    contract = 0.0;
    paidToDate = 0.0;
}

//move constructor
Painting::Painting(Painting &&other) noexcept{
    std::cout << "move constructor\n";
    *this = std::move(other);
}

//move assignment operator
Painting& Painting::operator=(Painting &&other) noexcept{
    std::cout << "move assignment\n";
    name = std::move(other.name);
    boatName = std::move(other.boatName);
    contract = std::move(other.contract);
    paidToDate = std::move(other.paidToDate);

    return *this;
}

//copy consructor
Painting::Painting(const Painting& other) {
    std::cout << "copy constructor\n";
    name = other.name;
    boatName = other.boatName;
    contract = other.contract;
    paidToDate = other.paidToDate;
}

//copy assingment
Painting& Painting::operator=(const Painting &other) {
    std::cout << "copy assignment\n";
    name = other.name;
    //this->setName(other.getName());
    boatName = other.boatName;
    //this->setboatName(other.getBoatName());
    contract = other.contract;
    //this->setContract(other.getContract());
    paidToDate = other.paidToDate;
    //this->setPaidToDate(other.getPaidToDate());

    return *this;
}

//overloaded addition operator
float Painting::operator+(const Painting &rhs) {
    float temp;

    temp = this->getContract() + rhs.getContract();

    return temp;
}

//overloaded greater than operator
bool Painting::operator>(const Painting &rhs) {
    if(this->getContract() > rhs.getContract()) {
        return true;
    }
    return false;
}

//*******************************************************
// name: getName
// called by: matchCustomer, overloaded stream insertion
// called by: operator << 
// passed: nothing
// returns: std::string
// The getName function returns the member variable name*
//*******************************************************
std::string Painting::getName() const {
    return name;
}

//*******************************************************
// name: getBoatName
// called by: overloaded stream insertion operator <<
// passed: nothing
// returns: std::string
// The getBoatName function returns the member variable *
// boatName.                                            *
//*******************************************************
std::string Painting::getBoatName() const {
    return boatName;
}

//*******************************************************
// name: getContract
// called by:
// passed: nothing
// returns: float
// The 'name' function 'what function does'             *
//*******************************************************
float Painting::getContract() const {
    return contract;
}

//*******************************************************
// name: getPaidToDate
// called by: 
// passed: nothing
// returns: float
// The 'name' function 'what function does'             *
//*******************************************************
float Painting::getPaidToDate() const {
    return paidToDate;
}

//*******************************************************
// name: setName
// called by:
// passed: std::string
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void Painting::setName(std::string c) {
    if(c.empty()) {
        throw EmptyValue();
    }
    else if(c.size() > 15) {
        throw BigString(c);
    }
    //set member variable to arg
    name = c;
}

//*******************************************************
// name: setBoatName
// called by:
// passed: std::string
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void Painting::setBoatName(std::string b) {
    if(b.empty()) {
        throw EmptyValue();
    }
    else if(b.length() > 15) {
        throw BigString(b);
    }
    //set member var to arg
    boatName = b;
}

//*******************************************************
// name: setContract
// called by:
// passed: float
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void Painting::setContract(float con) {
    if(con < 0.0) {
        throw NegativeValue(con);
    }
    //set member var to arg
    contract = con;
}

//*******************************************************
// name: setPaidToDate
// called by:
// passed: float
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void Painting::setPaidToDate(float ptd) {
    if(ptd < 0.0) {
        throw NegativeValue(ptd);
    }
    //set member var to arg
    paidToDate = ptd;
}

//overloaded insertion stream operator
std::ostream& operator<<(std::ostream& out, const Painting& obj) {
    return out << "\nName: " << obj.getName() << "\nBoatName: "
    << obj.getBoatName() << "\nContract Value: " << obj.getContract()
    << "\nAmount Paid: " << obj.getPaidToDate() << "\n";
}

//*******************************************************
// name: convertFloat
// called by:
// passed: std::string
// returns: float
// The 'name' function 'what function does'             *
//*******************************************************
float Painting::convertFloat(std::string num) {
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
// name: convertSingleInt
// called by:
// passed: std::string
// returns: int
// The 'name' function 'what function does'             *
//*******************************************************
int Painting::convertSingleInt(std::string num) {
    int choice;

    if(num.empty()) {
        throw EmptyValue();
    }

    else if(num.size() > 1) {
        throw BigString(num);
    }

    try{
        choice = stoi(num);
    }
    catch(std::invalid_argument e) {
        std::string m = "Invalid argument.";
        std::cout << m << '\n';
        throw ImpossibleStr(m);
    }
    catch(std::out_of_range e) {
        std::string m = "Input out of range.";
        std::cout << m << '\n';
        throw ImpossibleStr(m);
    }
    return choice;
}//end convertSingleInt

//*******************************************************
// name: print
// called by:
// passed: nothing
// returns: nothing
// The print member function prints a Painting object   *
// using the overloaded << operator and iomanip library *
//*******************************************************
void Painting::print() const {

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