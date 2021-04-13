#ifndef MENU_H
#define MENU_H
#include "Patient.h"
#include "PatientAccount.h"

//function declarations for menu.cpp

void mainMenu(Patient* );  

const int patientDisplayMenu(Patient*, int&);

void displaySurgeriesMenu(PatientAccount&, std::string);

void displayMedsMenu(PatientAccount&, std::string);





#endif