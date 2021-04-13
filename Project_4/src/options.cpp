#include "options.h"
#include "menu.h"
#include "Patient.h"
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"
#include "error.h"
#include "display.h"
#include <iostream>
#include <string>

//*******************************************************
// name: newPatient
// called by: mainMenu
// passed: pointer to an array of type Patient 
// passed: a reference to a int
// returns: nothing
// The newPatient function is called by the mainMenu to *
// facilitate the process of adding a new patient. First*
// check if the array is full.  If it is not, the user  *
// is prompted to enter an id number, validates the user*
// input, then adds it to the object.  Next the user is *
// prompted to enter a patient name.  The input is      *
// validated, then the object is set.  Next the user is *
// prompted to enter the patient address, the input is  *
// validated, then added to the object. Next the user is*
// prompted to enter a patient phone number, the input  *
// is validated, then added to the object.  The last    *
// step is to add the object to the Patient array       *
//*******************************************************
void newPatient(Patient* customers, int& numPatients) {
    //hold the user input for verification
    std::string name,address,phone,idTemp;
    //will hold the id number after 1st verification
    int id;
    //holds the newly created object before it is added to the array
    Patient jDoe;      

    //ensure we do go beyond the capacity of the array
    if(numPatients > MAX) { 
        std::cout << "Unfortunately we are no longer accepting"
        << " patients at the Institute.\n";
    }

    else {
        //1st give the new patient a unique Id number
        std::cout << "Enter patient id number: ";
        std::getline(std::cin, idTemp);

        //validate input
        id = validatePatientId(customers, idTemp, numPatients);
        //add id to Patient object
        jDoe.setPatientId(id);
        //error/test checking remove later
        std::cout << "Patient Id: " << jDoe.getPatientId() 
        << '\n'; 

        //get patient's name
        std::cout << "Enter patient's name: ";
        std::getline(std::cin, name);

        //validate input
        name = validateName(name);

        //add name to Patient object
        jDoe.setName(name);
        //error checking remove later
        std::cout << "Pateint name: " << jDoe.getName() << '\n';

        //get patient address
        std::cout << "Enter patient's address: ";
        std::getline(std::cin, address);

        //validate input
        address = validateAddress(address);

        //add address to Patient object
        jDoe.setAddress(address);
        //error checking remove later
        std::cout << "Pateint address: " << jDoe.getAddress() << '\n';

        //get patient phone number
        std::cout << "Enter patient's phone number: ";
        std::getline(std::cin, phone);

        //validate input
        phone = validatePhone(phone);

        //add phone number to Patient object
        jDoe.setPhone(phone);
        //error checking remove later
        std::cout << "Pateint phone: " << jDoe.getPhone() << '\n';

        //add new patient to database
        customers[numPatients] = jDoe;

    }//end else
}//end newPatient

//*******************************************************
// name: editPatient
// called by: mainMenu 
// passed: a pointer to an array of type Patient, a     *
// passed: reference to an int
// returns: nothing
// The editPatient function first validates that the    *
// Patient array is not empty. Next the user is prompted*
// to select a patient using the patientDisplayMenu.    *
// Next the Edit Patient Menu is printed and the user is*
// prompted, the input is validated, then the program is*
// routed using a switch.  The user is prompted for an  *
// entry, the input is validated, then the array is     *
// updated.  The user is then returned to the Edit      *
// Patient Menu, where the user can edit the same       *
// patient, or exit the Edit Patient Menu and return to *
// Main Menu                                            *
//*******************************************************
void editPatient(Patient* customers, int& numPatients) {
    int choice;         //holds the user input for patient
    int flag = 0;       //controls while loop flow
    std::string input;  //holds user input
    int newId;          //temporaritly holds new Id

//validate that there are patients in the system
    if(numPatients <= 0) {
        std::cout << "No patients currently in system!\n";
        flag = 5;
    }
//call patient display menu, get user choice
    else{
        choice = patientDisplayMenu(customers, numPatients);
    }
//Edit patient menu 
    while(flag != 5) {
        header();
        std::cout << "Edit Patient Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Edit " << customers[choice].getName() 
                << " name\n";
        std::cout << "2. Edit " << customers[choice].getName() 
                << " address\n";
        std::cout << "3. Edit " << customers[choice].getName()
        << " phone number\n";
        std::cout << "4. Edit " << customers[choice].getName()
        << " patient Id\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Enter menu selection: ";
        
        //get user input
        std::getline(std::cin, input);

        //validate user input
        flag = checkSingleChar(input);

        switch(flag) {
            case 1:
            std::cout << "\nCurrent patient name: " << customers[choice].getName()
            << '\n';
            std::cout << "Enter new name: ";
            
            //get user input
            std::getline(std::cin, input);
            //validate user input
            input = validateName(input);
            //update the Patient array
            customers[choice].setName(input);

            //success message
            std::cout << "\nName updated!\n";
            break;

            case 2:
             std::cout << "\nCurrent patient address: " 
             << customers[choice].getAddress() << '\n';
            std::cout << "Enter new address: ";
            
            //get user input
            std::getline(std::cin, input);
            //validate user input
            input = validateAddress(input);
            //update the Patient array
            customers[choice].setAddress(input);

            //success message
            std::cout << "\nAddress updated!\n";
            break;

            case 3:
             std::cout << "\nCurrent patient phone number: " 
             << customers[choice].getPhone() << '\n';
            std::cout << "Enter new phone number: ";
            
            //get user input
            std::getline(std::cin, input);
            //validate user input
            input = validatePhone(input);
            //update the Patient array
            customers[choice].setPhone(input);

            //success message
            std::cout << "\nPhone Number updated!\n";
            break;
            
            case 4:
             std::cout << "\nCurrent patient Id: " 
             << customers[choice].getPatientId() << '\n';
             std::cout << "Enter new patient Id: ";
            
            //get user input
            std::getline(std::cin, input);
            //validate user input
             newId = validatePatientId(customers, input, numPatients);
            //update the Patient array
            customers[choice].setPatientId(newId);

            //success message
            std::cout << "Patient Id updated!\n";
            break;


        }//end switch

    }//end while

}//end editPatient

//*******************************************************
// name: displayPatientInfo
// called by:
// passed: a pointer to an array of Patient objects
// passed: a reference to an int
// returns: nothing
// The displayPatientInfo function checks that there are*
// patients in the system, if so the user is prompted to*
// select a record, then passes the desired record to a *
// function that prints out the data in a formatted style*
//*******************************************************
void displayPatientInfo(Patient* customers, int& numPatients){
    int pChoice = 0; // holds patient choice
    Patient record;

    if(numPatients <= 0) {
        std::cout << "No patients currently in system!\n";
    }
    else {
        pChoice = patientDisplayMenu(customers, numPatients);

        //copy-assign individual record from array to pass
        record = customers[pChoice];

        // display Patient members with record as argument
        displayPatient(record);       
    }

}//end displayPatientInto

//*******************************************************
// name: dischargePatient
// called by: mainMenu
// passed: a poiner to an array of Patient objects
// passed: a reference to an int
// returns: nothing
// The dischargePatient function ist verifies that the  *
// array has members.  Once this is verified, the user  *
// is prompted to select a Patient record, this input is*
// verified and returned, then the user is prompted to  *
// enter the hospital stay amount, that amount is       *
// validated, then the PatientAccount object updated.   *
// Next a Surgeries menu is displayed, and user input is*
// validated, & added to the PatientAccount object. Next*
// the same process is followed with displayMedsMenu    *
// Lastly displayPatientAccount is called, displaying   *
// the PatientAccount object in a specific format       *
//*******************************************************
void dischargePatient(Patient* customers, int& numPatients) {
    PatientAccount patient;
    int choice = 0; // holds patient choice
    std::string input;  // will hold user input initially
    int days;

    //ensure people are in system
    if(numPatients <= 0) {
        std::cout << "No patients currently in system!\n";
    }
    else {
        //print menu to choose a patient and return that user choice
        choice = patientDisplayMenu(customers, numPatients);
    
        //ask for days in hospital, validate entry, use result to add amount to PatientAccount
        std::cout << "Enter how many days " << customers[choice].getName() << " was in the hospital: ";
        std::getline(std::cin, input);

        //verify input
        days = validateDaysInHospital(input);

        //set days in hospital to current object
        patient.setDaysSpent(days);

        //call display surgeries menu and have user choose one add to PatientAccount, validate
        displaySurgeriesMenu(patient, customers[choice].getName());

        //call display meds and have user choose one add amount to PatientAccount, validate
        displayMedsMenu(patient, customers[choice].getName());

        //call a display 3 amounts, then display total charges.
        displayPatientAccount(patient, customers[choice]);
        
    }//end else

}//end dischargePatient

//*******************************************************
// name: totalCharges
// called by: displayPatientAccount
// passed: three floats
// returns: a float
// The totalharges function takes the 3 float args and  *
// calculates their sum and returns that sum            *
//*******************************************************
float totalCharges(float dCharges, float sCharges, float mCharges) {
    //will hold the total of charges
    float total;

    //calculate total charges
    total = dCharges + sCharges + mCharges;

    //return sum
    return total;

}//end totalCharges

