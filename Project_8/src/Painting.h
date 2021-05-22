/**
    Jesse Plummer
    CISC 205
    05/29/2021
    Programming Challenge 8 Re-visiting Ivo's Yacht Painting Service
*/

#ifndef PAINTING_H
#define PAINTING_H
#include <string>
#include <iostream>

class Painting {
    private:
        std::string name;
        std::string boatName;
        float contract;
        float paidToDate;

    public:

        //Exeption classes need to go here...

        //default constructor
        Painting();

        //default destructor
        ~Painting() = default;

        //move constructor
        Painting(Painting &&other) noexcept;

        //move assignment operator
        Painting& operator=(Painting &&other) noexcept;

        //copy constructor
        Painting(const Painting& other);

        //copy assignment operator
        Painting& operator=(const Painting &other);

        //overloaded addition operator
        float operator+(const Painting& rhs);

        //overloaded greater than operator
        bool operator>(const Painting& rhs);

        //print function
        void print() const;

        //getters
        std::string getName() const;
        std::string getBoatName() const;
        float getContract() const;
        float getPaidToDate() const;
        //setters
        void setName(std::string);
        void setBoatName(std::string);
        void setContract(float);
        void setPaidToDate(float);
};

//overloaded stream insertion operator
std::ostream& operator <<(std::ostream&, const Painting&);



#endif