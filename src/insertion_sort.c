#include "../include/insertion_sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertion_sort(int arr[], int length)
{
    int key = 0;
    int j = 0;
    
    for ( int i = 1; i < length; i++)
    {
        key = arr[i];
        j = i - 1;
        while( arr[j] > key && j >= 0 )
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;   
    }    
}

void print_array(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}






