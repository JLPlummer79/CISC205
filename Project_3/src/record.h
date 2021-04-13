/*
 *
 * Jesse Plummer
 *
 * Chapter 11, Programming Challenge #3
 *
 * March 19th, 2021
 * 
*/

#ifndef RECORD_H
#define RECORD_H
#include <string>

//declaring namespace to help limit access potential
namespace access {

    //maximum number of customers
    inline constexpr int SIZE = 10;

    //definition for data structure holding customer info, used by array in main.cpp     
    struct Record {
        std::string customer;

        std::string boatName;

        float contract;

        float ptd;
    };

}//end namespace access

#endif