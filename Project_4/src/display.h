#ifndef DISPLAY_H
#define DISPLAY_H
#include "Patient.h"
#include "PatientAccount.h"
#include "options.h"

//function declarations for display.cpp
void header();

void displayPatient(Patient);

void border();

void displayPatientAccount(PatientAccount&, Patient);

#endif