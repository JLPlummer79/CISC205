/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#ifndef OPTIONS_H
#define OPTIONS_H
#include "record.h"

//function declarations for functions in options.cpp

void addNewCustomer(access::Record*, int&);

void editCustomer(access::Record*, int&);

int matchCustomer(const access::Record*, std::string, int&);

void searchContract(const access::Record*, int&);

void contractTotal(const access::Record*, int&);


#endif