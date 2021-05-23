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

        //Exception class EmptyValue, for empty throws
        class EmptyValue {};

        //Exception class NegativeValue, for negative float throws
        class NegativeValue{
            private:
                float value;
            public:
                //constructor
                NegativeValue(float num) {
                    num = value;
                }
                //getter
                float getValue() const {
                    return value;
                }
        }; //end negativeValue Exception class

        //Exception class BigString, for strings over 15 char throws
        class BigString{
            private:
                std::string sName;
            public:
                //constructor
                BigString(std::string n) {
                    sName = n;
                }
            //getter
            std::string getsName() const {
                return sName;
            }
        }; //end BigString Exception class

        //Exception class ImpossibleStr, for catching Impossible values 
        //thrown by stof, stoi
        class ImpossibleStr {
            private:
                std::string iStr;
            
            public:
                //constructor
                ImpossibleStr(std::string i) {
                    iStr = i;
                }
                //getter
                std::string getIStr() const {
                    return iStr;
                }
        };//end Exception class ImpossibleStr

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

        float convertFloat(std::string);
        int convertSingleInt(std::string);

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