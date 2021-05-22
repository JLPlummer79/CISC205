
/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/
#include "menu.h"
#include <vector>
#include <string>

void menu(<Painting> boats) {

    std::string input;
    int flag = 0;

    while(flag != -1) {
        std::cout << "\n\n              Main Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Input a customer's information\n";
        std::cout << "2. Edit a customer's information\n";
        std::cout << "3. Search for contract by value\n";
        std::cout << "4. Display all contract information\n";
        std::cout << "5. Exit\n";
        std::cout << "----------------------------------------\n\n";
        std::getline(std::cin,input);

        switch(flag) {
            case 1:
                std::cout << "Input cust info.\n";
                //call addCustomer(<vector>)
            break;

            case 2:
                std::cout << "Edit a customer's info.\n";
                //call editCustomer(<vector>)
            break;

            case 3:
                std::cout << "Find largest contract.\n";
                //call findLargest(<vector>)
            break;

            case 4:
                std::cout << "Print all contracts. With total at end.\n";
                //print all contracts using print() function 
                // & overloaded stream operator
            break;

            case 5:
                std::cout << "Exiting program. Be well!\n";
                flag = -1;
            break;
        }

    }//end while

}//end menu