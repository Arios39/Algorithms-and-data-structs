#ifndef InsertionSort_h
#define InsertionSort_h

#include "Swap.h"


void insertion_sort( int number[], int x){
    int n = x;
    int j;
    
    for (int i = 1; i < n; i++){
        j = i;
        while ( j > 0 && number[ j-1] > number[j] ){
            swap(number, j-1, j);
            j = (j-1);
        }
    }
}

// Do not write any code below this line
#endif
