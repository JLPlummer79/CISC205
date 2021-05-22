/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/

#include "options.h"
#include "Painting.h"
#include <vector>
#include <iostream>
#include <string>

void addCustomer(<Painting> boats) {
    std::string input;
    Painting boat;
    bool tryAgain = true;

    while(tryAgain) {

        std::cout << "Enter customer name, up to 15 characters: ";
        std::getline(std::cin, input);

        try{
            boat.setName(input);
            tryAgain = false;
        }
        catch(Painting::EmptyValue){
            std::cout << "\nError!"
            << " customer name must "
            << "be entered!\n";
        }
        catch(Painting::BigString e) {
            std::cout << "\nError! " <<
            e.getsName() << " too large."
            << "\n";
        }
    }//end while
    tryAgain = true;
    while(tryAgain) {
        std::cout << "Enter boat name, up to 15 characters: ";
        std::getline(std::cin, input);

        try{
            boat.setBoatName(input);
            tryAgain = false;
        }
        catch(Painting::EmptyValue) {
            std::cout << "\nError! " 
            << "Boat name must be "
            << "enterd!\n";
        }
        catch(Painting::BigString e) {
            std::cout << "\nError!" <<
            e.getsName() << " is too "
            << "large!\n";
        }

    }//end while
    tryAgain = true;
    
}//end addCustomer