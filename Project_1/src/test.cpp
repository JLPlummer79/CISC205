#include "modify.h"
#include <cassert>
#include <iostream>


void test0(const float* set, const int size) {
    // is set the right size?
    assert(size == SIZE);
    std::cout << "Size is correct\n";
  
    //eliminate the decimal points of the float to compare digits
    assert((int)(set[0] * 100) == 945);
    assert((int)(set[1]* 10) == 86);
    assert((int)(set[2]* 10) == 73);
    assert((int)(set[3]*10 == 60));
    std::cout << "Set elements are correct\n";

    std::cout << "Test 0 passed.\n";      
}
//test the display function 
void testDisplay(const float* set, const int size) {
    test0(set, size);
    

}

void test1(const float* set, const int size) {
    //is size correct?
    assert(size == SIZE);
    std::cout << "Size is correct\n";

    assert((int)(set[0] * 100) == 1890 );
    assert((int)(set[1]* 10) == 172);
    assert((int)(set[2]* 10) == 146);
    assert((int)(set[3]*10 == 120));
    std::cout << "Set elements are correct\n";

    std::cout << "Test 1 passed.\n";

}

void test2(const float* set, const int size) {
    assert(size == BSIZE);
    std::cout << "Size is correct\n";

    assert((int)(set[0] * 100) == 1890);
    assert((int)(set[1]* 10) == 172);
    assert((int)(set[2]* 10) == 146);
    assert((int)(set[3]* 10) == 120);  
    assert((int)(set[4]*1000) == 3145);
    assert((int)(set[5]*1000) == 3145);
    assert((int)(set[6]*1000) == 3145);
    assert((int)(set[7]*1000) == 3145);
    
    std::cout << "Set elements are correct\n";

    std::cout << "Test 2 passed.\n";

}

void test3(const float* set, const int size) {
     assert(size == BSIZE);
    std::cout << "Size is correct\n";

    assert((int)(set[7] * 100) == 1890);
    assert((int)(set[6]* 10) == 172);
    assert((int)(set[5]* 10) == 146);
    assert((int)(set[4]* 10) == 120);  
    assert((int)(set[3]*1000) == 3145);
    assert((int)(set[2]*1000) == 3145);
    assert((int)(set[1]*1000) == 3145);
    assert((int)(set[0]*1000) == 3145);
    
    std::cout << "Set elements are correct\n";

    std::cout << "Test 3 passed.\n";
}
