/*
 *
 * Jesse Plummer
 *
 * Chapter 9, Programming Challenge 2: Array manipulation
 *
 * March 15th, 2021
 * 
*/

#include "sort.h"
#include "modify.h"
#include <iostream>

void mergeSort(float* originalArray, float* workArray, const int size) {
// may try to implement this
    
}

//*******************************************************
// name: insertionSort
// called by: sortedArray
// passed: float*, const int
// returns: nothing
// The inertionSort function sorts the contents of the  *
// array passed to it in asceding order by insertion    *
// algorithm.                                           *
//*******************************************************
void insertionSort(float* set, const int size) {
    //holds the value being swapped
    float temp;
    //starts by comparing 2nd number to 1st...
    for(int i = 1; i < size; ++i) {
        int j = i;
        while(j > 0 && set[j-1] > set[j]) {
        //swap places of the compared values    
            temp = set[j-1];
            set[j-1] = set[j];
            set[j] = temp;
            --j;
        }
    }
}