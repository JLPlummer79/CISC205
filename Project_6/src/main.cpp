#include <iostream>
#include "Yacht.h"

int main(int, char**) {

    Yacht* ac = new Yacht;
    Yacht* marina[MAX];

    ac->setName("Enterprise");
    ac->setLength(1122);
    ac->setYearBuilt("1958");

    ac->print();

    marina[0] = ac;
    marina[0]->garbageCollector(ac);

    

    
}
