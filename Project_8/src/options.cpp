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
        catch(Painting::EmptyValue){
            std::cout << "Error!\n"
            << "A contract value must be entered!\n";
            continue;
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
        catch(Painting::EmptyValue){
            std::cout << "Error!\n"
            << "A contract value must be entered!\n";
            continue;
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
// name: editCustomerMenu
// called by:
// passed: nothing
// returns: int
// The 'name' function 'what function does'             *
//*******************************************************
int editCustomerMenu() {
    int flag = 0;
    std::string input;
    Painting blank;

    //editCustomer menu
    while(flag != -1){
        std::cout << "         Edit Customer Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Edit customer name\n";
        std::cout << "2. Edit boat name\n";
        std::cout << "3. Edit contract value\n";
        std::cout << "4. Edit paid to date amount\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "----------------------------------------\n\n";
        
        std::getline(std::cin, input);
        try{
            flag = blank.convertSingleInt(input);
        }
        catch(Painting::EmptyValue) {
            std::cout << "Error!\n"
            << eMess;
            continue;
        }
        catch(Painting::BigString e) {
            std::cout << "Error!\n"
            << e.getsName() << " is"
            << " invalid!" << eMess ;
            continue;
        }
        catch(Painting::ImpossibleStr e) {
            std::cout << "Error!\n"
            << e.getIStr() << eMess;
            continue;
        }
        
        switch(flag) {
            case 1: 
            case 2: 
            case 3:
            case 4:
                return flag;
                break;
            case 5:
                flag = -1;
                break;
            default:
                std::cout << "Invalid entry.  Please enter a menu option.\n";
            break;
        }
    }//end while
    return 0;
}

//*******************************************************
// name: matchCustomer
// called by:
// passed: std::vector<Painting>&, const std::string
// returns: int
// The 'name' function 'what function does'             *
//*******************************************************
int matchCustomer(std::vector<Painting>& boats, const std::string name) {
    int index = -1;
    for(int i = 0; i < boats.size(); ++i) {
        if(boats[i].getName() == name) {
            index = i;
        }
    }
    return index;
}

void editCustomer(std::vector<Painting>& boats) {
    std::string customer,entry;
    int index = -1;
    int flag = 1;
    int field;
    float value;
    Painting boat;
    
    while(flag != -1) {
        std::cout << "\nEnter customer name you wish to edit: ";
        std::getline(std::cin, customer);
        
        //find & match customer index
        index = matchCustomer(boats, customer);
        if(index == -1) {
            std::cout << "\nCustomer not found!\n";
            continue;
        }
        
        field = editCustomerMenu();

        switch(field){
            case 0:
                flag = -1;   
            break;
            case 1:
                std::cout << "Enter customer name: ";
                std::getline(std::cin, entry);
                try{
                    boats[index].setName(entry);
                    flag = -1;
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
            break;
            case 2:
                std::cout << "\nEnter updated boat name: ";
                std::getline(std::cin,entry);
                try{
                    boats[index].setBoatName(entry);
                    flag = -1;
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
            break;
            case 3:
                std::cout << "\nEnter updated contract value: ";
                std::getline(std::cin, entry);
                try{
                    value = boat.convertFloat(entry);
                }
                catch(Painting::EmptyValue){
                    std::cout << "Error!\n"
                    << "A contract value must be entered!\n";
                    continue;
                }
                catch(Painting::ImpossibleStr e) {
                    std::cout << "\nError! " <<
                    e.getIStr() << '\n';
                    continue;
                }
                try {
                    boats[index].setContract(value);
                    flag = -1;
                }
                catch(Painting::NegativeValue e) {
                    std::cout << "\nError! " << 
                    e.getValue() << " is invalid!\n";
                }
            break;
            case 4:
                std::cout <<"\nEnter updated paid to date amount: ";
                std::getline(std::cin, entry);
                
                try{
                    value = boat.convertFloat(entry);
                }
                catch(Painting::EmptyValue){
                    std::cout << "Error!\n"
                    << "A contract value must be entered!\n";
                    continue;
                }
                catch(Painting::ImpossibleStr e) {
                    std::cout << "\nError! " <<
                    e.getIStr() << '\n';
                    continue;
                }
                try {
                    boats[index].setPaidToDate(value);
                    flag = -1;
                }
                catch(Painting::NegativeValue e) {
                    std::cout << "\nError! " << 
                    e.getValue() << " is invalid!\n";
                }
                
            break;
            default:
                std::cout << "Unknown error.  A glitch in the Matrix perhaps?\n";
            break;

        }//end switch

    }//end while

}//end editCustomer

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************