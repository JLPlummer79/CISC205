/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#include "menu.h"
#include "error.h"
#include "options.h"
#include "display.h"
#include <string>
#include <iostream>


//*******************************************************
// name: menu
// called by: main
// passed:  
// passed: const int size
// returns: nothing
// The menu function controls the flow of the program   *
// using an initial Main Menu, validating user input and*
// functions to process user requests and enter data    *
//*******************************************************
void menu(access::Record* customerData) {
    std::string input;      //hold user input
    int flag = 0;           //hold menu cont/exit
    char c;                 //hold error check
    int numCustomers = 0;   //keep track of number of customers

    //keep menu looping until 5 entered
    while(flag != 5 ) {
        //print company header
        printHeader();

        std::cout << "\n              Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Input a customer's information\n";
        std::cout << "2. Edit a customer's information\n";
        std::cout << "3. Search for contract by value\n";
        std::cout << "4. Display all contract information\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n\n";
        std::getline(std::cin,input);

        //validate user input
        flag = checkSingleChar(input);

        switch(flag) {
            case 1:
            //add customer to customerData
                addNewCustomer(customerData, numCustomers);
            break;

            case 2:
            //edit existing customer 
                editCustomer(customerData, numCustomers);
            break;

            case 3:
            //search for contracts equal or greater than
            //specified amount
                searchContract(customerData, numCustomers);
            break;

            case 4:
            //Display all contract info, print total of contracts
            contractTotal(customerData, numCustomers);
            break;

            case 5:
            //Exit program
                std::cout << "Exiting program\n";
                 border();
            std::exit(0);

            default:
            //invalid input, start from beginning
                std::cout <<"Invalid input, please enter option from menu.\n";
            break;
        }//end switch

    }//end while
}//end menu

//*******************************************************
// name: editCustomerMenu
// called by: editCustomer
// passed: const std::string
// returns: const int
// The editCustomerMenu function prints the             *
// Edit Customer Menu, validate the user input, then    *
// returns the valid user entry, or prompts the user for*
// a valid entry.                                       *
//*******************************************************
const int editCustomerMenu(const std::string name) {
    //declare variables
    int flag = 0;               //loop monitor
    std::string input;          //holds user input

    //print Company heading
    printHeader();

    //editCustomer menu
    while(flag != 5){
        std::cout << "\n\n       Edit Customer Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Edit customer name\n";
        std::cout << "2. Edit boat name\n";
        std::cout << "3. Edit contract value\n";
        std::cout << "4. Edit paid to date amount\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Currently selected customer to edit: " << name << ".\n\n";
        
        //get input
        std::getline(std::cin, input);

        //validate input
        flag = checkSingleChar(input);
        
        //return user choice for editCustomer function to handle
        //or prompt a valid entry
        switch(flag) {
            case 1: 
            case 2: 
            case 3:
            case 4:
                return flag;
            break;
            case 5:
                flag = 5;
            break;
            default:
                std::cout << "Invalid entry.  Please enter a menu option.\n";
            break;
        } //end switch
    }//end while

    //Exit choice, will bring user to Main Menu
    return 0;

}//end editCustomerMenu