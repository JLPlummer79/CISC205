#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "PatientAccount.h"

//maximum amount of patients
const int MAX = 5;

class PatientAccount;

class Patient {

    private:
        int patientId;
        std::string name;
        std::string address;
        std::string phone;

    public:
        //member function declarations for Patient.cpp
        
        //default constructor
        Patient();

        //overloaded constructor
        Patient(std::string, std::string, std::string, int);
        
        //default destructor
        ~Patient() = default;

        //Move constructor
        Patient(Patient &&other) noexcept;

        //move assignment operator
        Patient& operator=(Patient &&other) noexcept;

        //copy constructor
        Patient(const Patient& other);

        //copy assignment operator
        Patient &operator=(const Patient &other);

        //getters & setter defined in Patent.cpp
        const int getPatientId() const;

        const std::string getName() const;

        const std::string getAddress() const;
        
        const std::string getPhone() const;

        PatientAccount getPatientAccount() const;

        void setPatientId(const int);

        void setName(const std::string);

        void setAddress(const std::string); 

        void setPhone(const std::string);

};



#endif