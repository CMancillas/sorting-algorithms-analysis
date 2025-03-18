#include "../include/time_measurement.h"
#include "../include/insertion_sort.h"  
#include "../include/selection_sort.h"
#include "../include/merge_sort.h"
#include <time.h>

double measure_time(int arr[], int length, int option)
{
    clock_t t;
    t = clock();    
    
    
    switch (option)
    {
        case 1:
            insertion_sort(arr, length);
        break;
        
        case 2:
            selection_sort(arr, length);
        break;
        
        case 3:
            merge_sort(arr, 0, length - 1);
        break;
        
        default:
        break;
    }
    t = clock() - t;
    return ((double)t) / CLOCKS_PER_SEC; // in seconds
}