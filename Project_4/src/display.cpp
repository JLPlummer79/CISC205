#include "display.h"
#include "Patient.h"
#include <iostream>
#include <iomanip>

//*******************************************************
// name: header
// called by: mainMenu, newPatient
// passed: nothing
// returns: nothing
// The header function prints the full institute name   *
// in a header type fashion                             *
//*******************************************************
void header() {
    std::cout << "\n\n\n";
    std::cout << "**************************************\n\n";
    std::cout << std::setw(15) << "Institute for the Very, Very Nervous\n\n";
    std::cout << "**************************************\n\n\n";
}

//*******************************************************
// name: border
// called by: displayPatient, displayPatientAccount
// passed: nothing
// returns: nothing
// The border function prints a formatted character at  *
// a set width, for data presentation purposes          *
//*******************************************************
void border() {
    int width = 80;
    std::cout << '\n' << std::setfill('-') << std::setw(width) 
    << '\n' << std::setfill(' ');
}

//*******************************************************
// name: displayPatient
// called by: displayPatientInfo
// passed: Patient object
// returns: nothing
// The displayPatient function prints the arg object    *
// in a fomatted presentation                           *
//*******************************************************
void displayPatient(Patient record) {
    //print Institute header
    header();

    //print heading for data
    std::cout << "\nPatient Information";

    //print dividing border
    border();

    //print Patient info (members of patient class)
    std::cout << "Patient Id   "<< std::setw(15) << record.getPatientId() 
    << "\n\n";
    std::cout << "Name         " << std::setw(15) << record.getName()
    << "\n\n";
    std::cout << "Address      " << std::setw(15) << record.getAddress()
    << "\n\n";
    std::cout << "Phone Number " << std::setw(15) << record.getPhone()
    << "\n\n";

    //print dividing border
    border();

    std::cout << '\n';

}//end displayPatient

//*******************************************************
// name: displayPatientAccount
// called by: dischargePatient
// passed: a reference to a PatientAccount object
// passed: a Patient object
// returns: nothing
// The displayPatientAccount function obtains the total *
// charges (to a patient), then displays the data stored*
// in the PatientAccount object we are referencing, as  *
// well as the data stored in the arg Patient object    *
// in a particular format that is useful to the user    *
//*******************************************************
void displayPatientAccount(PatientAccount& invoice, Patient record) {
    float value;        //holds the result of totalCharges function
    
    //get the total charges
    value = totalCharges(invoice.calcDaysSpentCharges(), invoice.getSurgeryCharges(), invoice.getMedCharges());
    
    //print institute header
    header();
    
    //print patient & patient account data in a formatted easy to read fashion
    std::cout << "\n     ****Patient Discharge Invoice****     ";
    
    border();
    
    std::cout << "Patient Id   " << std::setw(15) << record.getPatientId()
    << "\n\n";
    std::cout << "Name         " << std::setw(15) << record.getName()
    << "\n\n";

    std::cout << "Hospital Charge: " << std::setw(10) << std::setprecision(2) << std::fixed
    << '$' << invoice.calcDaysSpentCharges() << "( " << invoice.getDaysSpent() << " days )\n";

    std::cout << "Surgical Charge: " << std::setw(10) << std::fixed
     << '$' << invoice.getSurgeryCharges() << "( " << invoice.getSurgeryName() << " )\n";

    std::cout << "Medication Charge: " << std::setw(8) << std::fixed
    << '$' << invoice.getMedCharges() << " ( " << invoice.getMedName() << " )\n";

    std::cout << "Total: " << std::fixed << std::setw(20) << '$' << value << '\n';

    border();

}//end displayPatientAccount
