#include "Surgery.h"
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>

//*******************************************************
// name: getOthroCost
// called by: displaySurgeriesMenu, 
// passed: nothing
// returns: const float
// The getOthroCost member function returns the value of*
// the member variable othroCost                        *
//*******************************************************
const float Surgery::getOthroCost() const {
    return othroCost;
}

//*******************************************************
// name: getEyeCost
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const float
// The getEyeCost member function returns the value of  *
// the member variable eyeCost                          *
//*******************************************************
const float Surgery::getEyeCost() const {
    return eyeCost;
}

//*******************************************************
// name: getCardioCost
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const float
// The getCardioCost member function returns the value  *
// of the member variable cardioCost                    *
//*******************************************************
const float Surgery::getCardioCost() const {
    return cardioCost;
}

//*******************************************************
// name: getBrainCost
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const float
// The getBrainCost member function returns the value of*
// the member variable brainCost                        *
//*******************************************************
const float Surgery::getBrainCost() const {
    return brainCost;
}

//*******************************************************
// name: getTommyJohnCost
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const float
// The getTommyJohnCost member function returns the     *
// value of the member variable tommyJohnCost           *
//*******************************************************
const float Surgery::getTommyJohnCost() const {
    return tommyJohnCost;
}

//*******************************************************
// name: getOthro
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const std::string
// The getOthro member function returns the value of the*
// member variable othro                                *
//*******************************************************
const std::string Surgery::getOthro() const {
    return othro;
}

//*******************************************************
// name: getEye
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const std::string
// The getEye member function returns the value of the  *
// member variable eye                                  *
//*******************************************************        
const std::string Surgery::getEye() const {
    return eye;
}

//*******************************************************
// name: getCardio
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const std::string
// The getCardio member function returns the value of   *
// the member variable cardio                           *
//*******************************************************
const std::string Surgery::getCardio() const {
    return cardio;
}

//*******************************************************
// name: getBrain
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const std::string
// The getBrain member function returns the value of the*
// member variable brain                                *
//*******************************************************
const std::string Surgery::getBrain() const {
    return brain;
}

//*******************************************************
// name: getTommyJohn
// called by: displaySurgeriesMenu
// passed: nothing
// returns: const std::string
// The getTommyJohn member function returns the value of*
// the member variable tommyJohn                        *
//*******************************************************
const std::string Surgery::getTommyJohn() const {
    return tommyJohn;
}
