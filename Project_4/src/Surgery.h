#ifndef SURGERY_H
#define SURGERY_H
#include <string>

class Surgery {
    //5 different surgeries and their costs.  
    //Costs and Names remain the same, thus const
    private:
    //fixed costs of surgeries, these will never change
        const float othroCost = 1500.75;
        const float eyeCost = 3500.00;
        const float cardioCost = 9000.00;
        const float brainCost = 2500.00;
        const float tommyJohnCost = 2750.00;

    //fixed names of surgeries, these will never change
        const std::string othro = "Othroscopic";
        const std::string eye = "Eye";
        const std::string cardio = "Heart";
        const std::string brain = "Brain";
        const std::string tommyJohn = "Tommy-John";
    
    public:
    //default constructor
        Surgery() = default;

    //destructor
        ~Surgery() = default;

    // getters for costs.  No setters necessary
        const float getOthroCost() const;

        const float getEyeCost() const;
        
        const float getCardioCost() const;

        const float getBrainCost() const;

        const float getTommyJohnCost() const;

    // getters for names.  No setters necessary
        const std::string getOthro() const;
        
        const std::string getEye() const;

        const std::string getCardio() const;

        const std::string getBrain() const;

        const std::string getTommyJohn() const;
   
};






#endif