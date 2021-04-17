/*
 *
 * Jesse Plummer
 *
 * Chapter 14, Programming Challenge #5 Sea Pollution
 *
 * April 19th, 2021
 * 
*/

#ifndef SEAPOLLUTION_H
#define SEAPOLLUTION_H
#include <string>
#include <iostream>

//max amount of large bodies of water
const int MAX = 5;


class SeaPollution {

    private: 
        std::string name;
        float surfaceArea;
        float pollutionArea;
        float salinityLevel;
        static int id;
    
    public:
        //member function declarations for SeaPollution.cpp

        //default constructor
        SeaPollution();

        //overloaded constructor
        SeaPollution(std::string, float, float, float);

        //default destructor
        ~SeaPollution() = default;

        //move constructor
        SeaPollution(SeaPollution &&other) noexcept;

        //move assignment operator (overloaded)
        SeaPollution& operator=(SeaPollution &&other) noexcept;

        //copy constructor
        SeaPollution(const SeaPollution& other);

        //copy assignment operator
        SeaPollution& operator=(const SeaPollution &other);

        //overloaded additon operator
        SeaPollution operator+(const SeaPollution& rhs);

        //overloaded subtraction operator
        SeaPollution operator-(const SeaPollution& rhs);

        //overloaded greater-than operator
        bool operator>(const SeaPollution& rhs);

        //overloaded less-than operator
        bool operator<(const SeaPollution& rhs);

        //overloaded equivalence operator
        bool operator==(const SeaPollution& rhs);

        //print function
        void print() const;

        //getters
        const std::string getName() const;
        const float getSurfaceArea() const;
        const float getPollutionArea() const;
        const float getSalinityLevel() const;

        //setters
        void setName(const std::string);
        void setSurfaceArea(const float);
        void setPollutionArea(const float);
        void setSalinityLevel(const float);
        
};

        //overloaded << operator
        std::ostream& operator<<(std::ostream&, const SeaPollution&);







#endif