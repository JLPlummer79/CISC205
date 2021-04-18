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
// The menu function prints the base menu, then prompts *
// the user for input. Once that is validated, the input*
// calls the appropirate function and performs an action*
//*******************************************************
void menu(SeaPollution* seas) {
    //holds user input 
    std::string input;
    //variable to control flow
    int choice = 0;
    //will control on/off for high level validation
    bool validation = true;
    //tracks how many seas are in the array
    int numSeas = 0;

    while (choice != 7) {
        //main menu display
        std::cout << "\n<---------------Main Menu---------------->\n";
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
            //call arithmeticSeas
            arithmeticSeas(seas, numSeas, validation);
            break;

            case 5:
            //call printAllSeas
            printAllSeas(seas, numSeas);
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
        std::cout << "\nEnter sea name: ";
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
        while(bow.getSurfaceArea() < number) {
            std::cout << "Pollution area cannot "
            << "exceed surface area of sea!"
            << " Please re-enter pollution area"
            << " number: ";
            //get user input
            std::getline(std::cin, input);

            if(validation == true) {
                //high level validation
                number = checkValidFloat(input);
            }
            else{
                number = stof(input);
            } 
        }//end while

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
        while(number > 100) {
            std::cout << "Percent salinity "
            << "cannot exceed 100%! Please "
            << "re-enter salinity number: ";
            //get user input
            std::getline(std::cin,input);
            if(validation == true) {
                //high level validation
                number = checkValidFloat(input);
            }
            else{
                number = stof(input);
            } 
        }//end while

        //set salinityLevel in new object
        bow.setSalinityLevel(number);

    }
    //add new object to array
    seas[numSeas] = bow;
}//end enterSea function

//*******************************************************
// name: searchSeas
// called by: searchSeasPrint, compareSeas, arithmeticSeas
// passed: a pointer to an array of objects, int&, 
// passed: std::string
// returns: SeaPollution object
// The searchSeas function iterates the arg seas and    *
// compares it to the arg name.  The returned value is  *
// 0-5 if it is valid, 7 if it is not valid             *
//*******************************************************
int searchSeas(SeaPollution* seas, int& numSeas, std::string name) {
    //holds found object
    SeaPollution blank;

    int index = 7;

    for(size_t i = 0; i < numSeas; ++i) {
            
        if(seas[i].getName() == name) {
            index = i;
        }
    }
    // return valid or invalid index
    return index;    
    
}//end searchSeas

//*******************************************************
// name: searchSeasPrint
// called by: menu
// passed: pointer to a array of SeaPollution objects
// passed: int&, bool
// returns: nothing
// The searchSeasPrint function prompts the user for    *
// input, verifies it (or not), passes it to the search *
// -Seas function, and prints the object if found, an   *
// error message if not found                           *
//*******************************************************
void searchSeasPrint(SeaPollution* seas, int& numSeas, bool validation) {
    //will hold result from searchSeas
    int seaIndex = 0;

    //hold user input
    std::string input;

    //ensure array is populated
    if(numSeas <= 0) {
        std::cout << "No seas present in data structure!\n";
    }

    else {
        std::cout << "\nEnter sea name: ";
        //get user input
        std::getline(std::cin, input);

        //high level error checking
         if(validation == true) {
            input = validateString(input);
        }
        //1-5 if the sea was found.  7 otherwise
        seaIndex = searchSeas(seas,numSeas, input);

        if(seaIndex == 7) {
            std::cout << input << " sea not found.\n";
        }
        else {
            seas[seaIndex].print();
        }
    }
}//end searchSeasPrint

//*******************************************************
// name: compareSeas
// called by: menu
// passed: pointer to an array of objects, int&, bool
// returns: nothing
// The compareSeas function prompts the user for 2 seas *
// vaidates the input, then searches for the seas. If   *
// found, prompts the user to enter an operator.  After *
// the input is validated, the overloaded operator >, <,*
// or == is called to make a comparison.  Then the      *
// result is printed in a readable format using the     *
// print function and appropriate phrases (greater than)*
//*******************************************************
void compareSeas(SeaPollution* seas, int& numSeas, bool validation) {
 
    //lhs & rhs will be assigned the SeaPollution objects from seas
    //being compared
    SeaPollution lhs, rhs;

    //holds return value of searchSeas
    int seaIndex = 0;

    //holds user input
    std::string input;

    //will control flow of while
    int flag = 0;

    //will track which object needs assignment
    int count = 1;

    //will hold the operator entry
    char op = '$';

    //ensure array is populated
    if(numSeas <= 0) {
        std::cout << "No members in array!\n";
    }
    else {
        //1st while gets the sea names
        while(flag == 0) {
            std::cout << "\nEnter name of sea: ";

            //get user input
            std::getline(std::cin, input);

            //validate string 
            if(validation == true) {
                input = validateString(input);
            }

            //search for user input
            seaIndex = searchSeas(seas, numSeas, input);

            //sea was not found
            if(seaIndex == 7) {
                std::cout << input <<" sea not found."
                << " Please re-enter the sea name.\n";
                continue;
            }
            else {
                //assign lhs the left side arg for comparison
                if(count == 1) {
                    lhs = seas[seaIndex];
                    ++count;
                }
                //assign rhs the right side arg for comparison
                else if(count == 2) {
                    rhs = seas[seaIndex];
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
                op = checkSingleChar(input);

            //select and perform operation based on user input
            switch(op) {

                case '<':
                    divider();      //print divider for data presentation
                     lhs.print();   //print left side object
                    if(lhs < rhs) {     //print appropriate phrase
                        std::cout <<  
                        " is less than ";
                    }
                    else {
                        std::cout << 
                        " is not less than ";
                    }  
                    rhs.print();     //print right side object
                    divider();      //print divider for data presentation
                    flag = 0;       //break while
                break;

                case '>':
                    divider();      //print divider for data presentation
                    lhs.print();    //print left side object
                    if(lhs > rhs){      //print appropriate phrase
                        std::cout << 
                        " is greater than ";
                    }
                    else {
                        std::cout << 
                        " is not greater than ";
                    }  
                    rhs.print();    //print right side object
                    divider();      //print divider for data presentation
                    flag = 0;       //break while
                break;

                case '=':
                    divider();      //print divider for data presentation
                    lhs.print();    //print left side object
                    if(lhs == rhs){     //print appropriate phrase
                        std::cout <<
                        " is equal to ";
                    }
                    else{
                        std::cout <<
                        " is not equal to ";
                    } 
                    rhs.print();    //print right side object
                    divider();      //print divider for data presentation
                    flag = 0;       //break while
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
// called by: menu
// passed: pointer to an array of objects, int&, bool
// returns: nothing
// The arithmeticSeas function prompts the user to enter*
// the name of a sea, searchs for it and if found       *
// assigns the data to a new object, if nor prints an   *
// error message.  The step repeast, then prompts the   *
// user for a appropriate operator, checks it, then     *
// carries out the operation between the 2 objects.     *
// If the result is valid, it prints.  If the result is *
// zero or less an error message prints and the program *
// terminates.                                          *
//*******************************************************
void arithmeticSeas(SeaPollution* seas, int& numSeas, bool validation) {
    // represent the objects to have operations performed on
    SeaPollution shell, lhs, rhs;

    //holds the return value of searchSeas
    int seaIndex = 0;

    //holds user input
    std::string input;

    //control flow of while loops
    int flag = 0;
     
    //track what object needs assignment
    int count = 1;

    //holds operator entry
    char op = '$';

    //ensure array is populated
    if(numSeas <= 0) {
        std::cout << "No members in array!\n";
    }
    else {
        //1st while gets the sea names
        while(flag == 0) {
            std::cout << "\nEnter name of sea: ";

            //get user input
            std::getline(std::cin, input);

            //validate user input
            if(validation == true) {
                input = validateString(input);
            }

            //search for user input
            seaIndex = searchSeas(seas, numSeas, input);

            //sea was not found
            if(seaIndex == 7) {
                std::cout << input <<" sea not found."
                << " Please re-enter the sea name.\n";
                continue;
            }
            else {
                //assign lhs the left side arg for operation
                if(count == 1) {
                    lhs = seas[seaIndex];
                    ++count;
                }
                //assign rhs the right side arg for operation
                else if(count == 2) {
                    rhs = seas[seaIndex];
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
            op = checkSingleChar(input);
           
           //select & perform operation
            switch(op) {

                case '+':
                   shell = lhs + rhs;   //perform the overloaded operation
                   divider();           //print a formatted divider
                   shell.print();       //print resulting object with unique name
                   divider();           //print a formatted divider
                   flag = 0;            //ensure while terminates
                break;

                case '-':
                    shell = lhs - rhs;  //perform the overloaded operation
                    divider();          //print formatted divider
                    shell.print();      //print resulting object with unique name
                    divider();          //print formatted divider
                    flag = 0;           //break while
                break;

                //error message
                default:
                    std::cout << "Invalid character choice "
                    << "Please enter + or -.\n";
                break;
            }//end switch

        }//end 2nd while 

    }//end else

}//end arithmeticSeas

//*******************************************************
// name: printAllSeas
// called by: menu
// passed: pointer to an array of objects, int&
// returns: nothing
// The printAllSeas function prints all the objects of  *
// argument seas, using the numSeas argument as a limit *
//*******************************************************
void printAllSeas(SeaPollution* seas, int& numSeas) {
    //print divider for display purposes
    divider();              
    //loop through array, printing contents
    for(size_t i = 0; i < numSeas; ++i) {
        seas[i].print();
    }
    //print divider for display purposes
    divider();
}

//*******************************************************
// name: divider
// called by: printAllSeas,
// passed: nothing
// returns: nothing
// The divider function prints a border for data display*
// purposes                                             *
//*******************************************************
void divider() {
    std::cout << "\n<---------------------------------------->\n";
}




//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************