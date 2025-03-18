#include "../include/generate_growth_data_gnuscript.h"
#include <stdio.h>
#include <stdlib.h>

void generate_growth_data_gnuscript()
{
    FILE *gp = fopen("output/growth_plot.gnuplot", "w");
    if (gp == NULL)
    {
        printf("An error has ocurred while opening file.\n");
        exit(1);
    }

    fprintf(gp, "set terminal pngcairo enhanced font \"Arial,12\" size 800,600\n");
    fprintf(gp, "set output \"output/growth_plot.png\"\n");
    fprintf(gp, "set title \"Comparison of Growth Functions\"\n");
    fprintf(gp, "set xlabel \"n\"\n");
    fprintf(gp, "set ylabel \"Function Value\"\n");
    fprintf(gp, "set grid \n");
    fprintf(gp, "set logscale y 10\n");
    fprintf(gp, "set key top left\n");

    fprintf(gp, "plot \"output/growth_function.dat\" using 1:2 with lines title \"log(n)\" lc rgb \"blue\", \\\n");
    fprintf(gp, "     \"output/growth_function.dat\" using 1:3 with lines title \"n\" lc rgb \"red\", \\\n");
    fprintf(gp, "     \"output/growth_function.dat\" using 1:4 with lines title \"n*log(n)\" lc rgb \"green\", \\\n");
    fprintf(gp, "     \"output/growth_function.dat\" using 1:5 with lines title \"n^2\" lc rgb \"purple\", \\\n");
    fprintf(gp, "     \"output/growth_function.dat\" using 1:6 with lines title \"n^3\" lc rgb \"orange\", \\\n");

    fclose(gp);
}