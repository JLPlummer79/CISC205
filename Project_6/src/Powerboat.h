/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/

#ifndef POWERBOAT_H
#define POWERB0AT_H
#include "Yacht.h"
#include <string>

class Powerboat : public Yacht {
    private:
        int numEngines;
        float totHorsePower;

    public:
        //constructor
        Powerboat();

        //destructor
        ~Powerboat() = default;

        //move constructor
        Powerboat(Powerboat &&other) noexcept;

        //move assignment operator
        Powerboat& operator=(Powerboat &&rhs) noexcept;

        //copy constructor
        Powerboat(const Powerboat& other);

        //copy assignment operator
        Powerboat& operator=(const Powerboat &rhs);

        //getters
        int getNumEngines() const;
        float getTotHorsePower() const;
        std::string getName() const;
        float getLength() const;
        std::string getYearBuilt() const;

        //setters
        void setNumEngines(const int);
        void setTotHorsePower(const float);
        void setName(const std::string);
        void setLength(const float);
        void setYearBuilt(const std::string);

        //member garbageCollector
        void garbageCollector(const Powerboat*);

        //member print
        void print() const;

};

//overloaded stream insertion operator
std::ostream& operator<<(std::ostream&, const Powerboat&);


#endif