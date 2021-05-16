/*
 *
 * Jesse Plummer
 *
 * Chapter 16, Programming Challenge #7 Sea Pollution w/ try/catch
 *
 * May 17th, 2021
 * 
*/

#ifndef MENU_H
#define MENU_H
#include "SeaPollution.h"

//function declarations for menu.cpp
void menu(SeaPollution*);

void enterSea(SeaPollution*, int&);

int searchSeas(SeaPollution*, int&, std::string);

void searchSeasPrint(SeaPollution*, int&);

void compareSeas(SeaPollution*, int&);

void arithmeticSeas(SeaPollution*, int&);

void printAllSeas(SeaPollution*, int&);

void divider();


#endif