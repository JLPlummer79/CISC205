#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H
#include "Surgery.h"
#include "Pharmacy.h"
#include <string>

//daily cost of hospital stay
constexpr float HOSPITAL_RATE = 350.00;

//forward declaration of Pharmacy and Surgery classes
class Pharmacy;
class Surgery;

class PatientAccount {

    private:
        int daysSpent;
        float surgeryCharges;
        float medCharges;
        std::string surgeryName;
        std::string medicationName;
    
    public:

        //default constructor
        PatientAccount();

        //overloaded constructor
        PatientAccount(int, float, float);

        ~PatientAccount() = default;

         //move constructor
        PatientAccount(PatientAccount&&) noexcept;

        //move assignment operator
        PatientAccount&operator=(PatientAccount&&) noexcept;

        //copy constructor
        PatientAccount(const PatientAccount& other);

        //copy assignment operator
        PatientAccount &operator=(const PatientAccount& other);

        const int getDaysSpent() const ;

        const float getSurgeryCharges() const;

        const float getMedCharges() const;

        const std::string getMedName() const;

        const std::string getSurgeryName() const;

        void setDaysSpent(const int);

        void setSurgeryCharges(const float);

        void setMedCharges(const float);

        void setSurgeryName(const std::string);

        void setMedName(const std::string);

        float calcDaysSpentCharges();

        //Surgery getSurgery();



};




#endif