/*
 *
 * Jesse Plummer
 *
 * Chapter 16, Programming Challenge #7 Sea Pollution w/ try/catch
 *
 * May 17th, 2021
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
        //Exception class BigName when name exceeds 20 char
        class BigName {
            private:
                std::string bName;
            public:
                //constructor
                BigName(std::string n) {
                    bName = n;
                }
                //sole function
                std::string getbName() const {
                    return bName;
                }
        };//end BigString class

        //Exception class EmptyValue, when any value is empty
        //no need for member anything, will just print a 
        //message when instance is thrown
        class EmptyValue {};

        //Exception class NegativeValue, when any value is negative
        class NegativeValue {
            private:
                float value;
            public:
                //constructor
                NegativeValue(float num) {
                    value = num;
                }
                //sole member function
                float getValue() const {
                    return value;
                }
        }; //end NegativeValue class

        //Exception class ImpossibleValue, when pollutionArea 
        //is greater than surfaceArea *is not possible
        class ImpossibleValue {
            private:
                float iValue;
            
            public:
                //constructor
                ImpossibleValue(float num) {
                    iValue = num;
                }
                //sole member function
                float getIValue() const {
                    return iValue;
                }
        };  //end ImpossibleVAlue class

        //Exception class SmallStr
        class SmallStr {
            private:
               std::string s;

            public:
                //constructor
                SmallStr(std::string sm){
                    s = sm;
                }
                //sole member function
                std::string getSValue(){
                    return s;
                }

        };
        //Exception class ImpossibleStr, mainly will be used in single digit throws
        class ImpossibleStr {
            private:
                std::string a;

            public:
                //constructor
                ImpossibleStr(std::string val) {
                    a = val;
                }
                //sole member function
                std::string getIStr() {
                    return a;
                }
        };

        //member function declarations for SeaPollution.cpp

        //default constructor
        SeaPollution();

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

        //takes string arg, returns a float, may throw!
        float convertFloat(std::string);

        //takes string arg, returns a float, may throw!
        char convertChar(std::string);

        //takes string arg, returns an int, may throw!
        int convertInt(std::string);

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