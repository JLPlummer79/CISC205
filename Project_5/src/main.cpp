#include <iostream>
#include "SeaPollution.h"
#include "menu.h"

int main() {

    SeaPollution seas[MAX];

    //test object
    SeaPollution test;

    std::cout << "Default object test:\n" 
    << "Sea name: "<< test.getName() << '\n'
    << "Surface Area: " << test.getSurfaceArea() << '\n'
    << "Pollution Area: " << test.getPollutionArea() << '\n'
    << "Salinity: " << test.getSalinityLevel() << '\n';

    SeaPollution test1("Atlantic", 22.19, 345.12, 112.29);
    std::cout << "Testing Object Low level error checking:\n";
    //std::cout << "Set Name Test:\n";
    //std::cout << "Set Pollution Test:\n"
    //std::cout << "Set Surface Area Test:\n"
    std::cout << "2nd Ocean :\n"
     << "Sea name: "<< test1.getName() << '\n'
    << "Surface Area: " << test1.getSurfaceArea() << '\n'
    << "Pollution Area: " << test1.getPollutionArea() << '\n'
    << "Salinity: " << test1.getSalinityLevel() << '\n';
    //std::cout << "Changing name...\n";
    //std::cout << "Changing pollution area...\n";
    //std::cout << "Changing surface area...\n";
    //std::cout << "Changing salinity...\n";
    //test1.setName("SpongeBobSquarePantsOceanOfFun");
    //test1.setPollutionArea(21231111111111111111121212121212121212121212.09);
    //test1.setPollutionArea(-12.19);
    //test1.setPollutionArea(0);
    //test1.setSurfaceArea(21231111111111111111121212121212121212121212.09);
    //test1.setSurfaceArea(-12.20);
    //test1.setSurfaceArea(0);
    //test1.setSalinityLevel(21231111111111111111121212121212121212121212.09);
    //test1.setSalinityLevel(-12.19);
    //test1.setSalinityLevel(0);
    SeaPollution test2;
    test2 = test + test1;

     std::cout << "Overloaded addition operator test:\n"
     << "Sea name: "<< test2.getName() << '\n'
    << "Surface Area: " << test2.getSurfaceArea() << '\n'
    << "Pollution Area: " << test2.getPollutionArea() << '\n'
    << "Salinity: " << test2.getSalinityLevel() << '\n';

    std::cout << "Overloaded less-than operator test:\n";
    if(test < test1) {
        std::cout << test.getName() << " is less than " << test1.getName() << '\n';
    }
    else { 
        std::cout << test1.getName() << " is less than " << test.getName() << '\n'; 
    }
/*
    SeaPollution test3;
    test3 = test - test1;
    std::cout << "Overloaded subtraction operator test:\n"
    << "Sea name: "<< test3.getName() << '\n'
    << "Surface Area: " << test3.getSurfaceArea() << '\n'
    << "Pollution Area: " << test3.getPollutionArea() << '\n'
    << "Salinity: " << test3.getSalinityLevel() << '\n';

    std::cout << "Next test should produce an error.\n";
    SeaPollution test4;
    test4 = test1 - test;
    std::cout << "Sea name: "<< test4.getName() << '\n'
    << "Surface Area: " << test4.getSurfaceArea() << '\n'
    << "Pollution Area: " << test4.getPollutionArea() << '\n'
    << "Salinity: " << test4.getSalinityLevel() << '\n';
*/
    menu(seas);
    
    

    





}