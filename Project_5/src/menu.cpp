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
        std::cout << "4. Perform arithmetic on two seas.\n";
        std::cout << "5. Display all seas.\n";
        std::cout << "6. Toggle on/off high level validation.\n";
        std::cout << "7. Exit program.\n";
        std::cout << "<---------------------------------------->\n";
        std::cout << "Please enter selection: ";
        //get user input
        std::getline(std::cin, input);
        //validate user input
        choice = checkSingleInt(input);

        switch(choice) {
            case 1:
            //call enterSea function
            enterSea(seas, numSeas, validation);
            //track number of seas
            ++numSeas;
            break;

            case 2:
            //call searchSeas
            searchSeasPrint(seas, numSeas, validation);
            break;

            case 3:
            //call compareSeas
            compareSeas(seas, numSeas, validation);
            break;

            case 4:
            //call combineSeas(SeaPollution*, int, bool) array, numSeas, validation on/off
            std::cout << "Calling arithmeticSeas\n";
            arithmeticSeas(seas, numSeas, validation);
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
// name: enterSea
// called by: menu
// passed: pointer to an array of objects, int&, bool
// returns: nothing
// The enterSea function prompts the user for values for*
// a new SeaPollution object.  High level validation can*
// be turned on/off by user before function call.  At   *
// the end of the function, the new object is added to  *
// the array of SeaPollution objects                    *
//*******************************************************
void enterSea(SeaPollution* seas, int& numSeas, bool validation) {
    //new object to add to the array
    SeaPollution bow;
    //hold user input
    std::string input;
    float number;
    //check if array is full, if we are finished, may need to only be greater than
    if(numSeas >= MAX){
        std::cout << "Array is full, cannot add another sea!\n";
    }

    else {
        std::cout << "Enter sea name: ";
        //get user input
        std::getline(std::cin, input);

        //will execute if highlevel validation is turned on
        if(validation == true) {
            input = validateString(input);
        }
        //set seaName in new object
        bow.setName(input);

        std::cout << "\nEnter surface area of sea: ";
        //get user input
        std::getline(std::cin, input);
        if(validation == true) {
            //high level validation
            number = checkValidFloat(input);
        }
        //low level validation only
        else{
            number = stof(input);
        }
        //set surfaceArea in new object
        bow.setSurfaceArea(number);

        std::cout << "\nEnter pollution area of sea: ";
        //get user input
        std::getline(std::cin, input);
        if(validation == true) {
            //high level validation
            number = checkValidFloat(input);
        }
        else{
            number = stof(input);
        }
        //set pollutionArea in new object
        bow.setPollutionArea(number);

        std::cout << "\nEnter salinity level of sea: ";
        //get user input
        std::getline(std::cin, input);

        if(validation == true) {
            //high level validation
            number = checkValidFloat(input);
        }
        //low level validation only
        else {
            number = stof(input);
        }
        //set salinityLevel in new object
        bow.setSalinityLevel(number);

    }
    //add new object to array
    seas[numSeas] = bow;
}//end enterSea function

//*******************************************************
// name: searchSeas
// called by:
// passed: a pointer to an array of objects, int&, 
// passed: std::string
// returns: SeaPollution object
// The 'name' function 'what function does'             *
//*******************************************************
SeaPollution searchSeas(SeaPollution* seas, int& numSeas, std::string name) {
    SeaPollution blank;

    int index = 7;

    for(size_t i = 0; i < numSeas; ++i) {
            
        if(seas[i].getName() == name) {
            index = i;
        }
    }
    if(index != 7) {
        return seas[index];
    }
    
    std::cout << name << " sea not found.\n";

    return blank;
    
}//end searchSeas

//*******************************************************
// name: searchSeasPrint
// called by: menu
// passed: pointer to a array of SeaPollution objects
// passed: int&, bool
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void searchSeasPrint(SeaPollution* seas, int& numSeas, bool validation) {
    //will hold the return value from searchSeas
    SeaPollution shell;

    //hold user input
    std::string input;

    if(numSeas <= 0) {
        std::cout << "No seas present in data structure!\n";
    }

    else {
        std::cout << "Enter sea name: ";
        //get user input
        std::getline(std::cin, input);

        //high level error checking, don't really need here but nice to be consistent
         if(validation == true) {
            input = validateString(input);
        }
        //assign the returned object to the 'shell'
        shell = searchSeas(seas,numSeas, input);

        if(shell.getName() == "Zzyzx") {
            std::cout << input << " sea not found.\n";
        }
        else {
            shell.print();
        }
    }
}//end searchSeasPrint

//*******************************************************
// name: compareSeas
// called by:
// passed: pointer to an array of objects, int&, bool
// returns: nothing
// The 'name' function 'what function does'             *
//*******************************************************
void compareSeas(SeaPollution* seas, int& numSeas, bool validation) {

    //shell will hold the returned object for error checking, 
    //lhs & rhs will have the comparison performed on them
    SeaPollution shell, lhs, rhs;

    //holds user input
    std::string input;

    //will control flow of while
    int flag = 0;

    //will track which object needs assignment
    int count = 1;

    //will hold the operator entry
    char op = '$';

    if(numSeas <= 0) {
        std::cout << "No members in array!\n";
    }
    else {
        //1st while gets the sea names
        while(flag == 0) {
            std::cout << "Enter name of sea: ";

            //get user input
            std::getline(std::cin, input);

            //validate string 
            if(validation == true) {
                input = validateString(input);
            }

            //search for user input
            shell = searchSeas(seas, numSeas, input);

            if(shell.getName() == "Zzyzx") {
                std::cout << input <<" sea not found."
                << " Please re-enter the sea name.\n";
                continue;
            }
            else {
                if(count == 1) {
                    lhs = shell;
                    ++count;
                }
                else if(count == 2) {
                    rhs = shell;
                    flag = 1;
                    count = 0;
                }
            }
        }//end 1st while

        //2nd while gets the operator
        while(flag == 1) {
            std::cout << "\nEnter operator choice: <, >, = : ";
            
            //get user input
            std::getline(std::cin, input);

            //validate user input
            if(validation == true) {
                op = checkSingleChar(input);
            }

            switch(op) {

                case '<':
                     lhs.print();
                    if(lhs < rhs) {
                        std::cout <<  
                        " is less than ";
                    }
                    else {
                        std::cout << 
                        " is not less than ";
                    }  
                    rhs.print();
                    flag = 0;
                break;

                case '>':
                    lhs.print();
                    if(lhs > rhs){
                        std::cout << 
                        " is greater than ";
                    }
                    else {
                        std::cout << 
                        " is not greater than ";
                    }  
                    rhs.print();
                    flag = 0;
                break;

                case '=':
                    lhs.print();
                    if(lhs == rhs){
                        std::cout <<
                        " is equal to ";
                    }
                    else{
                        std::cout <<
                        " is not equal to ";
                    } 
                    rhs.print();
                    flag = 0;
                break;

                //error message 
                default:
                    std::cout << "Invalid character choice. "
                    << "Please enter a character from "
                    << "selection of operators.\n";
                break; 

            }//end switch

        }//end 2nd while

    }//end else

}//end compareSeas

//*******************************************************
// name: arithmeticSeas
// called by:
// passed: pointer to an array of objects, int&, bool
// returns: nothing
// The arithmeticSeas function prompts the user to enter*
// the name of a sea, *
//*******************************************************
void arithmeticSeas(SeaPollution* seas, int& numSeas, bool validation) {
    // represent the objects to have operations performed on
    SeaPollution shell, lhs, rhs;

    //holds user input
    std::string input;

    //control flow of while loops
    int flag = 0;
     
    //track what object needs assignment
    int count = 1;

    //holds operator entry
    char op = '$';

    if(numSeas <= 0) {
        std::cout << "No members in array!\n";
    }
    else {
        //1st while gets the sea names
        while(flag == 0) {
            std::cout << "Enter name of sea: ";

            //get user input
            std::getline(std::cin, input);

            //validate user input
            if(validation == true) {
                input = validateString(input);
            }

            //search for user input
            shell = searchSeas(seas, numSeas, input);

            if(shell.getName() == "Zzyzx") {
                std::cout << input <<" sea not found."
                << " Please re-enter the sea name.\n";
                continue;
            }
            else {
                if(count == 1) {
                    lhs = shell;
                    ++count;
                }
                else if(count == 2) {
                    rhs = shell;
                    flag = 1;
                    count = 0;
                }
            }
        }//end 1st while

        //2nd while gets the operator
        while(flag == 1) {
            std::cout << "\nEnter operator choice: +, - : ";

            //get user input
            std::getline(std::cin, input);

            //validate user input
            if(validation == true) {
                op = checkSingleChar(input);
            }

            switch(op) {

                case '+':
                   shell = lhs + rhs;
                   shell.print();
                   flag = 0;
                break;

                case '-':
                    shell = lhs - rhs;
                    shell.print();
                    flag = 0;
                break;

                default:
                    std::cout << "Invalid character choice "
                    << "Please enter + or -.\n";
                break;
            }//end switch

        }//end 2nd while 

    }//end else

}//end arithmeticSeas



//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************