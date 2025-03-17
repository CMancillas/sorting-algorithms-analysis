#include "../include/time_measurement.h"
#include "../include/insertion_sort.h"  
#include "../include/selection_sort.h"
#include <time.h>


double measure_time(int arr[], int length)
{
    clock_t t;
    t = clock();    
    selection_sort(arr, length);
    //insertion_sort(arr, length);
    t = clock() - t;
    return ((double)t) / CLOCKS_PER_SEC; // in seconds
}