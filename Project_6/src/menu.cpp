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
#include "Powerboat.h"
#include "error.h"
#include <iostream>
#include <string>


void menu(Yacht** marina) {

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
                ++numVessel;
            break;

            case 2:
                std::cout << "Calling newPowerBoat\n";
                newPowerBoat(marina, numVessel, validation);
                ++numVessel;
            break;

            case 3:
                std::cout << "Calling newSailBoat\n";
            break;

            case 4:
                std::cout << "Calling display all\n";
                printAll(marina, numVessel);
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
                //marina->garbageCollector(marina);
                delete[] marina;
            break;

            default: //may not need this... but we may need it.
                std::cout << "Unrecognized entry.  Please " 
                << "enter a single digit from the menu above.\n";
            break;
        }//end switch

    }//end while

}//end menu

void newYacht(Yacht** marina, int& numVessel, bool validation) {
    // holds user input
    std::string input;

    //will hold the length
    float len;

    Yacht* sloop = new Yacht();

    if(numVessel >= MAX) {
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
        //marina[numVessel]->setName(input);
        sloop->setName(input);

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
        //marina[numVessel]->setLength(len);
        sloop->setLength(len);

        std::cout << "\nEnter year constructed: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            input = validateString(input, input.size());
        }
        //set Yacht year
        //marina[numVessel]->setYearBuilt(input);
        sloop->setYearBuilt(input);

        marina[numVessel] = sloop;

        //delete sloop;
    }//end else

}//end newYacht

void printAll(Yacht** marina, int& numVessel) {
    
    for(size_t i = 0; i < numVessel; ++i) {
        marina[i]->print();
    }
}//end printAll

void newPowerBoat(Yacht** marina, int& numVessel, bool validation) {
    // holds user input
    std::string input;

    //will hold the length
    float len;

    //holds number of engines
    int num;

    //will hold new Powerboat
    Powerboat* vessel = new Powerboat();

    if(numVessel >= MAX){
        std::cout << "The marina is full!\n";
    }

    else {
        std::cout << "Enter name of Powerboat: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            //validating name
            input = validateString(input, input.size());
        }
        //set Powerboat name
        vessel->setName(input);

         std::cout << "\nEnter length of Powerboat: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            len = checkValidFloat(input);
        }
        else {
            len = stof(input);
        }
        //set Powerboat length
        vessel->setLength(len);

        std::cout << "\nEnter year constructed: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            input = validateString(input, input.size());
        }
        //set Yacht year
        vessel->setYearBuilt(input);

        std::cout << "\nEnter amount of horse-power: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            len = checkValidFloat(input);
        }
        else {
            len = stof(input);
        }
        //set Powerboat horse-power
        vessel->setTotHorsePower(len);

        std::cout << "\nEnter number of engines: ";
        //get user input
        std::getline(std::cin, input);

        //execute high-level validation when true
        if(validation == true) {
            num = validateInteger(input);
        }
        else {
            num = stoi(input);
        }
        //set Powerboat number of engines
        vessel->setNumEngines(num);

        //add the deferenced info to a Yacht object
        Yacht* thing = vessel;

        //delete vessel;
        
    }//end else

}//end newPowerBoat