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
// The addCustomer function prompts the user to enter   *
// data and checks the entries using try/catch blocks.  *
// While loops control the flow of the program, when the*
// user entry is invalid, the loop continues. When the  *
// entry is valid, the loop is exited, and the user     *
// continues the data entry process. When that process  *
// is finished, the newly created object is added to the*
// vector.                                              *
//*******************************************************
void addCustomer(std::vector<Painting>& boats) {
    std::string input;
    Painting boat;
    bool tryAgain = true;
    float value;

    while(tryAgain) {

        //prompt user and get the input
        std::cout << "Enter customer name, up to 15 characters: ";
        std::getline(std::cin, input);

        //error checking try/catch blocks if try executes, name is set, while exited
        //if setName throws, an error message is printed, while continues
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
    }//end while

    boats.push_back(boat);

}//end addCustomer

//*******************************************************
// name: printAll
// called by: menu
// passed: std::vector<Painting>
// returns: nothing
// The printAll function prints all the contents of the *
// vector passed to it as well as totaling the contract *
// values and printing them at the end.                 *
//*******************************************************
void printAll(std::vector<Painting> boats) {
    //holds total
    float total;
    //holds running total for overloaded adding
    Painting shell;

    if(boats.size() == 0) {
        std::cout << "No contracts in inventory!\n";
    }
    else {
        for(int i = 0; i < boats.size(); ++i) {
            //prints each entry
            boats[i].print();
            
            //overloaded addition of Painting objects
            total = shell + boats[i];

            //makes sure that shell has the running total
            shell.setContract(total);     
        }

        //print contracts total
        std::cout << "\nTotal: " << total << '\n';
    }
}//end printAll

//*******************************************************
// name: editCustomerMenu
// called by: editCustomer
// passed: nothing
// returns: int
// The editCustomerMenu function prints a menu that     *
// prompts the user to choose which field to enter. The *
// entry is error checked, then filtered with a switch. *
// If the entry is valid, it is returned, or the menu is*
// exited, or the user is prompted to enter a relavant  *
// choice. If the entry is invalid, try/catch handles   *
// error, prints a message, and the user is returned to *
// the beginning of the menu.                           *
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
        
        //get user inpup
        std::getline(std::cin, input);

        //making sure entry is valid
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
        //returns a valid entry, or prompts user to try again.
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
// called by: editCustomer
// passed: std::vector<Painting>&, const std::string
// returns: int
// The matchCustomer function takes 2 args, a vector and*
// a const std::string. The vector is iterated through, *
// comparing the name from each boat object to the name *
// arg. It is trying to find the index that matches the *
// user entry of which customer to edit data for. If a  *
// match is found, the variable index is set to j, then *
// returned. If no match is found, index is returned as *
// -1, which is handled in the calling function.        *
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

//*******************************************************
// name: editCustomer
// called by: menu
// passed: std::vector<Painting>&
// returns: nothing
// The editCustomer function prompts the user to enter  *
// the customer name they want to edit, searches for the*
// name; prints and error message if not found, starting*
// while loop again. If found, a function is called that*
// prints a menu prompting the user to enter a choice of*
// what to edit. That choice is again error checked and *
// returned. That is filtered through a switch, prompts *
// the user to enter the new data. That is error checked*
// then the object (in the vector) is updated.          *
//*******************************************************
void editCustomer(std::vector<Painting>& boats) {
    std::string customer,entry;
    int index = -1;
    int flag;
    int field;
    float value;
    Painting boat;

    if(boats.size() == 0) {
        flag = -1;
        std::cout << "No contracts in inventory!\n";
    }
    else {
        flag = 1;
    }
    
    while(flag != -1) {
        //prompt user for entry and get entry
        std::cout << "\nEnter customer name you wish to edit: ";
        std::getline(std::cin, customer);
        
        //find & match customer index
        index = matchCustomer(boats, customer);
        if(index == -1) {
            std::cout << "\nCustomer not found!\n";
            continue;
        }
        //get the user choice for which field to enter
        field = editCustomerMenu();

        //filter user choice, error check entry
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
// name: findLargest
// called by: menu
// passed: std::vector<Painting>&
// returns: nothing
// The findLargest function takes the arg and 1st sets a*
// Painting object (largest) to the first element. 2nd  *
// the vector is iterated over comparing each element to*
// largest. When the overloaded operator > returns true *
// largest is assigned the value of boats[j]. Once the  *
// loop finishes, the member function print is called,  *
// printing the largest Painting object in the arg.     *
//*******************************************************
void findLargest(std::vector<Painting>& boats) {
    if(boats.size() == 0) {
        std::cout << "No boats in inventory!\n";
    }
    else {
        Painting largest = boats[0];

        for(int j = 0; j < boats.size(); ++j) {
            if(boats[j] > largest) {
                largest = boats[j];
            }
        }
        largest.print();
    }

}

//*******************************************************
// name: 
// called by:
// passed: 
// returns: 
// The 'name' function 'what function does'             *
//*******************************************************