/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#include "options.h"
#include "record.h"
#include "error.h"
#include "menu.h"
#include "display.h"
#include <iostream>
#include <iomanip>

//*******************************************************
// name: addNewCustomer
// called by: menu
// passed: pointer to an array of structs (Record*), int&
// returns: nothing
// The addNewCustomer function checks if the maximum    *
//amount of customers has been reached; prompts the user*
//to enter data for a new Record, validating the user   *
//entries, creating the new record then adding it to the*
//array of Records and incrementing the amount of       *
//customers by 1                                        *
//*******************************************************

void addNewCustomer(access::Record* customerData, int& numCustomers) {
    //holds the input before validation
    std::string name, boatName, inputContract, inputPtd;

    //holds the values before input into Record
    float contractValue, ptdValue;

    //will hold the newCustomer when ready
    //to add to the array of Records
    access::Record newCustomer;

    //check if the number of customers has exceeded the maximum
    if( numCustomers >= access::SIZE) {
        std::cout << "The maximum number of customers has been reached.\n";
    }

    else {
        //get user input
        std::cout << "Enter new customer name (up to 15 characters): ";
        std::getline(std::cin, name);

        //validate user input
        name = validateName(name);

        //add to newCustomer record
        newCustomer.customer = name;
        
        //get user input
        std::cout << "\nEnter new boat name (up to 15 characters): ";
        std::getline(std::cin, boatName);

        //validate user input
        boatName = validateName(boatName);

        //add to newCustomer record
        newCustomer.boatName = boatName;
        
        //get user input
        std::cout << "\nEnter contract amount $: ";
        std::getline(std::cin, inputContract);

        //validate user input
        contractValue = validateNumber(inputContract);

        //add to newCustomer record
        newCustomer.contract = contractValue;
        
        //get user input
        std::cout << "\nEnter paid to date amount $: ";
        std::getline(std::cin, inputPtd);

        //validate user input
        ptdValue = validateNumber(inputPtd);

    
        //add to newCustomer record
        newCustomer.ptd = ptdValue;

        //add newCustomer to the array of Records
        customerData[numCustomers] = newCustomer;

        //increase number of customers by 1
        ++numCustomers;

    }//end else
}//end addNewCustomer

//*******************************************************
// name: editCustomer
// called by: menu
// passed: pointer to an array of structs Record*, int& *
// returns: nothing
// The editCustomer function ensures that the array is  *
//not empty, then prompts the user to enter the name of *
//an existing customer.  After validating the entry and *
//checking that it is in the system, user selects an    *
//option from a menu.  The input is validated and user  *
//is prompted for a new entry, which is then validated  *
//(if it is correct) alters the Record that is being    *
//accessed.  User is then returned to the Main Menu     *
//*******************************************************
void editCustomer(access::Record* customerData, int& numCustomers) {
    std::string name, entry;    //holds search name and user entries

    //holds index of user we wish to alter, and drives while loop
    int index = -1;

    //holds the choice of user of what field to edit             
    int field;

    //holds the numeric value of user edit of contract or ptd
    //before entry into accessed Record
    float value;

    //there are no customers in the array of Records
    //skip the while loop, return to Main Menu
    if(numCustomers <= 0) {
        std::cout << "No customers currently in system!\n";
        index = 0;
    }
    
    //will prompt user for a customer name until a valid, present name is entered
    while (index == -1) {
        std::cout << "Please enter the name of the customer you wish to edit: ";
        std::getline(std::cin, name);
       
        //ensure entry is valid
        name = validateName(name);
        
        //find customer in array of Records
        index = matchCustomer(customerData, name, numCustomers);

        //customer name was not found, bring user back to beginning of loop
        if(index == -1) {
            continue;
        }

        //prints the options menu, validates entry, then returns the choice
        field = editCustomerMenu(name);
        
        //handles the user choice from editCustomerMenu
        switch(field) {
            case 0:         //user indicated Exit
                index = 0;
            break;

            //prompting and validation of name change
            case 1:
                std::cout << "Current entry: " << customerData[index].customer << '\n';
                std::cout << "Enter new customer name: ";
                std::getline(std::cin, entry);
                entry = validateName(entry);
                customerData[index].customer = entry;
                std::cout <<"\nCustomer name updated!\n";
                index = 0;
            break;

            //prompting and validation of boat name change
            case 2:
                std::cout << "Current entry: " << customerData[index].boatName << '\n';
                std::cout << "Enter new boat name: ";
                std::getline(std::cin, entry);
                entry = validateName(entry);
                customerData[index].boatName = entry;
                std::cout <<"\nBoat name updated!\n";
                index = 0;
            break;

            //prompting and validation of contract value change
            case 3:
                std::cout << "Current entry: " << std::setprecision(2) << std::fixed  
                << "$ "<< customerData[index].contract << '\n';  
                std::cout << "Enter new contract amount $: ";
                std::getline(std::cin, entry);
                value = validateNumber(entry);
                customerData[index].contract = value;
                std::cout << "\nContract amount updated!\n";
                index = 0;
            break;

            //prompting and validation of paid to date value change
            case 4:
                std::cout << "Current entry: " << std::setprecision(2) << std::fixed
                << "$ " << customerData[index].ptd << '\n';  
                std::cout << "Enter new paid to date amount $: ";
                std::getline(std::cin, entry);
                value = validateNumber(entry);
                customerData[index].ptd = value;
                std::cout << "\nPaid to Date amount updated!\n";
                index = 0;
            break;

            //catch any errors
            default:
                std::cout << "Unknown error.\n";
            break;
        }//end switch
    }//end while
}//end editCustomer

//*******************************************************
// name: matchCustomer
// called by: editCustomer
// passed: const pointer to an array of structs Records *
// passed: std::string, int&
// returns: int
// The matchCustomer function compares the user provided*
// searchName to the names stored in the array of       *
// structs (Record).  If a match is found, the index of *
// the array is returned.  If no match is found, a      *
// message is printed, and -1 returned to prompt the    *
// user to re-enter the name                            *
//*******************************************************
int matchCustomer(const access::Record* customerData, std::string searchName, int& numCustomers){
    //loop through array of Records comparing entered name to names in array of Records
    for(int i = 0; i < numCustomers; ++i) {
        //when match is found return the index
        if(customerData[i].customer == searchName) {
            return i;
        }
    }  // if match is not found, print message return -1 so user can try again
    std::cout << "Customer not found.\n";
    return -1;
}

//*******************************************************
// name: searchContract
// called by: menu
// passed: const pointer to an array of structs, int&   *
// returns: nothing
// The searchContract function prompts the user for a   *
// amount to search for, validates that amount, then    *
// traverses the customerData array of structs, copying *
// the data when a match or greater is found, while     *
// tracking the number of Records that are copied.      *
// Next a new array of structs is instantiated with the *
// size of valid searched Records, and it is filled with*
// the records we originally copied.  The new array of  *
// structs is then printed in a consistent format.      *
//*******************************************************
void searchContract(const access::Record* customerData, int& numCustomers) {
    //variable declarations
    std::string num;                                 //holds the user input
    float searchVal;                                //holds the value to search
    access::Record temp[numCustomers];              //temporarily hold records
    int  newSize = 0;                               //will be new array size

    //get user input
    std::cout << "Enter contract amount to search $: ";
    std::getline(std::cin, num);

    //validate input
    searchVal = validateNumber(num);

    //do comparison, create new array of records that has the records we want, get the size we want
    for(int i = 0; i < numCustomers; ++i) {
        if(customerData[i].contract >= searchVal) {
            temp[i].customer = customerData[i].customer;
            temp[i].boatName = customerData[i].boatName;
            temp[i].contract = customerData[i].contract;
            temp[i].ptd = customerData[i].ptd;
            ++newSize;
        }
    }
    //will hold records that meet chriteria with no extra space
    access::Record cust[newSize];  

    //fill cust with Records that meet chriteria
    for(int i = 0; i < newSize; ++i) {
        cust[i].customer = temp[i].customer;
        cust[i].boatName = temp[i].boatName;
        cust[i].contract = temp[i].contract;
        cust[i].ptd = temp[i].ptd;
    }

    //call print with smaller array of Records, with its reduced size
    printContract(cust, newSize);

}//end searchContract

//*******************************************************
// name: contractTotal
// called by: menu
// passed: const pointer to an array of structs, int&   *
// returns: nothing
// The contractTotal function prints the company header,*
// next printing the array of Records, then totals the  *
// amount of each contract field in each Record in the  *
// array.  Next that total is printed in a specified    *
// format, followed by a border.                        *
//*******************************************************
void contractTotal(const access::Record* customerData, int& numRecords) {
    //holds contract total
    float total = 0;            

    //print all Records in array
    printContract(customerData, numRecords);

    //total the contracts
    for(auto i = 0; i < numRecords; ++i) {
        total = total + customerData[i].contract;
    }

    //print resulting total in specified format
    std::cout << std::setprecision(2) << std::fixed << "Contract Total: $" << std::setw(10) << total << '\n';

    //prints formatted border
    border();
    
}//end contractTotal

