#include "../include/generate_growth_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generate_growth_data()
{
    FILE *file = fopen("output/growth_function.dat", "w");
    if (file == NULL)
    {
        printf("An error has ocurred while opening file.\n");
        exit(1);
    }

    fprintf(file, "# n log(n) n n*log(n) n^2 n^3\n");

    for (int n = 1; n <= 1000; n++ )
    {
        double log_n = log(n);
        double n_log_n = n * log(n);
        double n_squared = pow(n, 2);
        double n_cubed = pow(n, 3);

        fprintf(file, "%d %f %d %f %f %f\n", n, log_n, n, n_log_n, n_squared, n_cubed);
    }

    fclose(file);
}