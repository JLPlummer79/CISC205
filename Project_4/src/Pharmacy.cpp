#include "Pharmacy.h"
#include <utility>
#include <iostream>
#include <cstdlib>



//*******************************************************
// name: getAmoxCost
// called by: displayMedsMenu
// passed: nothing
// returns: const float
// The getAmoxCost member function returns the value of *
// the member variable amoxCost                         *
//*******************************************************
    const float Pharmacy::getAmoxCost() const {
        return amoxCost;
    }

//*******************************************************
// name: getMorphCost
// called by: displayMedsMenu
// passed: nothing
// returns: const float
// The getMorphCost member function returns the value of*
// the member variable morphCost                        *
//*******************************************************
    const float Pharmacy::getMorphCost() const {
        return morphCost;
    }

//*******************************************************
// name: getKetamineCost
// called by: displayMedsMenu
// passed: nothing
// returns: const float
// The getKetamineCost member function returns the value*
// of the member variable ketamineCost                  *
//*******************************************************
    const float Pharmacy::getKetamineCost() const {
        return ketamineCost;
    }

//*******************************************************
// name: getAsprinCost
// called by: displayMedsMenu
// passed: nothing
// returns: const float
// The getAsprinCost member function returns the value  *
// of the member variable asprinCost                    *
//*******************************************************
    const float Pharmacy::getAsprinCost() const {
        return asprinCost;
    }

//*******************************************************
// name: getOxyCost
// called by: displayMedsMenu
// passed: nothing
// returns: const float
// The getOxyCost member function returns the value of  *
// the member variable oxyCost                          *
//*******************************************************
    const float Pharmacy::getOxyCost() const {
        return oxyCost;
    }
//*******************************************************
// name: getAmox
// called by: displayMedsMenu
// passed: nothing
// returns: const std::string
// The getAmox member function returns the value of the *
// member variable amox                                 *
//*******************************************************
    const std::string Pharmacy::getAmox() const {
       return amox;
    }

//*******************************************************
// name: getMorph
// called by: displayMedsMenu
// passed: nothing
// returns: const std::string
// The getMorph member function returns the value of the*
// member variable morph                                *
//*******************************************************
    const std::string Pharmacy::getMorph() const {
        return morph;
    }

//*******************************************************
// name: getKeta
// called by: displayMedsMenu
// passed: nothing
// returns: const std::string
// The getKeta member function returns the value of the *
// member variable keta                                 *
//*******************************************************
    const std::string Pharmacy::getKeta() const {
        return keta;
    }

//*******************************************************
// name: getAspr
// called by: displayMedsMenu
// passed: nothing
// returns: const std::string
// The getAspr member function returns the value of the *
// member variable aspr                                 *
//*******************************************************
    const std::string Pharmacy::getAspr() const {
        return aspr;
    }

//*******************************************************
// name: getOxy
// called by: displayMedsMenu
// passed: nothing
// returns: const std::string
// The getOxy member function returns the value of the  *
// member variable oxy                                  *
//*******************************************************
    const std::string Pharmacy::getOxy() const {
        return oxy;
    }

