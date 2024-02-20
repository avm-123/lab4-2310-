/*************************
*Aidan Militzer
*CPSC 2311 001
*Your amilitz@clemson.edu
*************************/
#include <stdio.h> 
#include <stdlib.h>
#include "functions.h"
int main(int argc, char* argv[])
{
    //Checks command line for text file
    if (argc < 2)
    { 
        printf("not enough argument: ./exe filename\n"); 
        exit(-1);
    }
    //points to text file and reads data
    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did not open\n"); 
        exit(-1);
    }
    int size = 0;
    //store data from file in function that reads data and creates a 2d array
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);

    return 0;
}
