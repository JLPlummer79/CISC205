/*
 *
 * Jesse Plummer
 *
 * Chapter 9, Programming Challenge 2: Array manipulation
 *
 * March 15th, 2021
 * 
*/
#include "modify.h"
#include "display.h"
#include "sort.h"
#include <iostream>

//*******************************************************
// name: dblValues
// called by: main
// passed: const float*, const int
// returns: const float* 
// The dblValues function creates a new array on the    *
// heap, initilizes it, copies the array set into the   *
// new array, displays the copy, doubles the values,    *
// lastly returns a pointer to the 1st memory loaction  *
// to the new array                                     *
//*******************************************************
const float* dblValues(const float* set, const int size) {
   float* dblSet = new float[size];
   //copy set into dblSet
   copyArray(set, dblSet, size);

    //double the values of dblSet
   for(auto j = 0; j < size; ++j) {
       dblSet[j] = dblSet[j]*2;
   }
    
    return dblSet;
}

//*******************************************************
// name: dblSizeArray
// called by: main
// passed: const float* , const int
// returns: const float*
// The dblSizeArray function copies the argument set to *
// the newly declared array, then fills the empty       *
// elements with 3.145                                  *
//*******************************************************
const float* dblSizeArray(const float* set, const int size) {
    float* biggerArray = new float[BSIZE];
    //copy set into biggerArray
    copyArray(set, biggerArray, size);
    //fill the remainder of biggerArray with 3.145
    for(auto i = SIZE; i < BSIZE; ++i) {
        biggerArray[i] = 3.145;
    }

    return biggerArray;
}

//*******************************************************
// name: sortedArray
// called by: main
// passed: const float*, const int
// returns: a const float*
// The 'name' function 'description of what function does'   *
//*******************************************************
const float* sortedArray(const float* set, const int size) {
    float* ascendingOrder = new float[size];
    //copy set into acendingOrder
    copyArray(set, ascendingOrder, size);
    //call sort function
    insertionSort(ascendingOrder, BSIZE);
    return ascendingOrder;
}

//*******************************************************
// name: copyArray
// called by: dblValues, dblSizeArray, sortedArray
// passed: const float*, float*, const int
// returns: nothing
// The copyArray function accepts a const pointer to an *
// array, and pointr to an array on the heap, and uses a*
// for loop to copy the contents of one to the other    *
//*******************************************************
void copyArray(const float* original, float* copy, const int size) {
// copy original array to copy
    for(auto i = 0; i < size; ++i) {
        copy[i] = original[i];   
    }
}
//*******************************************************
// name: garbageCollector
// called by: main
// passed: const float*
// returns: nothing
// The garbageCollector function frees up the memory    *
// from the heap that is allocated in the functions,    *
// then assigned to a pointer in main.  This is to      *
// prevent memory leaks, where memory is allocated then *
// 'abandonded' when the pointer to it is no longer     *
// referencing the memory.                              *
//*******************************************************
void garbageCollector(const float* array) {
    //clean up the allocated memory from the functions
    delete[] array;
    array = nullptr;
}


