/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/


#ifndef YACHT_H
#define YACHT_H
#include <string>
#include <iostream>

//max amount of yachts in array
const int MAX = 10;

class Yacht {

    private:
        std::string name;
        float length;
        std::string yearBuilt;

    public:
        //member function declarations for Yacht.cpp

        //default constructor
        Yacht();

        //default destructor
        ~Yacht();

        //move constructor
        Yacht(Yacht &&other) noexcept;

        //move assignment operator 
        Yacht& operator=(Yacht &&rhs) noexcept;

        //copy constructor
        Yacht(const Yacht& other);

        //copy assignment operator
        Yacht& operator=(const Yacht &rhs);

        //getters
        std::string getName() const;
        float getLength() const;
        std::string getYearBuilt() const;

        //setters
        void setName(const std::string);
        void setLength(const float);
        void setYearBuilt(const std::string);

        //member print function
        void print() const;



};

//overloaded << operator
std::ostream& operator<<(std::ostream&, const Yacht&);


#endif