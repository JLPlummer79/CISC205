/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/
#include "display.h"
#include "record.h"
#include <iostream>
#include <iomanip>

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what functin does'              *
//*******************************************************

void printContract(const access::Record* customerData, int& numCustomers) {
    //holds current record being printed
    access::Record current;

    //print company header
    printHeader();
    
    //print border for data display
    border();

    //set number of decimal places
    std::cout << std::setprecision(2) << std::fixed;

    //print heading for customer data
    std::cout << std::setw(20) << "Name" 
    << std::setw(20) << "Boat Name" 
    << std::setw(20) << "Contract Value" 
    << std::setw(20) << "Paid To Date\n";

    //print the actual customer data based on the 
    //number of current cusotmers
    for (int i = 0; i < numCustomers; ++i) {
        current = customerData[i];
        std::cout << std::setw(20) << current.customer 
        << std::setw(20) << current.boatName 
        << std::right << std::setw(10) << '$'
        << std::right << std::setw(10) << current.contract 
        << std::right << std::setw(10) << '$'
        << std::right<< std::setw(10) << current.ptd << '\n';
    }
    //print border for data display
    border();
}

//*******************************************************
// name: printHeader
// called by: printContract, menu, editCustomerMenu
// passed: nothing
// returns: nothing
// The printHeader function prints the company name in  *
// a header type fashion                                *
//*******************************************************
void printHeader() {
    std::cout << "\n\n\n";
    std::cout << "******************************\n\n";
    std::cout << std::setw(15) << "Ivo's Yacht Painting Company\n\n";
    std::cout << "******************************\n\n\n";
}

//*******************************************************
// name: border
// called by: printContract, menu, contractTotal
// passed: nothing
// returns: nothing
// The border function formatted line for the purpose of*
// data presentation                                    * 
//*******************************************************
void border() {
    int width = 80;
    std::cout << '\n' << std::setfill('-') << std::setw(width) 
    << '\n' << std::setfill(' ');
}