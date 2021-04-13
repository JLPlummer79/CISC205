#include "Patient.h"
#include "PatientAccount.h"
#include <utility>
#include <iostream>
#include <cstdlib>
#include <limits>

//default constructor
Patient::Patient() {
    patientId = 0;
    name = " ";
    address = " ";
    phone = " ";
}

//overloaded constructor
Patient::Patient(std::string n, std::string a, std::string p, int id) {
    patientId = id;
    name = n;
    address = a;
    phone = p;
}

//Move constructor
Patient::Patient(Patient &&other) noexcept {
    *this = std::move(other);
}

//Move assignment operator
Patient& Patient::operator=(Patient &&other) noexcept {
    patientId = std::move(other.patientId);
    name = std::move(other.name);
    address = std::move(other.address);
    phone = std::move(other.phone);

    return *this;
}

//copy constructor
Patient::Patient(const Patient& other) {

    patientId = other.patientId;
    name = other.name;
    address = other.address;
    phone = other.phone;
}

//copy assignment operator
Patient& Patient::operator=(const Patient &other) {
    patientId = other.patientId;
    name = other.name;
    address = other.address;
    phone = other.phone;

    return *this;
}

//*******************************************************
// name: getPatientId
// called by: displayPatient, displayPatientAccount
// called by: validateUniqueNumber, newPatient
// called by: editPatient
// passed: nothing
// returns: const int
// The getPatientId member function returns the value   *
// of the member variable patientId                     *
//*******************************************************
const int Patient::getPatientId() const{
    return patientId;
}

//*******************************************************
// name: getName
// called by: displayPatient, displayPatientAccount
// called by: patientDisplayMenu, newPatient, editPatient
// called by: dischargePatient 
// passed: nothing
// returns: const std::string
// The getName member function returns the value of the *
// member variable name                                 *
//*******************************************************
const std::string Patient::getName() const{
    return name;
}

//*******************************************************
// name: getAddress
// called by: displayPatient, newPatient, editPatient
// passed: nothing
// returns: const std::string
// The getAddress member function returns the value of  *
// the member variable address                          *
//*******************************************************
const std::string Patient::getAddress() const{
    return address;
}

//*******************************************************
// name: getPhone
// called by: displayPatient, newPatient, editPatient
// passed: nothing
// returns: const std::string
// The getPhone member function returns the value of the*
// member variable phone                                *
//*******************************************************        
const std::string Patient::getPhone() const{
    return phone;
}

//*******************************************************
// name: setName
// called by: newPatient, editPatient
// passed: const std::string
// returns: nothing
// The setName member function validates the argument   *
// if invalid prints a message and exits the program. If*
// valid sets the member variable name equal to the arg *
//*******************************************************
void Patient::setName(const std::string nName) {
//low level validation
    if(nName.size() > 25 || nName.size() <= 0 || nName.empty()) {
    //helpful error message, then force quit program    
        std::cout << "ERROR. Name must be less than "
        << "25 characters and greater than zero." 
        <<" Exiting program.\n";    
        exit(EXIT_FAILURE);
    }
    name = nName; 
}

//*******************************************************
// name: setAddress
// called by: newPatient, editPatient
// passed: const std::string
// returns: nothing
// The setAddress member function validates the argument*
// if invalid prints a message and exits the program. If*
// valid sets the member variable address to the arg    *
//*******************************************************
void Patient::setAddress(const std::string nAddress) {
//low level validation    
    if(nAddress.size() > 50 || nAddress.size() <= 0 || nAddress.empty()) {
    //helpful error message, then force quit program    
        std::cout << "ERROR. Address must be less than "
        <<"50 characters and greater than zero."
        << " Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    address = nAddress;   
}

//*******************************************************
// name: setPhone
// called by: newPatient, editPatient
// passed: const std::string
// returns: nothing
// The setPhone member function validates the argument  *
// if invalid prints a message and quits the program.If *
// valid sets the member variable phone to the argument *
//*******************************************************
void Patient::setPhone(const std::string nPhone) {
//low level validation
    if(nPhone.size() > 11 || nPhone.size() <= 0 || nPhone.empty()) {
    //informative error message, then force quit program    
        std::cout << "ERROR. Phone Number must be "
        << "less than 11 characters and greater than "
        << " zero.  Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    phone = nPhone;
}

//*******************************************************
// name: setPatientId
// called by: newPatient, editPatient
// passed: const int
// returns: nothing
// The setPatientId member function validates the arg   *
// if invalid, prints a message and quits the program.If*
// valid then sets the member variable patientId to arg *
//*******************************************************
void Patient::setPatientId(const int id) {
//low level validation
if(id <= 0 || id >= std::numeric_limits<int>::max()) {
    //informative error message, then force quit program
    std::cout << "ERROR.  Patient Id must be greater "
    << "than zero and less than the maximum size of an"
    << "integer.  Exiting program.\n";
    exit(EXIT_FAILURE);
}    
    patientId = id;
}
