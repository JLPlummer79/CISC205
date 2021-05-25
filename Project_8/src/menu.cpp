
/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/
#include "menu.h"
#include "options.h"
#include "Painting.h"
#include <vector>
#include <string>

//*******************************************************
// name: menu
// called by: main
// passed: std::vector<Painting>
// returns: nothing
// The menu function prints the menu for the user to    *
// interact with. User entry is processed (error        *
// checking and conversion) then functions to perform   *
// the other actions are called.                        *
//*******************************************************

void menu(std::vector<Painting> boats) {

    std::string input;
    int flag = 0;
    Painting shell;

    
    while(flag != -1) {
        std::cout << "\n\n              Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Input a customer's information\n";
        std::cout << "2. Edit a customer's information\n";
        std::cout << "3. Find Largest Contract\n";
        std::cout << "4. Display all contract information\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n\n";
        std::getline(std::cin,input);

        //perform error checking and str->int conversion try/catch block to handle errors
        try{
            flag = shell.convertSingleInt(input);
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
        
        //handles cases when try block executes as expected
        switch(flag) {
            case 1:
                std::cout << "Input cust info.\n";
                addCustomer(boats);
            break;

            case 2:
                std::cout << "Edit a customer's info.\n";
                editCustomer(boats);
            break;

            case 3:
                std::cout << "Find largest contract.\n";
                findLargest(boats);
            break;

            case 4:
                std::cout << "Print all contracts. With total at end.\n";
                printAll(boats);
            break;

            case 5:
                std::cout << "Exiting program. Be well!\n";
                flag = -1;
            break;

            default:
                std::cout << "Error! Entry is invalid.\n"
                << eMess;
                flag = 0;
            break;
        }//end switch

    }//end while

}//end menu