/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#ifndef MENU_H
#define MENU_H
#include "Yacht.h"

void menu(Yacht**);

void newYacht(Yacht**, int&, bool);

void newPowerBoat(Yacht**, int&, bool);

void printAll(Yacht**, int&);

void newSailBoat(Yacht**, int&, bool);


#endif