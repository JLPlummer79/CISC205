/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include "Painting.h"
#include <vector>

void addCustomer(std::vector<Painting>&);

void editCustomer(std::vector<Painting>&);

void findLargest(std::vector<Painting>);

void printAll(std::vector<Painting>);

int editCustomerMenu();

int matchCustomer(std::vector<Painting>&, const std::string);



#endif