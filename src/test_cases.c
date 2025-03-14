#include "../include/test_cases.h"
#include "../include/time_measurement.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double best_case(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        arr[i] = i + 1;
    }

    // Calculate time taken by insertion_sort()
    return measure_time(arr, length);
}

double average_case(int arr[], int length)
{
    srand(time(NULL));
    for ( int i = 0; i < length; i++)
    {
        arr[i] = rand() % length + 1;
    }

    return measure_time(arr, length);
}

double worst_case(int arr[], int length)
{
    int length_size = length;

    for( int i = 0; i < length; ++i)
    {
        arr[i] = length_size - 1;
        length_size--;
    }

    return measure_time(arr, length);
}
