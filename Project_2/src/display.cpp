/*
 *
 * Jesse Plummer
 *
 * Chapter 9, Programming Challenge 2: Array manipulation
 *
 * March 15th, 2021
 * 
*/

#include "display.h"
#include <iostream>
#include <iomanip>

//*******************************************************
// name: display
// called by: main, dblValues, dblSizeArray
// passed: const float*, const int
// returns: nothing
// The display function prints the data in an organized *
// fashion for improved user consumption                *
//*******************************************************
void display(const float* set, const int size) {
    
    divider();
    //print contents of passed array with precision of 4 decimal places.
    for(auto i = 0; i < size; ++i) {
        std::cout << "Element[" << i << "] is " << 
        std::fixed << std::setprecision(4) << set[i] << '\n';
    }
    divider();
}
//*******************************************************
// name: divider
// called by: display, main
// passed: nothing
// returns: nothing
// The divider function prints out a formatted line  to *
// enhance the display of the data                      *
//*******************************************************
void divider() {
    std::cout << std::setw(42) << std::setfill('*')  << '\n' << std::setfill(' ');
}