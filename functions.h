/*************************
*Aidan Militzer
*CPSC 2311 001
*Your amilitz@clemson.edu
*************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdbool.h>
int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);
int calculateVal(int** mat, int size); 
bool isRightDiagonal(int size, int row, int col); 
bool isLeftDiagonal(int row, int col);
#endif
