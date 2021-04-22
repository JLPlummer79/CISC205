#include <iostream>
#include "Yacht.h"
#include "Sailboat.h"

int main(int, char**) {

    Yacht* ac = new Yacht;
    Yacht* marina[MAX];
    Sailboat* cr = new Sailboat;

    //testing object creation and adding to the marina
    ac->setName("Enterprise");
    ac->setLength(1122);
    ac->setYearBuilt("1958");
    ac->print();

    cr->setSailArea(450.57);
    cr->setName("Cricket");
    cr->setLength(45.75);
    cr->setYearBuilt("1975");
    cr->print();

    marina[0] = ac;
    marina[1] = cr;
    marina[0]->garbageCollector(ac);

    marina[1]->garbageCollector(cr);



    

    
}
