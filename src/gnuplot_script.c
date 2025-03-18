#include <stdio.h>
#include <stdlib.h>

void generate_gnuplot_script()
{
    FILE *gp = fopen("output/algorithm_plot.gnuplot", "w");
    if (gp == NULL)
    {
        printf("An error has ocurred while opening file.\n");
        exit(1);
    }

    fprintf(gp, "set terminal pngcairo enhanced font \"Arial,12\" size 800,600\n");
    fprintf(gp, "set output \"output/algorithm_plot.png\"\n");
    fprintf(gp, "set title \"Execution Time\"\n");
    fprintf(gp, "set xlabel \"Array Size (N)\"\n");
    fprintf(gp,"set ylabel \"Execution Time (seconds)\"\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set logscale y 10\n");

    fprintf(gp, "plot \"output/sorting_times.dat\" using 1:2 with linespoints title \"Best Case\" lc rgb \"blue\", \\\n");
    fprintf(gp, " \"output/sorting_times.dat\" using 1:3 with linespoints title \"Average Case\" lc rgb \"green\", \\\n");
    fprintf(gp, " \"output/sorting_times.dat\" using 1:4 with linespoints title \"Worst Case\" lc rgb \"red\", \n");

    fclose(gp);
}
