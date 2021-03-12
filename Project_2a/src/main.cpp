/*
 *
 * Jesse Plummer
 *
 * Chapter 9, Programming Challenge 2: Array manipulation
 *
 * March 15th, 2021
 * 
*/

#include <iostream>
#include <iomanip>

// global constants for size of array
constexpr int SIZE = 4;

//function declarations
const float* dblValues(const float* , const int);
const float* dblSizeArray(const float*, const int);
const float* sortedArray(const float*, const int);
void copyArray(const float*, float*, const int);
void garbageCollector(const float *);
void insertionSort(float*, const int);
void display(const float* set, const int size);
void divider();


int main() {
 //create initial array and pointers to point to the modified arrays

    const float array[SIZE] {9.45, 8.6, 7.3, 6.0};
    const float* ptr0;
    const float* ptr1;
    const float* ptr2;

    //getting and displaying the different array manipulations

    std::cout << "Original array values\n";
    display(array,SIZE);
    ptr0 = dblValues(array, SIZE);
    std::cout << "Doubled array values\n";
    display(ptr0,SIZE);
    ptr1 = dblSizeArray(ptr0, SIZE);
    std::cout << "Copied array 8 elements long filled with PI\n";
    display(ptr1, SIZE*2);
    ptr2 = sortedArray(ptr1, SIZE*2);
    std::cout << "Array sorted least to greatest\n";
    display(ptr2, SIZE*2);

    //deallocate the memory on the heap

    garbageCollector(ptr0);
    garbageCollector(ptr1);
    garbageCollector(ptr2);

    return 0;
}

//*******************************************************
// name: display
// called by: main, dblValues, dblSizeArray
// passed: const float*, const int
// returns: nothing
// The display function prints the data in an organized *
// fashion for improved user consumption                *
//*******************************************************
void display(const float* set, const int size) {
    //prints a dividing line 
    divider();

    //print contents of array neatly with 4 decimal places.
    for(auto i = 0; i < size; ++i) {
        std::cout << "Element[" << i << "] is " << 
        std::fixed << std::setprecision(4) << 
        set[i] << '\n';
    }

    //prints a dividing line
    divider();
}
//*******************************************************
// name: divider
// called by: display, main
// passed: nothing
// returns: nothing
// The divider function prints out a formatted line  to *
// enhance the display of the data                      *
//*******************************************************
void divider() {
    //print a dividing line of stars
    std::cout << std::setw(42) << std::setfill('*')  << 
    '\n' << std::setfill(' ');
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
   //hold the array with the values doubled
   float* dblSet = new float[size];

   //copy set into dblSet
   copyArray(set, dblSet, size);

    //double the values of dblSet
   for(auto j = 0; j < size; ++j) {
       dblSet[j] = dblSet[j]*2;
   }
    
    //return a pointer to the array holding the doubled values
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
    //to hold the larger array
    float* biggerArray = new float[SIZE*2];

    //copy set into biggerArray
    copyArray(set, biggerArray, size);

    //fill the remainder of biggerArray with 3.145
    for(auto i = SIZE; i < SIZE*2; ++i) {
        biggerArray[i] = 3.145;
    }

    //return a pointer to the larger array
    return biggerArray;
}

//*******************************************************
// name: sortedArray
// called by: main
// passed: const float*, const int
// returns: a const float*
// The sortedArray function copies the argument set to a*
// new array on the heap, then sorts that array and     *
// a pointer to the sorted array                        *
//*******************************************************
const float* sortedArray(const float* set, const int size) {
    //to hold the sorted array
    float* ascendingOrder = new float[size];

    //copy set into acendingOrder
    copyArray(set, ascendingOrder, size);

    //call sort function
    insertionSort(ascendingOrder, SIZE*2);

    //return a pointer to the sorted array
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
void copyArray(const float* original, float* copy, 
                                        const int size) {
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


