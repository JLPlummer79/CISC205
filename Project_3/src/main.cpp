/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#include <iostream>
#include <string>
#include "record.h"
#include "menu.h"




int main() {
    //declare an array of Records SIZE in length, holds each record
    access::Record customerData[access::SIZE];

    menu(customerData); 
    
    return 0;
}