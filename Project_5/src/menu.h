/*
 *
 * Jesse Plummer
 *
 * Chapter 14, Programming Challenge #5 Sea Pollution
 *
 * April 19th, 2021
 * 
*/

#ifndef MENU_H
#define MENU_H
#include "SeaPollution.h"

//function declarations for menu.cpp
void menu(SeaPollution*);

void enterSea(SeaPollution*, int&, bool);

int searchSeas(SeaPollution*, int&, std::string);

void searchSeasPrint(SeaPollution*, int&, bool);

void compareSeas(SeaPollution*, int&, bool);

void arithmeticSeas(SeaPollution*, int&, bool);

void printAllSeas(SeaPollution*, int&);

void divider();


#endif