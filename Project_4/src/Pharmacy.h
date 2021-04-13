#ifndef PHARMACY_H
#define PHARMACY_H
#include <string>

class Pharmacy {
    private:
    //fixed costs of medications, these will never change
        const float amoxCost = 52.87;
        const float morphCost = 1401.15;
        const float ketamineCost = 252.90;
        const float asprinCost = 25.01;
        const float oxyCost = 75.75;

    //fixed names of medications, these will never change
        const std::string amox = "Amoxacillin";
        const std::string morph = "Morphine";
        const std::string keta = "Ketamine";
        const std::string aspr = "Asprin";
        const std::string oxy = "Oxycontin";


    public:
    //default constructor
        Pharmacy() = default;
    
    //default destructor inline
        ~Pharmacy() = default;
        
    //getter for the prices
        const float getAmoxCost() const;
        const float getMorphCost() const;
        const float getKetamineCost() const;
        const float getAsprinCost() const;       
        const float getOxyCost() const; 
    
    //getters for the names of the medications
        const std::string getAmox() const;
        const std::string getMorph() const;
        const std::string getKeta() const;
        const std::string getAspr() const;
        const std::string getOxy() const; 

};




#endif