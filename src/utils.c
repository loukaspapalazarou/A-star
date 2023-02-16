#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float time;
    int points_explored;
} solution;

void read_file(const char *filename, int *rows, int *cols, int ***grid, int *start_x, int *start_y, int *end_x, int *end_y)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(file, "%d %d", rows, cols);
    int i, j;
    *grid = (int **)malloc(*rows * sizeof(int *));
    for (i = 0; i < *rows; i++)
    {
        (*grid)[i] = (int *)malloc(*cols * sizeof(int));
        for (j = 0; j < *cols; j++)
        {
            fscanf(file, "%1d", &(*grid)[i][j]);
        }
    }

    fscanf(file, "%d %d %d %d", start_y, start_x, end_y, end_x);

    fclose(file);
}

void print_grid(int rows, int cols, int **grid)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
