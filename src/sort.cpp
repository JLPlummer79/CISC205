#include "sort.h"
#include "modify.h"
#include <iostream>

void mergeSort(float* originalArray, float* workArray, const int size) {
// may try to implement this
    
}

void insertionSort(float* set, const int size) {
    std::cout << "Begin insertion...\n";
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