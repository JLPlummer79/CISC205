/*
 *
 * Jesse Plummer
 *
 * Chapter 9, Programming Challenge 2: Array manipulation
 *
 * March 15th, 2021
 * 
*/
#ifndef MODIFY_H
#define MODIFY_H

// global constants for array size SIZE for initial array
// BSIZE for the doubled (in size) array
constexpr int SIZE = 4;
constexpr int BSIZE = 2*SIZE;

//function declarations for modify.cpp
const float* dblValues(const float* , const int);

const float* dblSizeArray(const float*, const int);

const float* sortedArray(const float*, const int);

void copyArray(const float*, float*, const int);

void garbageCollector(const float *);

void initilizeArray(float* shell, const int size);

#endif