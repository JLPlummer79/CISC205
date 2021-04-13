#include "menu.h"
#include "error.h"
#include "display.h"
#include "Patient.h"
#include "options.h"
#include <string>
#include <iostream>

//*******************************************************
// name: menu
// called by: main 
// passed: pointer to an array of type Patient
// returns: nothing
// The menu function controls the flow of the program   *
// using an initial Main Menu, validating user input and*
// functions to process user requests and enter data    *
//******************************************************
void mainMenu(Patient* customers) {

    std::string input;  // holds user input
    int flag = 0;       // variable to break/continue do/while
    char c;             //holds entry for error checking
    int numPatients = 0; //track the number of patients
    
    while(flag != 5) {
        //print institute heading
        header();

        //print main menu for user to make a selection
        std::cout << "\n              Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Enter new patient into system\n";
        std::cout << "2. Edit existing patient's information\n";
        std::cout << "3. Display selected patient's information\n";
        std::cout << "4. Discharge patient\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n\n";
        //get user input
        std::getline(std::cin,input);
        
        //validate user input
        flag = checkSingleChar(input);

        switch(flag) {
            case 1: 
                //call enterNewPatient to put through steps and interact directly with class
                newPatient(customers,numPatients);
                //ensure tracking of number of patients
                ++numPatients;
            break;

            case 2:
                //call editPatient to do the job
                editPatient(customers, numPatients);
            break;

            case 3:
                //call patientSearch
                displayPatientInfo(customers, numPatients);
            break;

            case 4:
                //call disPatient
                dischargePatient(customers, numPatients);
            break;

            case 5:
                std::cout << "Exiting Program.  Have a great day!\n";
                //this ends the while, and ends menu...but we can std::exit(0);
            break;
            
            //invalid input, start from the beginning of while
            default:
                std::cout << "Invalid input.  Please enter an option from the menu.\n";
            break;

        }//end switch

    }//end while

}//end mainMenu

//*******************************************************
// name: patientDisplayMenu
// called by: editPatient, dischargePatient,
// called by: displayPatientInfo
// passed: pointer to a Patient array, reference to an  *
// integer.
// returns: const int
// The patientDisplayMenu function prints a list of    *
// Patient objects present in the array passed to it,  *
// then prompts the user to enter a digit to select a  *
// patient record.  The user input is validated, then  *
// returned (minus 1 to access the array) to be used by*
// the calling function                                *
//*******************************************************
const int patientDisplayMenu(Patient* customers, int& numPatients) {
    std::string select;     // will hold the user selection before validation
    int flag = 0;           //control loop and hold validated user input

    // will repeat menu until user input is valid
    while(flag == 0) {
    
        std::cout << "\n\n*****Patient List*****\n\n";
        //display list of patients
        for(size_t i = 0; i < numPatients; ++i) {
            std::cout << i + 1 << ". ";
            std::cout << "Name: " << customers[i].getName() << " ";
            std::cout << '\n';
        }
        //get user input    
        std::cout << "\nEnter record number to select patient: ";
        std::getline(std::cin, select);

        //validate user entry
        flag = checkSingleChar(select);
        if(flag > numPatients || flag == 0) {
            std::cout << "\nThat entry is invalid. Please enter "
            << "a record number that is on screen: ";
            flag = 0;
        }
    }//end while

    //return user selection, reduce by 1 to access array
    return flag - 1;

}//end patientDisplayMenu

//*******************************************************
// name: displaySurgeriesMenu
// called by: dischargePatient
// passed: Reference to PatientAccount object, std::string
// returns: nothing
// The displaySurgeriesMeun function prints a menu of   *
// offered surgeries and associated costs in a menu then*
//prompts the user for a selection, validates the entry,*
//then sets the surgeryCost to the associated PatientAcc*
//-ount object                                          *
//*******************************************************
void displaySurgeriesMenu(PatientAccount& patient, std::string name) {
    std::string choice;     //will hold user selection 
    int flag = 0;           //will control loop & hold validated user input
    Surgery cost;           //object will access the necessary values

    //print a menu for the user to select surgery
    while(flag == 0) {
        std::cout << "\n****Select Surgery performed on " << name << "****\n";
        std::cout << "1. Othroscopic ($" << cost.getOthroCost() << ")\n";
        std::cout << "2. Eye ($" << cost.getEyeCost() << ")\n";
        std::cout << "3. Heart ($" << cost.getCardioCost() << ")\n";
        std::cout << "4. Brain ($" << cost.getBrainCost() << ")\n";
        std::cout << "5. Tommy-John ($" << cost.getTommyJohnCost() << ")\n";
        std::cout << "Enter Surgical Choice: ";

        //get user input
        std::getline(std::cin, choice);
        
        //validate user input
        flag = checkSingleChar(choice);

        //assign surgery cost and surgery name to patientAccount object
        switch(flag){
            case 1:
                patient.setSurgeryCharges(cost.getOthroCost());
                patient.setSurgeryName(cost.getOthro()); 
            break;

            case 2:
                patient.setSurgeryCharges(cost.getEyeCost());
                patient.setSurgeryName(cost.getEye());
            break;

            case 3:
                patient.setSurgeryCharges(cost.getCardioCost());
                patient.setSurgeryName(cost.getCardio());
            break;

            case 4:
                patient.setSurgeryCharges(cost.getBrainCost());
                patient.setSurgeryName(cost.getBrain());
            break;

            case 5:
                patient.setSurgeryCharges(cost.getTommyJohnCost());
                patient.setSurgeryName(cost.getTommyJohn());
            break;

            default:
                std::cout << "\nInvalid entry.  Please choose a selection from the menu.\n";
                flag = 0;
            break;

        }//end switch

    }//end while

}//end displaySurgeriesMenu

//*******************************************************
// name: displayMedsMenu
// called by: dischargePatient
// passed: Reference to a PatientAccount obj, std::string
// returns: nothing
// The displayMedsMenu function prints a menu that lists*
// the names and costs of the medicine and prompts the  *
// user to enter a selection, then validates the user   *
//input, then sets the medication price and name with   *
// the PatientAccount reference                         *
//*******************************************************
void displayMedsMenu(PatientAccount& patient, std::string name) {
    std::string choice;         //holds user selection
    int flag = 0;               //control flow of loop 
    Pharmacy cost;              //object to access the data we need

    //print Medicine menu for the user to make a selection from
    while(flag == 0) {
        std::cout << "****Select Medicine administered to " << name << "****\n";
        std::cout << "1. Amoxcacillin ($" << cost.getAmoxCost() << ")\n";
        std::cout << "2. Morphine ($" << cost.getMorphCost() << ")\n";
        std::cout << "3. Ketamine ($" << cost.getKetamineCost() << ")\n";
        std::cout << "4. Asprin ($" << cost.getAsprinCost() << ")\n";
        std::cout << "5. Oxycontin ($" << cost.getOxyCost() << ")\n";
        std::cout << "Enter medication choice: ";

        //get user input
        std::getline(std::cin, choice);

        //verify user input
        flag = checkSingleChar(choice);

        //assign medicine cost and name to PatientAccount object
        //message prints for each case
        switch(flag){
            case 1:
                patient.setMedCharges(cost.getAmoxCost());
                patient.setMedName(cost.getAmox());
            break;

            case 2:
                patient.setMedCharges(cost.getMorphCost());
                patient.setMedName(cost.getMorph());
            break;

            case 3:
                patient.setMedCharges(cost.getKetamineCost());
                patient.setMedName(cost.getKeta());
            break;

            case 4:
                patient.setMedCharges(cost.getAsprinCost());
                patient.setMedName(cost.getAspr());
            break;

            case 5:
                patient.setMedCharges(cost.getOxyCost());
                patient.setMedName(cost.getOxy());
            break;

            //message for invalid entries.  Loop continues.
            default:
                std::cout << "\nEntry invalid.  Please enter a choice from the menu.\n";
                flag = 0;
            break;

        }//end switch

    }//end while

}//end displayMedsMenu



