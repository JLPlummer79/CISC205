#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include "Yacht.h"
#include "Sailboat.h"
#include "Powerboat.h"
#include "menu.h"

int main() {

    Yacht** marina = new Yacht*[MAX];
    

    menu(marina);
    
    _CrtDumpMemoryLeaks();

    return 0;
}