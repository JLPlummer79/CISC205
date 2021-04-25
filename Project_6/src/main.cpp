/*
 *
 * Jesse Plummer
 *
 * Chapter 15, Programming Challenge #6 Yacht 
 *
 * May 2nd, 2021
 * 
*/
/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <cstdlib>
#include <crtdbg.h>
*/
#include <iostream>
#include "Yacht.h"
#include "Sailboat.h"
#include "Powerboat.h"
#include "menu.h"

int main() {

    Yacht** marina = new Yacht*[MAX];
    

    menu(marina);
    
    //_CrtDumpMemoryLeaks();

    return 0;
}