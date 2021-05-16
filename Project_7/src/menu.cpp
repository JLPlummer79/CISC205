/*
 *
 * Jesse Plummer
 *
 * Chapter 16, Programming Challenge #7 Sea Pollution w/ try/catch
 *
 * May 17th, 2021
 * 
*/

#include "menu.h"
#include "SeaPollution.h"
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
    //tracks how many seas are in the array
    int numSeas = 0;
    //to make a call
    SeaPollution shell;

    while (choice != -1) {
        //main menu display
        std::cout << "\n<---------------Main Menu---------------->\n";
        std::cout << "1. Enter data for one sea.\n";
        std::cout << "2. Search for sea in system.\n";
        std::cout << "3. Compare two seas.\n";
        std::cout << "4. Perform arithmetic on two seas.\n";
        std::cout << "5. Display all seas.\n";
        std::cout << "6. Exit program.\n";
        std::cout << "<---------------------------------------->\n";
        std::cout << "Please enter selection: ";
        //get user input
        std::getline(std::cin, input);
        //validate user input & convert to int
        try{
            choice = shell.convertInt(input);
        }
        catch(SeaPollution::EmptyValue) {
            std::cout << "Error! Entry "
            << "is empty, and invalid!\n";
        }
        catch(SeaPollution::SmallStr e){
            std::cout << "Error: " <<
            e.getSValue() << " is invalid."
            << "\n";
        }
        catch(SeaPollution::ImpossibleStr e) {
            std::cout << "Error: " << e.getIStr()
            << " is invalid!\n";
        }
        
        switch(choice) {
            case 1:
            //call enterSea function
            enterSea(seas, numSeas);
            //track number of seas
            ++numSeas;
            break;

            case 2:
            //call searchSeas
            searchSeasPrint(seas, numSeas);
            break;

            case 3:
            //call compareSeas
            compareSeas(seas, numSeas);
            break;

            case 4:
            //call arithmeticSeas
            arithmeticSeas(seas, numSeas);
            break;

            case 5:
            //call printAllSeas
            printAllSeas(seas, numSeas);
            break;

            case 6:
               std::cout << "Exiting program.  Have a nice day!\n";
               choice = -1;
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
// a new SeaPollution object.  Try catch pattern with   *
// exception classes are used to handle entry errors. At*
// the end of the function, the new object is added to  *
// the array of SeaPollution objects                    *
//*******************************************************
void enterSea(SeaPollution* seas, int& numSeas) {
    //new object to add to the array
    SeaPollution bow;
    //hold user input
    std::string input;
    //holds the converted numerical user input
    float num;

    //will control loop flows when an exception is thrown
    bool tryAgain = true;

    //check if array is full, if we are finished, may need to only be greater than
    if(numSeas >= MAX){
        std::cout << "Array is full, cannot add another sea!\n";
    }

    else {
        while(tryAgain) {
            std::cout << "\nEnter sea name: ";
            //get user input
            std::getline(std::cin, input);

            //try to set new name
            try {
                bow.setName(input);
                //note, this will not excecute if an exception is thrown
                tryAgain = false;
            }
            catch(SeaPollution::BigName e) {
                std::cout << "Error: " << 
                e.getbName() << " is an invalid "
                << " length.\n";
            }
            catch(SeaPollution::EmptyValue ) {
                std::cout << "Error sea name "
                << "cannot be empty!\n";
            }
        }//end while
        tryAgain = true;

        while(tryAgain) {
            std::cout << "\nEnter surface area of sea: ";
            //get user input
            std::getline(std::cin, input);
            //try to convert input to a float, 
            //may throw exception 
            try { 
                num = bow.convertFloat(input);
            }
            catch(SeaPollution::EmptyValue ) {
                std::cout << "Error surface "
                << "area cannot be empty!\n";
                continue;
            }
            catch(SeaPollution::ImpossibleStr e) {
                std::cout << "Error: " << e.getIStr()
                << "\n";
                continue;
            }
            //try to setSurfaceArea, may throw
            try{
                bow.setSurfaceArea(num);
                tryAgain = false;
            }
            catch(SeaPollution::NegativeValue e) {
                std::cout << "Error: " << 
                e.getValue() << " is an invalid "
                << "size.\n";
                continue;
            }
        }//end while
        tryAgain = true;
        while(tryAgain) {

            std::cout << "\nEnter pollution area of sea: ";
            //get user input
            std::getline(std::cin, input);

            //try to convert float, may throw
            try {
                num = bow.convertFloat(input);
            }
            catch(SeaPollution::ImpossibleStr e) {
                std::cout << "Error:  " << e.getIStr()
                << "\n";
                continue;
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Pollution"
                << " area value cannot be empty!"
                << "\n";
                continue;
            }
            try {
                bow.setPollutionArea(num);
                tryAgain = false;
            }
            catch(SeaPollution::NegativeValue e) {
                std::cout << "Error: " << 
                e.getValue() << " is an invalid "
                << "size.\n";
                continue;
            }
            catch(SeaPollution::ImpossibleValue e) {
                std::cout << "Error: " << e.getIValue()
                << " is an invalid size.\n";
                continue;
            }
        }//end while
        tryAgain = true;
        
        while(tryAgain) {
            std::cout << "\nEnter salinity level of sea: ";
            //get user input
            std::getline(std::cin, input);

            //try to convert input to a float, may throw
            try {
                num = bow.convertFloat(input);
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Salinity level"
                << " is invalid!\n";
                continue;
            }
            catch(SeaPollution::ImpossibleStr e) {
                std::cout << "Error: " << e.getIStr()
                << "\n";
                continue;
            }
            //try to set the Salinity value, may throw
            try {
                bow.setSalinityLevel(num);
                tryAgain = false;
            }
            catch(SeaPollution::NegativeValue e) {
                std::cout << "Error: " << e.getValue()
                << " is an invalid size.\n";
                continue;
            }
            catch(SeaPollution::ImpossibleValue e) {
                std::cout << "Error: " << e.getIValue()
                << " is an invalid size.\n";
                continue;
            }
        }//end while

    }//end else

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
// 0-5 if it is valid, -1 if it is not valid             *
//*******************************************************
int searchSeas(SeaPollution* seas, int& numSeas, std::string name) {
    //holds found object
    //SeaPollution blank;

    int index = -1;

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
void searchSeasPrint(SeaPollution* seas, int& numSeas) {
    //will hold result from searchSeas
    int seaIndex = 0;

    //hold user input
    std::string input;

    //object for comparison
    SeaPollution blank;

    bool tryAgain = true;

    //ensure array is populated
    if(numSeas <= 0) {
        std::cout << "No seas present in data structure!\n";
    }

    else {
        std::cout << "\nEnter sea name: ";
        //get user input
        std::getline(std::cin, input);

        while(tryAgain) {
            //try to set name, may throw
            try{
                blank.setName(input);
                tryAgain = false;
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Name "
                << "cannot be empty!\n";
                continue;
            }
            catch(SeaPollution::BigName e) {
                std::cout << "Error: " << 
                e.getbName() << " must be "
                << "less than 20 characters.\n";
                continue;
            }
        }//end while
        //1-5 if the sea was found.  -1 otherwise
        seaIndex = searchSeas(seas,numSeas, blank.getName());

        //sea found or sea not found
        if(seaIndex == -1) {
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
void compareSeas(SeaPollution* seas, int& numSeas) {
 
    //lhs & rhs will be assigned the SeaPollution objects from seas
    //being compared
    SeaPollution lhs, rhs, blank;

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

            //try to set name, may throw
            try {
                blank.setName(input);
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Sea name "
                << "cannot be empty!\n";
                continue;
            }
            catch(SeaPollution::BigName e) {
                std::cout << "Error: " << 
                e.getbName() << " must be less "
                << "than 20 characters.\n";
                continue;
            }

            //search for user input
            seaIndex = searchSeas(seas, numSeas, blank.getName());

            //sea was not found
            if(seaIndex == -1) {
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

            //try to validate the operator, may throw
            try{
               op = blank.convertChar(input);
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Cannot "
                << "be empty! "
                << "a character must be selected!\n";
                continue;
            }
            catch(SeaPollution::SmallStr e) {
                std::cout << "Error: " << e.getSValue()
                << " is invalid.\n";
                continue;
            }

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
// error message.  The step repeats, then prompts the   *
// user for a appropriate operator, checks it, then     *
// carries out the operation between the 2 objects.     *
// If the result is valid, it prints.  If the result is *
// zero or less an exception is thrown                  *
//*******************************************************
void arithmeticSeas(SeaPollution* seas, int& numSeas) {
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

            //try to set name, may throw
            try {
                shell.setName(input);
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Sea name "
                << "cannot be empty!\n";
                continue;
            }
            catch(SeaPollution::BigName e) {
                std::cout << "Error: " << 
                e.getbName() << " must be less "
                << "than 20 characters.\n";
                continue;
            }

            //search for user input
            seaIndex = searchSeas(seas, numSeas, shell.getName());

            //sea was not found
            if(seaIndex == -1) {
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

            //try to convert the input to a single char, may throw
            try{
               op = shell.convertChar(input);
            }
            catch(SeaPollution::EmptyValue) {
                std::cout << "Error! Cannot "
                << "choose nothing, " 
                << "a character must be selected!\n";
                continue;
            }
            catch(SeaPollution::SmallStr e) {
                std::cout << "Error: " << e.getSValue()
                << " is invalid.\n";
                continue;
            }
           
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
                    //try to perform the subtraction, may throw
                    try {
                        shell = lhs - rhs;  //perform the overloaded operation
                    }
                    catch(SeaPollution::NegativeValue e){
                        std::cout << "Error: " << e.getValue()
                        << " is negative & invalid.\n";
                        continue;
                    }

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