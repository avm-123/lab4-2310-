/*************************
*Aidan Militzer
*CPSC 2311 001
*Your amilitz@clemson.edu
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int** readFile(FILE* fp, int *size)
{
//Checks if file is readable
    if(fscanf(fp, "%d", size) != 1)
    {
        fprintf(stderr, "Fail\n");
        exit(EXIT_FAILURE);
    }
    //create a local variable to store pointer
    int num = *size;
    //set index to 0
    int index = 0;
    //Allocate memory to mat[][]
    int** mat = (int**)malloc(num * sizeof(int*));
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int)); 

    int row = 0; 
    int col = 0;
    
    
    //loop through file to store values as a 2d array
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            if(fscanf(fp, "%d", &mat[row][col]) != 1)
            {
                fprintf(stderr, "Fail\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return mat;
}


void printMatrix (int** mat, int num)
{
    int row = 0; 
    int col = 0;
    //Creating the output of a 2d array that has the numbers from the text file 
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
            
        }
        printf("\n");
    }
    //Calls calculateVal function to read the total of values diagonal to the center
    printf("Total = %d\n", calculateVal(mat, num));
    
}

int calculateVal(int** mat, int size)
{
     int sum = 0;

    // Traverse the matrix
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            // Check if the element is not part of any diagonal
            if (!isLeftDiagonal(i, j) && !isRightDiagonal(size, i, j)) 
            {
                // Add the element to the sum
                sum += mat[i][j];
            }
        }
    }

    return sum;
}
bool isRightDiagonal(int size, int row, int col)
{
    //right diagonal
    return row + col == size - 1;
}
bool isLeftDiagonal(int row, int col)
{
    //left diagonal
    return row == col;
}
