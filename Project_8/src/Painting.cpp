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
    *this = std::move(other);
}

//move assignment operator
Painting& Painting::operator=(Painting &&other) noexcept{
    name = std::move(other.name);
    boatName = std::move(other.boatName);
    contract = std::move(other.contract);
    paidToDate = std::move(other.paidToDate);

    return *this;
}

//copy consructor
Painting::Painting(const Painting& other) {
    name = other.name;
    boatName = other.boatName;
    contract = other.contract;
    paidToDate = other.paidToDate;
}

//copy assingment
Painting& Painting::operator=(const Painting &other) {
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
// called by:
// passed: nothing
// returns: std::string
// The 'name' function 'what function does'             *
//*******************************************************
std::string Painting::getName() const {
    return name;
}

//*******************************************************
// name: getBoatName
// called by:
// passed: nothing
// returns: std::string
// The 'name' function 'what function does'             *
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
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************