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

//*******************************************************
// name: addCustomer
// called by: menu
// passed: std::vector<Painting>&
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void addCustomer(std::vector<Painting>& boats) {
    std::string input;
    Painting boat;
    bool tryAgain = true;
    float value;

    while(tryAgain) {

        std::cout << "Enter customer name, up to 15 characters: ";
        std::getline(std::cin, input);

        try{
            boat.setName(input);
            tryAgain = false;
        }
        catch(Painting::EmptyValue){
            std::cout << "\nError!"
            << " Customer name must "
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
            std::cout << "\nError! " <<
            e.getsName() << " is too "
            << "large!\n";
        }

    }//end while
    tryAgain = true;

    //adding contract information
    while(tryAgain) {
        std::cout << "Enter contract value, must be zero or greater: ";
        std::getline(std::cin, input);

        try{
            value = boat.convertFloat(input);
        }

        catch(Painting::ImpossibleStr e) {
            std::cout << "\nError! " <<
            e.getIStr() << '\n';
            continue;
        }
        try {
            boat.setContract(value);
            tryAgain = false;
        }
        catch(Painting::NegativeValue e) {
            std::cout << "\nError! " << 
            e.getValue() << " is invalid!\n";
        }
    }//end while
    tryAgain = true;

    //add paid to date information
    while(tryAgain) {
        std::cout << "Enter amount of contract paid, must be zero or greater: ";
        std::getline(std::cin, input);

        try{
            value = boat.convertFloat(input);
        }
        catch(Painting::ImpossibleStr e) {
            std::cout << "\nError! " <<
            e.getIStr() << '\n';
            continue;
        }
        try{
            boat.setPaidToDate(value);
            tryAgain = false;
        }
        catch(Painting::NegativeValue e) {
            std::cout << "\nError! " << 
            e.getValue() << " is invalid!\n";
        }
        //do we need to compare paidToDate and contract? error thrown if they paid too much?
    }//end while

    boats.push_back(boat);

}//end addCustomer

//*******************************************************
// name: printAll
// called by: menu
// passed: std::vector<Painting>
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void printAll(std::vector<Painting> boats) {
    //holds total
    float total;
    //holds running total for overloaded adding
    Painting shell;

    for(int i = 0; i < boats.size(); ++i) {
        boats[i].print();

        total = shell + boats[i];

        shell.setContract(total);     
    }

    //rough draft. Read specs
    std::cout << "\nTotal: " << total << '\n';
}//end printAll



//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************