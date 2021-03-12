/*
 *
 * Jesse Plummer
 *
 * Chapter 9, Programming Challenge 2: Array manipulation
 *
 * March 15th, 2021
 * 
*/
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
#include "display.h"
#include "modify.h"
#include "test.h"
#include <iostream>

int main() {
    //create initial array to be modified
    const float array[SIZE] {9.45, 8.6, 7.3, 6.0};
    const float testArray[SIZE] {2.5,7.8,0.2,1.5};
    //each will hold the results from each function
    const float* ptr0;
    const float* ptr1;
    const float* ptr2;

    std::cout << "Original array values\n";
    display(array,SIZE);


    //call function to double the values in array
    ptr0 = dblValues(array, SIZE);

    //display the new values
    std::cout << "Doubled array values\n";
    display(ptr0,SIZE);
    

    //call function to double the size of array
    ptr1 = dblSizeArray(ptr0, SIZE);

    //display the new array
    std::cout << "Copied array 8 elements long filled with PI\n";
    display(ptr1, BSIZE);

    //call function to sort the array 'stored' at ptr1
    ptr2 = sortedArray(ptr1, BSIZE);
    
    //display new array
    std::cout << "Array sorted least to greatest\n";
    display(ptr2, BSIZE);

    //deallocate the memory on the heap
    garbageCollector(ptr0);
    garbageCollector(ptr1);
    garbageCollector(ptr2);

    //Part of the VS Code process for checking for memory leaks
    //will output a memory leak repot to the Output window

    //_CrtDumpMemoryLeaks();
    //_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_DEBUG );

    return 0;
}