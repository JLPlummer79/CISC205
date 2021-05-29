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
    //std::cout << "move constructor\n";
    *this = std::move(other);
}

//move assignment operator
Painting& Painting::operator=(Painting &&other) noexcept{
    //std::cout << "move assignment\n";
    name = std::move(other.name);
    boatName = std::move(other.boatName);
    contract = std::move(other.contract);
    paidToDate = std::move(other.paidToDate);

    return *this;
}

//copy consructor
Painting::Painting(const Painting& other) {
    //std::cout << "copy constructor\n";
    name = other.name;
    boatName = other.boatName;
    contract = other.contract;
    paidToDate = other.paidToDate;
}

//copy assingment
Painting& Painting::operator=(const Painting &other) {
    //std::cout << "copy assignment\n";
    name = other.name;
    boatName = other.boatName;
    contract = other.contract;
    paidToDate = other.paidToDate;

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
// The getName function returns the value of the member *
// variable name                                        *
//*******************************************************
std::string Painting::getName() const {
    return name;
}

//*******************************************************
// name: getBoatName
// called by: overloaded stream insertion operator <<
// passed: nothing
// returns: std::string
// The getBoatName function returns the value of the    *
// member variable boatName.                            *
//*******************************************************
std::string Painting::getBoatName() const {
    return boatName;
}

//*******************************************************
// name: getContract
// called by: overloaded stream insertion operator <<, 
// called by: overloaded + operator, overloaded > 
// called by: operator
// passed: nothing
// returns: float
// The getContract function returns the value of the    *
// member variable contract.*
//*******************************************************
float Painting::getContract() const {
    return contract;
}

//*******************************************************
// name: getPaidToDate
// called by: overloaded stream insertion operator <<
// passed: nothing
// returns: float
// The getPaidToDate function returns the value of the  *
// member variable paidToDate                           *
//*******************************************************
float Painting::getPaidToDate() const {
    return paidToDate;
}

//*******************************************************
// name: setName
// called by: addCustomer, editCustomer
// passed: std::string
// returns: nothing
// The setName function takes a std::string as an arg.  *
// It checks the following conditions 1) Is the arg     *
// empty? 2) Is the arg greater than 15 chars in length?*
// When either of these things are true it throws. If   *
// these two conditons are false, then the member var   *
// name is set to the arg.                              * 
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
// called by: addCustomer, editCustomer
// passed: std::string
// returns: nothing
// The setBoatName function takes a std::string as an   *
// arg. It checks the following conditions 1) Is the arg*
// empty? 2) Is the arg greater than 15 chars in length?*
// When either of these conditions are true, it throws. *
// If these two conditions are false, then the member   *
// var boatName is set to the arg.                      *
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
// called by: addCustomer, editCustomer, printAll
// passed: float
// returns: nothing
// The setContract function takes a float as an arg. It *
// then checks the condition is the arg less than 0? If *
// it is then it throws. If the condition is met, then  *
// the member var contract is set to the arg.           *
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
// called by: addCustomer, editCustomer
// passed: float
// returns: nothing
// The setPaidToDate function takes a float as an arg.  *
// If the condition of arg being greater than 0 is not  *
// met, it throws. If the condition is met, then the    *
// member var paidToDate is set to the arg.             *
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
// called by: addCustomer, editCustomer
// passed: std::string
// returns: float
// The convertFloat function takes a std::string arg. It*
// then checks if the arg is empty. If it is it throws. *
// If the arg is not empty then it tries to convert the *
// arg to a float. There are two catch blocks for the   *
// two errors that stof can throw, if either of those   *
// execute an error message is printed, followed by a  *
// second throw that the calling object & function will *
// catch. When the conversion is successful, then a     *
// float is returned.                                   *
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
// called by: menu, editCustomerMenu
// passed: std::string
// returns: int
// The convertSingleInt function takes a std::string arg*
// It checks for 1) is the arg empty? 2) Does the arg   *
// have a length greater than 1? If either of these     *
// conditions are true, it throws. If these conditions  *
// are false, then the function tries to convert the arg*
// to a int. There are two catch blocks for the two     *
// errors stoi can throw. If either of those execute, an*
// error message is printed and a second throw is made, *
// caught by the calling function. When the conversion  *
// is successful, an int is returned.                   *
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
// called by: printAll, findLargest
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