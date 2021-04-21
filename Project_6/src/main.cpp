#include <iostream>
#include "Yacht.h"

int main(int, char**) {

    Yacht ac, junk;

    ac.setName("Enterprise");
    ac.setLength(1122);
    ac.setYearBuilt("1958");

    ac.print();

    //test name low level
    //junk.setName("XiJinPingZhoughTTTTTT");

    //junk.setLength(-240);   

    //junk.setYearBuilt("19241");
}
