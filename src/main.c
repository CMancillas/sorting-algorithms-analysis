#include <stdio.h>
#include <stdlib.h>
#include "../include/test_cases.h"
#include "../include/time_measurement.h"
#include "../include/gnuplot_script.h"

int main()
{
    FILE *file = fopen("output/sorting_times.dat", "w");
    if (file == NULL)
    {
        printf("An error has ocurred when opening file.\n");
        return 1;
    } 

    printf("+----------+-----------+-------------+------------+\n");
    printf("|    N     | Best Case | Average Case| Worst Case |\n");
    printf("+----------+-----------+-------------+------------+\n");
    
    fprintf(file, "# N Best_Case Average_Case Worst_Case\n");

    int n_values[] = {10, 50, 100, 200, 500, 1000, 2000, 5000, 7000, 10000};
    int n = sizeof(n_values) / sizeof(n_values[0]);

       

    for (int i = 0; i < n; i++)
    {
        int length = n_values[i]; 
        int *arr = (int *)malloc(sizeof(int) * n_values[i]);
        if( arr == NULL)
        {
            printf("Allocation failed.\n");
            exit(0);
        }

        // Best case
        printf("|%9d ", n_values[i]);
        
        double best = best_case(arr, length);
        printf("|%11f", best);
        
        // Average
        double avg = average_case(arr, length);
        printf("|%13f", avg);

        // Worst case
        double worst = worst_case(arr, length);
        printf("|%12f|", worst);

        // Writing in a compatible Gnuplot format
        fprintf(file, "%d %f %f %f\n", n_values[i], best, avg, worst);
        printf("\n");
        free(arr);
    }
    
    printf("+----------+-----------+-------------+------------+\n");
    fclose(file);
    
    generate_gnuplot_script();
    
    // Running Gnuplot from C
    system("gnuplot output/insertion_plot.gnuplot");

    return 0;
}