/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#include "menu.h"
#include "Yacht.h"
#include "error.h"
#include <iostream>
#include <string>


void menu(Yacht* marina) {

//holds user input
std::string input;

//holds string on/off
std::string phrase;

//control flow of loop and switch
int choice = 0;

//control high level on/off toggle
bool validation = true;

//track number of Yachts in array
int numVessel = 0;

while(choice != -1) {
    std::cout << "\n<---------------Main Menu---------------->\n";
    std::cout << "1. Enter data for new Yacht.\n";
    std::cout << "2. Enter data for new Powerboat.\n";
    std::cout << "3. Enter data for new Sailboat.\n";
    std::cout << "4. Display contents of the Marina.\n";
    std::cout << "5. Toggle on/off high level validation.\n";
    std::cout << "6. Exit program.\n";
    std::cout << "<---------------------------------------->\n";
    std::cout << "Please enter selection: ";

    //get user input
    std::getline(std::cin, input);

    //error checking    
    choice = checkSingleInt(input);

    switch(choice) {
        case 1:
            std::cout << "Calling newYacht\n";
            newYacht(marina, numVessel,validation);
        break;

        case 2:
            std::cout << "Calling newPowerBoat\n";
        break;

        case 3:
            std::cout << "Calling newSailBoat\n";
        break;

        case 4:
            std::cout << "Calling display all\n";
        break;

        case 5:
            if(validation == true) {
                validation = false;
                phrase = "off";
            }
            else {
                validation = true;
                phrase = "on";
            }

            std::cout << "High level validation is "
            << phrase << "\n";
        break;

        case 6:
            std::cout << "Exiting program.  Be well!\n";
            choice = -1;
        break;

        default: //may not need this... but we may need it.
            std::cout << "Unrecognized entry.  Please " 
            << "enter a single digit from the menu above.\n";
        break;
    }//end switch

}//end while

}//end menu

void newYacht(Yacht* marina, int& numVessel, bool validation) {
    // holds user input
    std::string input;

    //will hold new object
    Yacht ark;


    //will hold the length
    float len;

    if(numVessel >= MAX){
        std::cout << "The marina is full!\n";
    }

    else {

        std::cout << "Enter name of Yacht: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            //validating name
            input = validateString(input, input.size());
        }
        //set Yacht name
        ark.setName(input);

        std::cout << "\nEnter length of Yacht: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            len = checkValidFloat(input);
        }
        else {
            len = stof(input);
        }
        //set Yacht length
        ark.setLength(len);

        std::cout << "\nEnter year constructed: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            input = validateString(input, input.size());
        }
        //set Yacht year
        ark.setYearBuilt(input);
    }//end else

    // add new object to the array
    marina[numVessel] = ark;
}//end newYacht