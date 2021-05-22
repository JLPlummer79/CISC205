/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/

#include "Painting.h"
#include <string>

//default constructor
Painting::Painting() {
    name = " ";
    boatName = " ";
    contract = 0.0;
    paidToDate = 0.0;
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

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************