/*
 *
 * Jesse Plummer
 *
 * Chapter 14, Programming Challenge #5 Sea Pollution
 *
 * April 19th, 2021
 * 
*/
#include "menu.h"
#include "SeaPollution.h"
#include "error.h"
#include <iostream>
#include <string>

//*******************************************************
// name: menu
// called by: main
// passed: pointer to an array of SeaPollution objects
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void menu(SeaPollution* seas) {
    //holds user input 
    std::string input;
    //variable to control flow
    int choice = 0;
    //will control on/off for high level validation
    bool validation = true;
    //tracks how many seas are in the array
    int numSeas;

    while (choice != 7) {
        //main menu display
        std::cout << "<---------------Main Menu---------------->\n";
        std::cout << "1. Enter data for one sea.\n";
        std::cout << "2. Search for sea in system.\n";
        std::cout << "3. Compare two seas.\n";
        std::cout << "4. Combine to seas.\n";
        std::cout << "5. Display all seas.\n";
        std::cout << "6. Toggle on/off high level validation.\n";
        std::cout << "7. Exit program.\n";
        std::cout << "<---------------------------------------->\n";
        std::cout << "Please enter selection: ";
        //get user input
        std::getline(std::cin, input);
        //validate user input
        choice = checkSingleChar(input);

        switch(choice) {
            case 1:
            //call enterSea(SeaPollution*, int, bool) array, numSeas, validation on/off
            std::cout << "Calling enterSea\n";
            //track number of seas
            ++numSeas;
            break;

            case 2:
            //call searchSeas(SeaPollution*, int, bool) array, numSeas, validation on/off
            std::cout << "Calling searchSeas\n";
            break;

            case 3:
            //call compareSeas(SeaPollution*, int bool) array, numSeas, validaton on/off
            std::cout << "Calling compareSeas\n";
            break;

            case 4:
            //call combineSeas(SeaPollution*, int, bool) array, numSeas, validation on/off
            std::cout << "Calling combineSeas\n";
            break;

            case 5:
            //call printSeas(SeaPollution*, int) array, numSeas (no need for validation)
            std::cout << "Calling printSeas\n";
            break;

            case 6:
                //toggle validation off
                if(validation == true) {
                    std::cout << "Turning high level validation off!\n";
                    validation = false;
                }
                //toggle validatoin on
                else if(validation == false) {
                    std::cout << "Turning high level validation on!\n";
                    validation = true;
                }
            break;

            case 7:
                std::cout << "Exiting program.  Have a nice day!\n";
                //could use std::exit(0), but this will break the while and end menu
            break;

        }//end switch

    }//end while

}//end menu function

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************