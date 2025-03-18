#include "../include/print_array.h"
#include <stdio.h>

void print_array(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}