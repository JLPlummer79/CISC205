/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#ifndef SAILBOAT_H
#define SAILBOAT_H
#include "Yacht.h"
#include <string>

class Sailboat: public Yacht {
    private:
        float sailArea;

    public:
        //constructor
        Sailboat(); 

        //destructor
        ~Sailboat();

        //move constructor
        Sailboat(Sailboat &&other) noexcept;

        //move assignment operator 
        Sailboat& operator=(Sailboat &&rhs) noexcept;

        //copy constructor
        Sailboat(const Sailboat& other);

        //copy assignment operator
        Sailboat& operator=(const Sailboat &rhs);

        //getters
        float getSailArea() const;
        std::string getName() const;
        float getLength() const;
        std::string getYearBuilt() const;

        //setter
        void setSailArea(const float);
        void setName(const std::string);
        void setLength(const float);
        void setYearBuilt(const std::string);

        //member garbageCollector
        void garbageCollector(const Sailboat*);

        //member print
        void print() const;

};

//overloaded << operator
std::ostream& operator<<(std::ostream&, const Sailboat&);


#endif