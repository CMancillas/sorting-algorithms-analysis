#include "../include/selection_sort.h"
#include "../include/insertion_sort.h"
#include <stdio.h>
void selection_sort(int arr[], int length)
{
    print_array(arr,length);
    // [7, 3, 6, 9]
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

    print_array(arr, length);
}

