#include "../include/selection_sort.h"
#include "../include/print_array.h"
#include <stdio.h>
void selection_sort(int arr[], int length)
{
    for ( int i = 0; i < length - 1; i++)
    {
        int lowest_index = i;
        int lowest = arr[i];

        for ( int j = i + 1; j < length; j++)
        {
            if ( arr[j] < lowest)
            {
                lowest_index = j;
                lowest = arr[j];
            }
        }
        arr[lowest_index] = arr[i];
        arr[i] = lowest;
    }

}

