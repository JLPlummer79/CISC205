#include "PatientAccount.h"
#include <utility>
#include <string>
#include <iostream>
#include <cstdlib>

//default constructor
PatientAccount::PatientAccount() {

    daysSpent = 0;
    surgeryCharges = 0;
    medCharges = 0;

}

//overloaded constructor
PatientAccount::PatientAccount(int days, float sTotal, float mTotal) {
    daysSpent = days;
    surgeryCharges = sTotal;
    medCharges = mTotal;

}

//*******************************************************
// name: getDaysSpent
// called by: displayPatientAccount
// passed: nothing
// returns: const int
// The getDaysSpent member function returns the value of*
// the daysSpent member variable                        *
//*******************************************************
const int PatientAccount::getDaysSpent() const{
    return daysSpent;
}

//*******************************************************
// name: getSurgeryCharges
// called by: displayPatientAccount
// passed: nothing
// returns: const int
// The getSurgeryCharges member function returns the    *
// value of the surgeryCharges member variable          *
//*******************************************************
const float PatientAccount::getSurgeryCharges() const{
    return surgeryCharges;
}

//*******************************************************
// name: getMedCharges
// called by: displayPatientAccount
// passed: nothing
// returns: const float
// The getMedCharges member function returns the value  *
// of the member variable medCharges                    *
//*******************************************************
const float PatientAccount::getMedCharges() const {
    return medCharges;
}

//*******************************************************
// name: getMedName
// called by: displayPatientAccount
// passed: nothing
// returns: const std::string
// The getMedName member function returns the value of  *
// the member variable medicationName                   *
//*******************************************************
const std::string PatientAccount::getMedName() const {
    return medicationName;
}

//*******************************************************
// name: getSurgeryName
// called by: displayPatientAccount
// passed: nothing
// returns: const std::string
// The getSurgeryName member function returns the value *
// of member variable surgeryName                       *
//*******************************************************
const std::string PatientAccount::getSurgeryName() const {
    return surgeryName;
}

//*******************************************************
// name: calcDaysSpentCharges
// called by: displayPatientAccount
// passed: nothing
// returns: float
// The calcDaysSpentCharges member function returns the *
// result of the calculation of the daysSpent member    *
// variable multiplied by the const HOSPITAL_RATE       *
//*******************************************************
float PatientAccount::calcDaysSpentCharges() {

    return daysSpent * HOSPITAL_RATE;
}

//*******************************************************
// name: setSurgeryCharges
// called by: displaySurgeriesMenu
// passed: const float
// returns: nothing
// The setSurgeryCharges function validates the argument*
// exits the program if it is invald. If valid, the     *
// member variable surgeryCharges is set to the argument*
//*******************************************************
void PatientAccount::setSurgeryCharges(const float amt) {
    if(amt <= 0) {
        std::cout << "ERROR.  Surgery charges must "
        << "be greater than zero." << " Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    surgeryCharges = amt;
}

//*******************************************************
// name: setMedCharges
// called by: displayMedsMenu
// passed: const float
// returns: nothing
// The setMedCharges member function validates the arg  *
// and exits the program if the amount is invalid. If   *
// valid, the member variable medCharges is set to the  *
// argument                                             *
//*******************************************************
void PatientAccount::setMedCharges(const float amt) {
    if(amt <= 0) {
        std::cout << "ERROR. Medicine charges must "
        << "be greater than zero.  Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    medCharges = amt;
}

//*******************************************************
// name: setDaysSpent
// called by: dischargePatient
// passed: const int
// returns: nothing
// The setDaysSpent member function validates the arg   *
// and exits the program if the amount is invalid. If   *
// valid, the member variable daysSpent is set to the   *
// argument.                                            *
//*******************************************************
void PatientAccount::setDaysSpent(const int days) {
    if(days <= 0) {
        std::cout << "ERROR.  Days spent must be "
        << "greater than zero.  Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    daysSpent = days;
}

//*******************************************************
// name: setSurgryName
// called by: displaySurgeriesMenu
// passed: const std::string
// returns: nothing
// The setSurgeryName member function validates the arg *
// and exits the program if found invalid.  If valid the*
// member variable surgeryName is set to the arugment   *
//*******************************************************
void PatientAccount::setSurgeryName(const std::string name) {
    if(name.empty()){
        std::cout << "ERROR.  Surgery name cannot be empty. "
        << "Exiting program.\n";
        exit(EXIT_FAILURE);
    }
    surgeryName = name;
}

//*******************************************************
// name: setMedName
// called by: displayMedsMenu
// passed: const std::string
// returns: nothing
// The setMedName member function validates the argument*
// and exits the program if found invalid.  If valid the*
// member variable medicationName is set to the arugment*
//*******************************************************
void PatientAccount::setMedName(const std::string name) {
    if(name.empty()){
        std::cout << "ERROR.  Medication name cannot be empty. "
        << "Exiting Program.\n";
        exit(EXIT_FAILURE);
    }
    medicationName = name;
}

//move constructor
PatientAccount::PatientAccount(PatientAccount &&other) noexcept {
    *this = std::move(other);
}

//move assignment operator
PatientAccount& PatientAccount::operator=(PatientAccount &&other) noexcept {
    surgeryCharges= std::move(other.surgeryCharges);
    medCharges = std::move(other.medCharges);
    daysSpent = std::move(other.daysSpent);

    return *this;
}

//copy constructor
PatientAccount::PatientAccount(const PatientAccount& other) {
    surgeryCharges = other.surgeryCharges;
    medCharges = other.medCharges;
    daysSpent = other.daysSpent;
}

//copy assignment operator
PatientAccount& PatientAccount::operator=(const PatientAccount &other) {
    surgeryCharges = other.surgeryCharges;
    medCharges = other.medCharges;
    daysSpent = other.daysSpent;

    return *this;
}